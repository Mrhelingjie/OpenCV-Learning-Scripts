//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//#define WINDOW_NAME "滑动条修改对比度与亮度"
//
////函数声明
//void on_changeContrastAndBright(int, void*);
//
////全局变量
//int g_nContrastValue;
//int g_nBrightValue;
//Mat g_srcImage, g_dstImage;
//
//int main() {
//	g_srcImage = imread("./5_4/1.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());
//	g_nContrastValue = 80;
//	g_nBrightValue = 80;
//	namedWindow(WINDOW_NAME, 1);
//	char TrackBarContrastName[50];
//	char TrackBarBrightName[50];
//	sprintf(TrackBarContrastName, "对比度%d", g_nContrastValue);
//	sprintf(TrackBarBrightName, "亮度%d", g_nBrightValue);
//
//	createTrackbar(TrackBarContrastName, WINDOW_NAME, &g_nContrastValue, 300, on_changeContrastAndBright);
//	createTrackbar(TrackBarBrightName, WINDOW_NAME, &g_nBrightValue, 200, on_changeContrastAndBright);
//	on_changeContrastAndBright(g_nContrastValue, 0);
//	on_changeContrastAndBright(g_nBrightValue, 0);
//	while (char(waitKey(1))!= 'q'){}
//	return 0;
//	
//}
//
//void on_changeContrastAndBright(int, void*) {
//	namedWindow("原始图窗口", 1);
//	for (int i = 0; i < g_srcImage.rows; i++)
//	{
//		for (int j = 0; j < g_srcImage.cols; j++)
//		{
//			for (int k = 0; k < 3; k++)
//			{
//				g_dstImage.at<Vec3b>(i, j)[k] =
//					saturate_cast<uchar>(
//					(g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(i, j)[k]) + g_nBrightValue);
//				//saturate_cast 数据溢出保护函数
//			}
//		}
//	}
//	imshow("原始图窗口", g_srcImage);
//	imshow(WINDOW_NAME, g_dstImage);
//}