//#include<opencv2/core/core.hpp>
//#include<opencv2/features2d/features2d.hpp>
//#include<highgui/highgui.hpp>
//#include<opencv2/nonfree/nonfree.hpp>
//#include<opencv2/calib3d/calib3d.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
//int main() {
//
//	Mat srcImage1 = imread("./11-4/1.jpg", 1);
//	Mat srcImage2 = imread("./11-4/2.jpg", 1);
//
//	if (!srcImage1.data||!srcImage2.data)
//	{
//		printf("load error");
//		return 0;
//	}
//
//	int minHessian = 400;
//	vector<KeyPoint> keypoints_object, keypoints_scene;
//	SurfFeatureDetector detector(minHessian);
//	detector.detect(srcImage1, keypoints_object);
//	detector.detect(srcImage2, keypoints_scene);
//
//	Mat descriptors_object, descriptors_scene;
//	SurfDescriptorExtractor extractor;
//	extractor.compute(srcImage1, keypoints_object, descriptors_object);
//	extractor.compute(srcImage2, keypoints_scene, descriptors_scene);
//
//	FlannBasedMatcher matcher;
//	vector<DMatch> matches;
//	matcher.match(descriptors_object, descriptors_scene, matches);
//
//	double max_dist = 0; double min_dist = 100;
//	for (int i = 0; i < descriptors_object.rows; i++)
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
//	vector<DMatch> good_matches;
//	for (size_t i = 0; i < matches.size(); i++)
//	{
//		if (matches[i].distance < 3*min_dist)
//		{
//			good_matches.push_back(matches[i]);
//		}
//	}
//
//	Mat img_matches;
//	drawMatches(srcImage1, keypoints_object, srcImage2, keypoints_scene,
//		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//
//
//	vector<Point2f> obj;
//	vector<Point2f> scene;
//
//	for (size_t i = 0; i < good_matches.size(); i++)
//	{
//		obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
//		scene.push_back(keypoints_scene[good_matches[i].trainIdx].pt);
//	}
//
//	Mat H = findHomography(obj, scene, CV_RANSAC);
//
//	vector<Point2f> obj_corners(4);
//	obj_corners[0] = cvPoint(0, 0);
//	obj_corners[1] = cvPoint(srcImage1.cols, 0);
//	obj_corners[2] = cvPoint(srcImage1.cols, srcImage1.rows);
//	obj_corners[3] = cvPoint(0, srcImage1.rows);
//	
//	vector<Point2f> scene_corners(4);
//
//	perspectiveTransform(obj_corners, scene_corners, H);
//	line(
//		img_matches, 
//		scene_corners[0] + Point2f(static_cast<float>(srcImage1.cols), 0),
//		scene_corners[1] + Point2f(static_cast<float>(srcImage1.cols), 0), 
//		Scalar(255, 0, 123), 4);
//	line(
//		img_matches,
//		scene_corners[1] + Point2f(static_cast<float>(srcImage1.cols), 0),
//		scene_corners[2] + Point2f(static_cast<float>(srcImage1.cols), 0),
//		Scalar(255, 0, 123), 4);
//	line(
//		img_matches, 
//		scene_corners[2] + Point2f(static_cast<float>(srcImage1.cols), 0),
//		scene_corners[3] + Point2f(static_cast<float>(srcImage1.cols), 0), 
//		Scalar(255, 0, 123), 4);
//	line(
//		img_matches,
//		scene_corners[3] + Point2f(static_cast<float>(srcImage1.cols), 0),
//		scene_corners[0] + Point2f(static_cast<float>(srcImage1.cols), 0), 
//		Scalar(255, 0, 123), 4);
//
//	imshow("效果图", img_matches);
//
//	waitKey(0);
//	return 0;
//}