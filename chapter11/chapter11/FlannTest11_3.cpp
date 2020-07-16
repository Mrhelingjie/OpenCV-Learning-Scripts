//#include<opencv2/core/core.hpp>
//#include<opencv2/features2d/features2d.hpp>
//#include<highgui/highgui.hpp>
//#include<opencv2/nonfree/nonfree.hpp>
//#include<opencv2/legacy/legacy.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
//int main() {
//	Mat img_1 = imread("./11-3/1.jpg", 1);
//	Mat img_2 = imread("./11-3/2.jpg", 1);
//	if (!img_1.data||!img_2.data)
//	{
//		printf("Load error");
//		return 0;
//	}
//
//	int minHessian=300;
//	SurfFeatureDetector detector(minHessian);
//	vector<KeyPoint> keypoints_1, keypoints_2;
//
//	detector.detect(img_1, keypoints_1);
//	detector.detect(img_2, keypoints_2);
//
//	SurfDescriptorExtractor extractor;
//	Mat descriptor_1, descriptor_2;
//	extractor.compute(img_1, keypoints_1, descriptor_1);
//	extractor.compute(img_2, keypoints_2, descriptor_2);
//
//	FlannBasedMatcher matcher;
//	vector<DMatch> matches;
//	matcher.match(descriptor_1, descriptor_2, matches);
//
//	double max_dist = 0; double min_dist = 100;
//	for (int i = 0; i < descriptor_1.rows; i++)
//	{
//		double dist = matches[i].distance;
//		if (dist<min_dist)
//		{
//			min_dist = dist;
//		}
//		if (dist>max_dist)
//		{
//			max_dist = dist;
//		}
//	}
//	printf("> 最大距离（Max dist） : %f \n", max_dist);
//	printf("> 最小距离（Min dist） : %f \n", min_dist);
//
//	//进行筛选
//	vector<DMatch> good_match;
//	for (size_t i = 0; i < matches.size(); i++)
//	{
//		if (matches[i].distance<2*min_dist)
//		{
//			good_match.push_back(matches[i]);
//		}
//	}
//	Mat imgDst;
//	drawMatches(img_1, keypoints_1, img_2, keypoints_2, good_match, imgDst, Scalar::all(-1), Scalar::all(-1), vector<char>(),
//		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//	for (size_t i = 0; i < good_match.size(); i++)
//	{
//		printf(">符合条件的匹配点 [%d] 特征点1: %d  -- 特征点2: %d  \n", i, good_match[i].queryIdx, good_match[i].trainIdx);
//
//	}
//	imshow("效果图", imgDst);
//	waitKey(0);
//	return 0;
//
//}