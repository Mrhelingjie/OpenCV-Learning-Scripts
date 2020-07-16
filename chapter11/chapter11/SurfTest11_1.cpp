//#include<opencv2/core/core.hpp>
//#include<opencv2/features2d/features2d.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/nonfree/nonfree.hpp>
//#include<iostream>
//using namespace cv;
//
//
//int main() {
//	Mat srcImage1 = imread("./11-1/1.jpg");
//	Mat srcImage2 = imread("./11-1/2.jpg");
//
//	if (!srcImage1.data||!srcImage2.data)
//	{
//		printf("load error");
//		return 0;
//	}
//
//	imshow("原始图1", srcImage1);
//	imshow("原始图2", srcImage2);
//
//	int minHessian = 400;
//	SurfFeatureDetector detector(minHessian);
//	
//	std::vector<KeyPoint> keypoints1, keypoints2;
//
//	detector.detect(srcImage1, keypoints1);
//	detector.detect(srcImage2, keypoints2);
//	
//	Mat img_keypoints1, img_keypoints2;
//	drawKeypoints(srcImage1, keypoints1, img_keypoints1, Scalar::all(-1), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//	drawKeypoints(srcImage2, keypoints2, img_keypoints2, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//	imshow("特征点1", img_keypoints1);
//	imshow("特征点2", img_keypoints2);
//	waitKey(0);
//	return 0;
//}
