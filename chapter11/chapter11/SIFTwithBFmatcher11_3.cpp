//#include<opencv2/opencv.hpp>
//#include<opencv2/features2d/features2d.hpp>
//#include<highgui/highgui.hpp>
//#include<opencv2/nonfree/features2d.hpp>
//
//#include<iostream>
//using namespace std;
//using namespace cv;
//
//int main() {
//	Mat trainImage = imread("./11-3/1.jpg"), trainImage_gray;
//
//	imshow("原始图", trainImage);
//	cvtColor(trainImage, trainImage_gray, COLOR_BGR2GRAY);
//	//提取关键点
//	vector<KeyPoint> train_KeyPoint;
//	
//	SiftFeatureDetector featureDetector;
//	featureDetector.detect(trainImage_gray, train_KeyPoint);
//	//计算描述符
//	Mat trainDescriptor;
//	SiftDescriptorExtractor extractor;
//	extractor.compute(trainImage_gray, train_KeyPoint, trainDescriptor);
//
//	BFMatcher matcher;
//	vector<Mat> train_desc_collection(1, trainDescriptor);
//	matcher.add(train_desc_collection);
//	matcher.train();
//
//	VideoCapture cap(0);
//	unsigned int frameCount = 0;
//	while (char(waitKey(1))!='q')
//	{
//		int64 time0 = getTickCount();
//		Mat testImage, testImage_gray;
//		cap >> testImage;
//		if (testImage.empty())
//		{
//			continue;
//		}
//		cvtColor(testImage, testImage_gray, COLOR_BGR2GRAY);
//
//
//		//提取关键点
//		vector<KeyPoint> test_KeyPoint;
//		featureDetector.detect(testImage_gray, test_KeyPoint);
//		//计算描述符
//		Mat testDescriptor;
//		extractor.compute(testImage_gray, test_KeyPoint, testDescriptor);
//
//		vector<vector<DMatch>> matches;
//		matcher.knnMatch(testDescriptor, matches, 2);
//
//		vector<DMatch> goodmatch;
//		for (unsigned int i = 0; i < matches.size(); i++)
//		{
//			if (matches[i][0].distance<0.6*matches[i][1].distance)
//			{
//				goodmatch.push_back(matches[i][0]);
//			}
//		}
//
//		Mat dstImage;
//		drawMatches(testImage, test_KeyPoint, trainImage, train_KeyPoint, goodmatch, dstImage);
//		imshow("匹配窗口", dstImage);
//		cout << "当前帧率为：" << getTickFrequency() / (getTickCount() - time0) << endl;
//	}
//	return 0;
//}