////#include<opencv2/opencv.hpp>
////#include<iostream>
////using namespace std;
////using namespace cv;
////
////void useRecToShow() {
////	Mat image(600, 600, CV_8UC3);
////	RNG& rng = theRNG();
////	while (true)
////	{
////		int count = rng.uniform(3, 103);
////		vector<Point> points;
////
////		for (int i = 0; i < count; i++)
////		{
////			Point point;
////			point.x = rng.uniform(image.cols / 4, image.cols * 3 / 4);
////			point.y = rng.uniform(image.rows / 4, image.rows * 3 / 4);
////			points.push_back(point);
////		}
////
////		RotatedRect box = minAreaRect(Mat(points));
////		Point2f vertex[4];
////		box.points(vertex);
////
////		image = Scalar::all(0);
////		for (int i = 0; i < count; i++)
////		{
////			circle(
////				image,
////				points[i], 3,
////				Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),
////				CV_FILLED,
////				CV_AA
////			);
////		}
////
////		for (int i = 0; i < 4; i++)
////		{
////			line(
////				image,
////				vertex[i],
////				vertex[(i + 1) % 4],
////				Scalar(100, 200, 211),
////				2, CV_AA
////			);
////		}
////		imshow("矩阵包围", image);
////		char key = (char)waitKey();
////		if (key == 27 || key == 'q') {
////			break;
////		}
////
////	}
////	return ;
////}
////
////void useCircleToShow() {
////	Mat image(600, 600, CV_8UC3);
////	RNG& rng = theRNG();
////	while (true)
////	{
////		int count = rng.uniform(3, 103);
////		vector<Point> points;
////
////		for (int i = 0; i < count; i++)
////		{
////			Point point;
////			point.x = rng.uniform(image.cols / 4, image.cols * 3 / 4);
////			point.y = rng.uniform(image.rows / 4, image.rows * 3 / 4);
////			points.push_back(point);
////		}
////
////		Point2f center;
////		float radius = 0;
////		minEnclosingCircle(Mat(points),center,radius);
////		
////
////		image = Scalar::all(0);
////		for (int i = 0; i < count; i++)
////		{
////			circle(
////				image,
////				points[i], 3,
////				Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),
////				CV_FILLED,
////				CV_AA
////			);
////		}
////
////		circle(
////			image, 
////			center, 
////			cvRound(radius), 
////			Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),
////			2, 
////			CV_AA
////		);
////		imshow("圆形包围", image);
////		char key = (char)waitKey();
////		if (key == 27 || key == 'q') {
////			break;
////		}
////
////	}
////	return;
////}
////int main() {
////	useRecToShow();
////	useCircleToShow();
////	return 0;
////}
//
//
//
//
//
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//
//using namespace cv;
//using namespace std;
//
//#define WINDOW_NAME1 "【原始图窗口】"        //为窗口标题定义的宏 
//#define WINDOW_NAME2 "【效果图窗口】"        //为窗口标题定义的宏 
//
////  全局变量的声明
//Mat g_srcImage;
//Mat g_grayImage;
//int g_nThresh = 50;//阈值
//int g_nMaxThresh = 255;//阈值最大值
//RNG g_rng(12345);//随机数生成器
//
//void on_ContoursChange(int, void*);
//
//int main()
//{
//	
//	//【1】载入3通道的原图像
//	g_srcImage = imread("1.jpg", 1);
//	if (!g_srcImage.data) 
//	{ 
//		printf("load error"); 
//		return 0; 
//	}
//
//	//【2】得到原图的灰度图像并进行平滑
//	cvtColor(g_srcImage, g_grayImage, CV_BGR2GRAY);
//	blur(g_grayImage, g_grayImage, Size(3, 3));
//
//	//【3】创建原始图窗口并显示
//	namedWindow(WINDOW_NAME1, CV_WINDOW_AUTOSIZE);
//	imshow(WINDOW_NAME1, g_srcImage);
//
//	//【4】设置滚动条并调用一次回调函数
//	createTrackbar(" 阈值:", WINDOW_NAME1, &g_nThresh, g_nMaxThresh, on_ContoursChange);
//	on_ContoursChange(0, 0);
//
//	waitKey(0);
//
//	return(0);
//}
//
//void on_ContoursChange(int, void*)
//{
//	Mat threshold_output;
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	
//	//边缘检测
//	threshold(g_grayImage, threshold_output, g_nThresh, 255, THRESH_BINARY);
//
//	//找轮廓
//	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	//多边形逼近轮廓 + 矩阵和圆形
//	vector<vector<Point>> contours_poly(contours.size());
//	vector<Rect> boundRect(contours.size());
//	//每个轮廓的原点与半径
//	vector<Point2f> center(contours.size());
//	vector<float> radius(contours.size());
//	//对每个轮廓循环 得到绘图数据
//	for (unsigned int i = 0; i < contours.size(); i++)
//	{
//		//逼近的多边形曲线
//		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
//		//曲线最外的矩阵
//		boundRect[i] = boundingRect(Mat(contours_poly[i]));
//		//最小包围圆
//		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
//	}
//	//创建绘图 类型通道保持一致
//	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
//
//	for (unsigned int i = 0; i < contours.size(); i++)
//	{
//		Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
//		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
//		rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
//		circle(drawing, center[i], cvRound(radius[i]), color, 2, 8, 0);
//	}
//	namedWindow(WINDOW_NAME2, WINDOW_AUTOSIZE);
//	imshow(WINDOW_NAME2, drawing);
//}
//
//
