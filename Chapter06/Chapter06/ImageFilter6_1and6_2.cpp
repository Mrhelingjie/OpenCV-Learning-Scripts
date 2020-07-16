//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
////-----------------------------------【全局变量声明部分】--------------------------------------
////	描述：全局变量声明
////-----------------------------------------------------------------------------------------------
//Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3,g_dstImage4,g_dstImage5;//存储图片的Mat类型
//int g_nBoxFilterValue = 3;  //方框滤波参数值
//int g_nMeanBlurValue = 3;  //均值滤波参数值
//int g_nGaussianBlurValue = 3;  //高斯滤波参数值
//int g_nMedianBlurValue = 3;  //中值滤波
//int g_nBilateralFilterValue = 3; //双边滤波
//
//
//
////-----------------------------------【全局函数声明部分】--------------------------------------
////	描述：全局函数声明
////-----------------------------------------------------------------------------------------------
////四个轨迹条的回调函数
//static void on_BoxFilter(int, void *);		//均值滤波
//static void on_MeanBlur(int, void *);		//均值滤波
//static void on_GaussianBlur(int, void *);			//高斯滤波
//static void on_MedianBlur(int, void *);
//static void on_BilateralFilter(int, void *);
//
////void BoxFilterImage() {
////	Mat image = imread("./6-1/1.jpg");
////
////	namedWindow("方框滤波-原图");
////	imshow("方框滤波-原图", image);
////	Mat dstImage;
////	boxFilter(
////		image,
////		dstImage,
////		-1,
////		Size(5, 5),
////		Point(-1,-1),
////		true
////	);
////	namedWindow("方框滤波-效果图");
////	imshow("方框滤波-效果图", dstImage);
////}
////void BlurFilterImage() {
////	Mat image = imread("./6-1/1.jpg");
////
////	namedWindow("均值滤波-原图");
////	imshow("均值滤波-原图", image);
////	Mat dstImage;
////	blur(
////		image,
////		dstImage,
////		Size(7, 7)	
////	);
////	namedWindow("均值滤波-效果图");
////	imshow("均值滤波-效果图", dstImage);
////}
////
////void GaussianBlurImage() {
////	Mat image = imread("./6-1/1.jpg");
////
////	namedWindow("高斯滤波-原图");
////	imshow("高斯滤波-原图", image);
////	Mat dstImage;
////	GaussianBlur(
////		image,
////		dstImage,
////		Size(3, 3),
////		0,
////		0
////	);
////	namedWindow("高斯滤波-效果图");
////	imshow("高斯滤波-效果图", dstImage);
////}
//
//int main() {
//	/*BoxFilterImage();
//	BlurFilterImage();
//	GaussianBlurImage();*/
//	g_srcImage= imread("./6-1/1.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	g_dstImage1 = g_srcImage.clone();
//	g_dstImage2 = g_srcImage.clone();
//	g_dstImage3 = g_srcImage.clone();
//	g_dstImage4 = g_srcImage.clone();
//	g_dstImage5 = g_srcImage.clone();
//
//	
//	namedWindow("原图",1);
//	imshow("原图", g_srcImage);
//
//
//	namedWindow("方框滤波",1);
//	createTrackbar("内核值：", "方框滤波", &g_nBoxFilterValue, 40, on_BoxFilter);
//	on_BoxFilter(g_nBoxFilterValue, 0);
//	
//	
//	namedWindow("均值滤波", 1);
//	createTrackbar("内核值：", "均值滤波", &g_nMeanBlurValue, 40, on_MeanBlur);
//	on_MeanBlur(g_nMeanBlurValue, 0);
//	
//	namedWindow("高斯滤波", 1);
//	createTrackbar("内核值：", "高斯滤波", &g_nGaussianBlurValue, 40, on_GaussianBlur);
//	on_MeanBlur(g_nGaussianBlurValue, 0);
//
//	namedWindow("中值滤波", 1);
//	createTrackbar("参数值：", "中值滤波", &g_nMedianBlurValue, 50, on_MedianBlur);
//	on_MedianBlur(g_nMedianBlurValue, 0);
//	
//	namedWindow("双边滤波", 1);
//	createTrackbar("参数值：", "双边滤波", &g_nBilateralFilterValue, 50, on_BilateralFilter);
//	on_BilateralFilter(g_nBilateralFilterValue, 0);
//
//	cout << endl << "\t运行成功，请调整滚动条观察图像效果~\n\n"
//		<< "\t按下“q”键时，程序退出。\n";
//
//	//按下“q”键时，程序退出
//	while (char(waitKey(1)) != 'q') {}
//	return 0;
//
//}
////方框滤波
//static void on_BoxFilter(int, void *) {
//	boxFilter(
//		g_srcImage,
//		g_dstImage1,
//		-1,
//		Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1),
//		Point(-1,-1),
//		false
//	);
//	imshow("方框滤波", g_dstImage1);
//}
////均值滤波
//static void on_MeanBlur(int, void *) {
//	blur(
//		g_srcImage,
//		g_dstImage2,
//		Size(g_nMeanBlurValue + 1, g_nGaussianBlurValue + 1),
//		Point(-1, -1)
//	);
//	imshow("均值滤波", g_dstImage2);
//
//}
////高斯滤波
//static void on_GaussianBlur(int, void *) {
//	GaussianBlur(
//		g_srcImage,
//		g_dstImage3,
//		Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1),
//		0,
//		0
//	);
//	imshow("高斯滤波", g_dstImage3);
//
//}
//static void on_MedianBlur(int, void *)
//{
//	medianBlur(
//		g_srcImage, 
//		g_dstImage4, 
//		g_nMedianBlurValue * 2 + 1
//	);
//	imshow("中值滤波", g_dstImage4);
//}
//
//
//
//static void on_BilateralFilter(int, void *)
//{
//	bilateralFilter(
//		g_srcImage, 
//		g_dstImage5, 
//		g_nBilateralFilterValue, 
//		g_nBilateralFilterValue * 2, 
//		g_nBilateralFilterValue / 2
//	);
//	imshow("双边滤波", g_dstImage5);
//}