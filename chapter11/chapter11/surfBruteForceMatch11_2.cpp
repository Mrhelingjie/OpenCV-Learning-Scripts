//#include<opencv2/core/core.hpp>
//#include<opencv2/features2d/features2d.hpp>
//#include<highgui/highgui.hpp>
//#include<opencv2/nonfree/nonfree.hpp>
//#include<opencv2/legacy/legacy.hpp>
//
//#include<iostream>
//using namespace cv;
//using namespace std;
//
//int main() {
//	Mat srcImage1 = imread("./11-2/1.jpg", 1);
//	Mat srcImage2 = imread("./11-2/2.jpg", 1);
//
//	if (!srcImage1.data||!srcImage2.data)
//	{
//		printf("load error");
//		return 0;
//	}
//
//	int minHessian = 700;
//	SurfFeatureDetector detector(minHessian);
//	vector<KeyPoint> keypoint1, keypoint2;
//	//调用detect函数检测surf的特征关键点，保存在vector中
//	detector.detect(srcImage1, keypoint1);
//	detector.detect(srcImage2, keypoint2);
//
//	//计算描述符
//	SurfDescriptorExtractor extractor;
//	Mat descriptors1, descriptors2;
//	extractor.compute(srcImage1, keypoint1, descriptors1);
//	extractor.compute(srcImage2, keypoint2, descriptors2);
//	
//	//bruteforce进行匹配
//	BruteForceMatcher<L2<float>> matcher;
//	vector<DMatch> matches;
//	matcher.match(descriptors1, descriptors2, matches);
//
//	Mat imgmatches;
//	drawMatches(srcImage1, keypoint1, srcImage2, keypoint2, matches,imgmatches);
//	imshow("匹配图", imgmatches);
//	waitKey(0);
//	return 0;
//}