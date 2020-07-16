//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;
//
//#define WINDOW_NAME "程序窗口"
//
//int g_nThresholdValue = 100;
//int g_nThresholdType = 3;
//Mat g_srcImage, g_dstImage, g_grayImage;
//
//void on_Threshold(int, void*);
//
//int main() {
//	g_srcImage = imread("./6-7/1.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
//	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
//
//	createTrackbar(
//		"模式",
//		WINDOW_NAME,
//		&g_nThresholdType,
//		4,
//		on_Threshold
//	);
//	createTrackbar(
//		"参数值",
//		WINDOW_NAME,
//		&g_nThresholdValue,
//		255,
//		on_Threshold
//	);
//	on_Threshold(0, 0);
//	while (true)
//	{
//		int key;
//		key = waitKey(20);
//		if ((char)key == 27)
//		{
//			break;
//		}
//	}
//	return 0;
//
//}
//
//void on_Threshold(int, void *)
//{
//	threshold(
//		g_grayImage,
//		g_dstImage,
//		g_nThresholdValue,
//		255,
//		g_nThresholdType
//	);
//	imshow(WINDOW_NAME, g_dstImage);
//}
