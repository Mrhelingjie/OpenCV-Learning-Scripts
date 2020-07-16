//#include<opencv2/opencv.hpp>
//#include<vector>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
////void HoughLinesShow() {
////	Mat srcImage = imread("./7-2/1.jpg");
////	if (!srcImage.data)
////	{
////		printf("load error");
////		return;
////	}
////	Mat tmpImage, dstImage;
////
////	Canny(srcImage,tmpImage,50, 200, 3);
////	cvtColor(tmpImage, dstImage, COLOR_GRAY2BGR);
////
////	vector<Vec2f> lines;
////	HoughLines(tmpImage, lines, 1, CV_PI / 180, 150, 0, 0);
////
////	for (size_t i = 0; i < lines.size(); i++)
////	{
////		float rho = lines[i][0], theta = lines[i][1];
////		Point pt1, pt2;
////		double a = cos(theta), b = sin(theta);
////		double x0 = a * rho, y0 = b * rho;
////
////		pt1.x = cvRound(x0 + 1000 * (-b));
////		pt1.y = cvRound(y0 + 1000 * (a));
////		pt2.x = cvRound(x0 - 1000 * (-b));
////		pt2.y = cvRound(y0 - 1000 * (a));
////
////		line(dstImage, pt1, pt2, Scalar(55, 100, 195), 1, CV_AA);
////	}
////	imshow("yuanshitu", srcImage);
////
////	imshow("canny", tmpImage);
////
////	imshow("result", dstImage);
////	waitKey(0);
////
////}
////void HoughLinesPShow() {
////	Mat srcImage = imread("./7-2/1.jpg");
////	if (!srcImage.data)
////	{
////		printf("load error");
////		return;
////	}
////	Mat tmpImage, dstImage;
////
////	Canny(srcImage, tmpImage, 50, 200, 3);
////	cvtColor(tmpImage, dstImage, COLOR_GRAY2BGR);
////
////	vector<Vec4i> lines;
////	HoughLinesP(tmpImage, lines, 1, CV_PI / 180, 80, 50, 10);
////
////	for (size_t i = 0; i < lines.size(); i++)
////	{
////		Vec4i l = lines[i];
////
////		line(dstImage,Point(l[0],l[1]), Point(l[2],l[3]), Scalar(186, 88, 255), 1, CV_AA);
////	}
////	imshow("yuanshitu", srcImage);
////
////	imshow("canny", tmpImage);
////
////	imshow("result", dstImage);
////	waitKey(0);
////}
////void HoughCirclesShow() {
////	Mat srcImage = imread("./7-2/2.jpg");
////	if (!srcImage.data)
////	{
////		printf("load error");
////		return;
////	}
////	Mat tmpImage, dstImage;
////	imshow("yuanshitu", srcImage);
////
////	cvtColor(srcImage, tmpImage, COLOR_BGR2GRAY);
////	GaussianBlur(tmpImage, tmpImage, Size(9, 9), 2, 2);
////
////
////	vector<Vec3f> circles;
////	HoughCircles(tmpImage, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);
////
////	for (size_t i = 0; i < circles.size(); i++)
////	{
////		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
////		int radius = cvRound(circles[i][2]);
////		
////		circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
////		circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
////	}
////	imshow("result", srcImage);
////	waitKey(0);
////}
////窗口宏
//#define WINDOW_NAME_SRC "原始图"
//#define WINDOW_NAME_HOUGHLINE "霍夫线性"
//#define WINDOW_NAME_HOUGHLINEP "霍夫线性概率"
//#define WINDOW_NAME_HOUGECIRCLE "霍夫圆"
////全局变量
//Mat g_srcImage, g_midImage, g_dstImage;
//vector<Vec4i> g_lines;
//int g_nthreshold = 100;
//
////全局函数
//
//static void on_HoughLines(int, void *);
//
//
//int main() {
//	
//	
//	
//
//	
//	Mat g_srcImage = imread("./7-2/2.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	//载入原始图和Mat变量定义   
//	
//
//	//显示原始图  
//	imshow("【原始图】", g_srcImage);
//
//	//创建滚动条
//	namedWindow("【效果图】", 1);
//	createTrackbar("值", "【效果图】", &g_nthreshold, 200, on_HoughLines);
//
//	//进行边缘检测和转化为灰度图
//	Canny(g_srcImage, g_midImage, 50, 200, 3);//进行一次canny边缘检测
//	cvtColor(g_midImage, g_dstImage, CV_GRAY2BGR);//转化边缘检测后的图为灰度图
//
//	//调用一次回调函数，调用一次HoughLinesP函数
//	on_HoughLines(g_nthreshold, 0);
//	HoughLinesP(g_midImage, g_lines, 1, CV_PI / 180, 80, 50, 10);
//
//	//显示效果图  
//	imshow("【效果图】", g_dstImage);
//
//
//	waitKey(0);
//
//	return 0;
//
//}
//
//
////-----------------------------------【on_HoughLines( )函数】--------------------------------
////		描述：【顶帽运算/黑帽运算】窗口的回调函数
////----------------------------------------------------------------------------------------------
//static void on_HoughLines(int, void*)
//{
//	//定义局部变量储存全局变量
//	Mat dstImage = g_dstImage.clone();
//	Mat midImage = g_midImage.clone();
//
//	//调用HoughLinesP函数
//	vector<Vec4i> mylines;
//	HoughLinesP(midImage, mylines, 1, CV_PI / 180, g_nthreshold + 1, 50, 10);
//
//	//循环遍历绘制每一条线段
//	for (size_t i = 0; i < mylines.size(); i++)
//	{
//		Vec4i l = mylines[i];
//		line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(23, 180, 55), 1, CV_AA);
//	}
//	//显示图像
//	imshow("【效果图】", dstImage);
//}
