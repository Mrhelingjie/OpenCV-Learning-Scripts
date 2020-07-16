//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;
//#define TRACKBAR_NAME "迭代值"
//#define WINDOW_NAME_SRC "原始图"
//#define WINDOW_NAME_OpenClose "开运算闭运算"
//#define WINDOW_NAME_ErodeDilate "腐蚀膨胀"
//#define WINDOW_NAME_TopBlackHat "顶帽黑帽"
//
////全局变量
//Mat g_srcImage, g_dstImage;
//int g_nElementShape = MORPH_RECT;// 元素结构形状
//
////trackbar变量
//int g_nMaxIterationNum = 10;
//int g_nOpenCloseNum = 0;
//int g_nErodeDilateNum = 0;
//int g_nTopBlackHatNum = 0;
//
////回调函数声明
//static void on_OpenClose(int, void*);
//static void on_ErodeDilate(int, void*);
//static void on_TopBlackHat(int, void*);
//
//int main() {
//	g_srcImage = imread("./6-4/1.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	namedWindow(WINDOW_NAME_SRC,1);
//	namedWindow(WINDOW_NAME_OpenClose, 1);
//	namedWindow(WINDOW_NAME_ErodeDilate, 1);
//	namedWindow(WINDOW_NAME_TopBlackHat, 1);
//
//	g_nOpenCloseNum = 9;
//	g_nErodeDilateNum = 9;
//	g_nTopBlackHatNum = 2;
//
//
//	createTrackbar(TRACKBAR_NAME, WINDOW_NAME_OpenClose, &g_nOpenCloseNum,g_nMaxIterationNum*2+1,on_OpenClose);
//	createTrackbar(TRACKBAR_NAME, WINDOW_NAME_ErodeDilate, &g_nErodeDilateNum, g_nMaxIterationNum * 2 + 1, on_ErodeDilate);
//	createTrackbar(TRACKBAR_NAME, WINDOW_NAME_TopBlackHat, &g_nTopBlackHatNum, g_nMaxIterationNum * 2 + 1, on_TopBlackHat);
//
//	while (true)
//	{
//		int c;
//		on_OpenClose(g_nOpenCloseNum, 0);
//		on_ErodeDilate(g_nErodeDilateNum, 0);
//		on_TopBlackHat(g_nTopBlackHatNum, 0);
//		c = waitKey(0);
//		//按下键盘按键Q或者ESC，程序退出
//		if ((char)c == 'q' || (char)c == 27)
//			break;
//		//按下键盘按键1，使用椭圆(Elliptic)结构元素结构元素MORPH_ELLIPSE
//		if ((char)c == 49)//键盘按键1的ASII码为49
//			g_nElementShape = MORPH_ELLIPSE;
//		//按下键盘按键2，使用矩形(Rectangle)结构元素MORPH_RECT
//		else if ((char)c == 50)//键盘按键2的ASII码为50
//			g_nElementShape = MORPH_RECT;
//		//按下键盘按键3，使用十字形(Cross-shaped)结构元素MORPH_CROSS
//		else if ((char)c == 51)//键盘按键3的ASII码为51
//			g_nElementShape = MORPH_CROSS;
//		//按下键盘按键space，在矩形、椭圆、十字形结构元素中循环
//		else if ((char)c == ' ')
//			g_nElementShape = (g_nElementShape + 1) % 3;
//	}
//	return 0;
//
//}
//
//void on_OpenClose(int, void *)
//{
//	int offset = g_nOpenCloseNum - g_nMaxIterationNum;
//	int Absolute_offset = offset > 0 ? offset : -offset;
//	Mat element = getStructuringElement(
//		g_nElementShape,
//		Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1),
//		Point(Absolute_offset, Absolute_offset)
//	);
//	if (offset<0)
//	{
//		morphologyEx(
//			g_srcImage,
//			g_dstImage,
//			MORPH_OPEN,
//			element
//		);
//	}
//	else
//	{
//		morphologyEx(
//			g_srcImage,
//			g_dstImage,
//			MORPH_CLOSE,
//			element
//		);
//	}
//	imshow(WINDOW_NAME_OpenClose, g_dstImage);
//}
//
//void on_ErodeDilate(int, void *)
//{
//	int offset = g_nErodeDilateNum - g_nMaxIterationNum;
//	int Absolute_offset = offset > 0 ? offset : -offset;
//	Mat element = getStructuringElement(
//		g_nElementShape,
//		Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1),
//		Point(Absolute_offset, Absolute_offset)
//	);
//	if (offset < 0)
//	{
//		erode(
//			g_srcImage,
//			g_dstImage,
//			element
//		);
//	}
//	else
//	{
//		dilate(
//			g_srcImage,
//			g_dstImage,
//			element
//		);
//	}
//	imshow(WINDOW_NAME_ErodeDilate, g_dstImage);
//}
//
//void on_TopBlackHat(int, void *)
//{
//	int offset = g_nTopBlackHatNum - g_nMaxIterationNum;
//	int Absolute_offset = offset > 0 ? offset : -offset;
//	Mat element = getStructuringElement(
//		g_nElementShape,
//		Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1),
//		Point(Absolute_offset, Absolute_offset)
//	);
//	if (offset < 0)
//	{
//		morphologyEx(
//			g_srcImage,
//			g_dstImage,
//			MORPH_TOPHAT,
//			element
//		);
//	}
//	else
//	{
//		morphologyEx(
//			g_srcImage,
//			g_dstImage,
//			MORPH_BLACKHAT,
//			element
//		);
//	}
//	imshow(WINDOW_NAME_TopBlackHat, g_dstImage);
//}
