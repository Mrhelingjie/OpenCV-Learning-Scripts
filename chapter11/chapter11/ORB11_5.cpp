#include<opencv2/opencv.hpp>
#include<opencv2/features2d/features2d.hpp>
#include<highgui/highgui.hpp>
#include<opencv2/nonfree/features2d.hpp>

#include<iostream>
using namespace std;
using namespace cv;

int main() {
	Mat srcImage = imread("./11-5/1.jpg"), grayImage;
	imshow("原始图", srcImage);
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	
	//提取关键点
	vector<KeyPoint> KeyPoints;
	
	OrbFeatureDetector featureDetector;
	featureDetector.detect(grayImage, KeyPoints);
	//计算描述符
	Mat descriptors;
	OrbDescriptorExtractor extractor;
	extractor.compute(grayImage, KeyPoints, descriptors);

	flann::Index flannIndex(descriptors, flann::LshIndexParams(12, 20, 2), cvflann::FLANN_DIST_HAMMING);

	VideoCapture cap(0);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 360);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 900);
	unsigned int frameCount = 0;

	while (true)
	{
		double time0 = static_cast<double>(getTickCount());
		Mat captureImage, captureImage_gray;
		cap >> captureImage;
		if (captureImage.empty())
		{
			continue;
		}
		cvtColor(captureImage, captureImage_gray, COLOR_BGR2GRAY);


		//提取关键点
		vector<KeyPoint> captureKeyPoint;
		featureDetector.detect(captureImage_gray, captureKeyPoint);
		//计算描述符
		Mat captureDescriptor;
		extractor.compute(captureImage_gray, captureKeyPoint, captureDescriptor);

		Mat matchIndex(captureDescriptor.rows, 2, CV_32SC1),
			matchDistance(captureDescriptor.rows, 2, CV_32FC1);
		flannIndex.knnSearch(captureDescriptor, matchIndex, matchDistance, 2, flann::SearchParams());


		vector<DMatch> goodMatches;
		for(int i = 0; i < matchDistance.rows; i++) 
		{
			if(matchDistance.at<float>(i, 0) < 0.6 * matchDistance.at<float>(i, 1)) 
			{
				DMatch dmatches(i, matchIndex.at<int>(i, 0), matchDistance.at<float>(i, 0));
				goodMatches.push_back(dmatches);
			}
		}

		//【12】绘制并显示匹配窗口
		Mat resultImage;
		drawMatches( captureImage, captureKeyPoint, srcImage, KeyPoints, goodMatches, resultImage);
		imshow("匹配窗口", resultImage);

		//【13】显示帧率
		cout << ">帧率= " << getTickFrequency() / (getTickCount() - time0) << endl;

		//按下ESC键，则程序退出
		if(char(waitKey(1)) == 27) break;
	}
	return 0;
}