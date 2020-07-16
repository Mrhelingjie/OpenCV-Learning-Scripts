//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;
//
//#define WINDOW_NAME "程序窗口"
//#define WINDOW_NAME_RESULT "效果图"
////void remapTest() {
////	Mat srcImage, dstImage;
////	Mat map_x, map_y;
////
////	srcImage = imread("./7-3/1.jpg");
////	if (!srcImage.data)
////	{
////		printf("load error");
////		return;
////	}
////	imshow(WINDOW_NAME_SRCIMAGE, srcImage);
////
////	dstImage.create(srcImage.size(), srcImage.type());
////	map_x.create(srcImage.size(), CV_32FC1);
////	map_y.create(srcImage.size(), CV_32FC1);
////
////	for (int i = 0; i < srcImage.rows; i++)
////	{
////		for (int j = 0; j < srcImage.cols; j++)
////		{
////			map_x.at<float>(i, j) = static_cast<float>(j);
////			map_y.at<float>(i, j) = static_cast<float>(srcImage.rows - i);
////		}
////	}
////
////	remap(srcImage, dstImage, map_x, map_y, CV_INTER_CUBIC, BORDER_CONSTANT, Scalar(0, 0, 0));
////	imshow(WINDOW_NAME_RESULT, dstImage);
////
////}
////全局变量声明
//Mat g_srcImage, g_dstImage;
//Mat g_map_x, g_map_y;
////全局函数声明
//int update_map(int key);
//static void ShowHelpText();
//
//int main() {
//	g_srcImage = imread("./7-3/2.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	g_dstImage.create(g_srcImage.size(), g_srcImage.type());
//	g_map_x.create(g_srcImage.size(), CV_32FC1);
//	g_map_y.create(g_srcImage.size(), CV_32FC1);
//
//	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
//	imshow(WINDOW_NAME, g_srcImage);
//
//	while (true)
//	{
//		int key = waitKey(0);
//		if ((key&255)==27)
//		{
//			printf("exit");
//			break;
//		}
//		update_map(key);
//		remap(g_srcImage, g_dstImage, g_map_x, g_map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//		imshow(WINDOW_NAME, g_dstImage);
//	}
//	return 0;
//}
//int update_map(int key) {
//	//双层循环，遍历每一个像素点
//	for (int j = 0; j < g_srcImage.rows; j++)
//	{
//		for (int i = 0; i < g_srcImage.cols; i++)
//		{
//			switch (key)
//			{
//			case '1': // 键盘【1】键按下，进行第一种重映射操作
//				if (i > g_srcImage.cols*0.25 && i < g_srcImage.cols*0.75 && j > g_srcImage.rows*0.25 && j < g_srcImage.rows*0.75)
//				{
//					g_map_x.at<float>(j, i) = static_cast<float>(2 * (i - g_srcImage.cols*0.25) + 0.5);
//					g_map_y.at<float>(j, i) = static_cast<float>(2 * (j - g_srcImage.rows*0.25) + 0.5);
//				}
//				else
//				{
//					g_map_x.at<float>(j, i) = 0;
//					g_map_y.at<float>(j, i) = 0;
//				}
//				break;
//			case '2':// 键盘【2】键按下，进行第二种重映射操作
//				g_map_x.at<float>(j, i) = static_cast<float>(i);
//				g_map_y.at<float>(j, i) = static_cast<float>(g_srcImage.rows - j);
//				break;
//			case '3':// 键盘【3】键按下，进行第三种重映射操作
//				g_map_x.at<float>(j, i) = static_cast<float>(g_srcImage.cols - i);
//				g_map_y.at<float>(j, i) = static_cast<float>(j);
//				break;
//			case '4':// 键盘【4】键按下，进行第四种重映射操作
//				g_map_x.at<float>(j, i) = static_cast<float>(g_srcImage.cols - i);
//				g_map_y.at<float>(j, i) = static_cast<float>(g_srcImage.rows - j);
//				break;
//			}
//		}
//	}
//	return 1;
//}