//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//using namespace cv;
//using namespace std;
//
//
//#define WINDOW_NAME1 "【原始图窗口】"			//为窗口标题定义的宏 
//#define WINDOW_NAME2 "【轮廓图】"					//为窗口标题定义的宏 
//
//
//Mat g_srcImage;
//Mat g_grayImage;
//int g_nThresh = 80;
//int g_nThresh_max = 255;
//RNG g_rng(12345);
//Mat g_cannyMat_output;
//vector<vector<Point>> g_vContours;
//vector<Vec4i> g_vHierarchy;
//
//
//
//void on_ThreshChange(int, void*);
//
//int main(int argc, char** argv)
//{
//	
//	
//	// 加载源图像
//	g_srcImage = imread("1.jpg", 1);
//	if (!g_srcImage.data) { printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"); return false; }
//
//	// 转成灰度并模糊化降噪
//	cvtColor(g_srcImage, g_grayImage, CV_BGR2GRAY);
//	blur(g_grayImage, g_grayImage, Size(3, 3));
//
//	// 创建窗口
//	namedWindow(WINDOW_NAME1, CV_WINDOW_AUTOSIZE);
//	imshow(WINDOW_NAME1, g_srcImage);
//
//	//创建滚动条并初始化
//	createTrackbar("canny阈值", WINDOW_NAME1, &g_nThresh, g_nThresh_max, on_ThreshChange);
//	on_ThreshChange(0, 0);
//
//	waitKey(0);
//	return(0);
//}
//
//void on_ThreshChange(int, void*)
//{
//
//	// 用Canny算子检测边缘
//	Canny(g_grayImage, g_cannyMat_output, g_nThresh, g_nThresh * 2, 3);
//
//	// 寻找轮廓
//	findContours(g_cannyMat_output, g_vContours, g_vHierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	// 绘出轮廓
//	Mat drawing = Mat::zeros(g_cannyMat_output.size(), CV_8UC3);
//	for (int i = 0; i < g_vContours.size(); i++)
//	{
//		Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));//任意值
//		drawContours(drawing, g_vContours, i, color, 2, 8, g_vHierarchy, 0, Point());
//	}
//
//	// 显示效果图
//	imshow(WINDOW_NAME2, drawing);
//}
//
//
