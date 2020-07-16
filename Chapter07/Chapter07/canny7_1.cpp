//#include<opencv2/opencv.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//using namespace cv;
//
////void cannyShow() {
////	Mat srcImage = imread("./7-1/1.jpg");
////	Mat srcClone = srcImage.clone();
////
////	imshow("yuanshitu", srcImage);
////	/*Canny(srcImage, srcImage, 150, 100, 3);
////	imshow("xiaoguotu", srcImage);*/
////
////	Mat dst, edge, gray;
////	dst.create(srcClone.size(), srcClone.type());
////	转换为灰度图
////	cvtColor(srcClone, gray, COLOR_BGR2GRAY);
////    降噪
////	blur(gray, edge, Size(3, 3));
////    运行canny
////	Canny(edge, edge, 3, 9, 3);
////
////	dst = Scalar::all(0);
////
////	srcClone.copyTo(dst, edge);
////	imshow("xiaoguotu", dst);
////}
////void sobelShow() {
////	Mat grad_x, grad_y;
////	Mat abs_grad_x, abs_grad_y, dst;
////	Mat src = imread("./7-1/1.jpg", 1);
////	Mat srcImage;
////	cvtColor(src, srcImage, COLOR_BGR2GRAY);
////	imshow("sobel-yuanshitu", srcImage);
////
////	Sobel(
////		srcImage,
////		grad_x,
////		CV_16S,
////		1, 0, 3, 1, 1,
////		BORDER_DEFAULT
////	);
////	convertScaleAbs(grad_x, abs_grad_x);
////	imshow("grad_xsobel", abs_grad_x);
////
////	Sobel(
////		srcImage,
////		grad_y,
////		CV_16S,
////		0, 1, 3, 1, 1,
////		BORDER_DEFAULT
////	);
////	convertScaleAbs(grad_y, abs_grad_y);
////	imshow("grad_ysobel", abs_grad_y);
////
////	addWeighted(
////		abs_grad_x, 0.5,
////		abs_grad_y, 0.5,
////		0,
////		dst
////	);
////	imshow("x+ygrad", dst);
////}
////void laplacianShow() {
////	Mat src, src_gray, dst, abs_dst;
////	src= imread("./7-1/1.jpg");
////	imshow("laplacianSRC", src);
////	GaussianBlur(
////		src,
////		src,
////		Size(3, 3),
////		0, 0,
////		BORDER_DEFAULT
////	);
////	cvtColor(src, src_gray, COLOR_BGR2GRAY);
////
////	Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
////	convertScaleAbs(dst, abs_dst);
////	imshow("laplacianRes", abs_dst);
////}
////void scharrShow() {
////	Mat grad_x, grad_y;
////	Mat abs_grad_x, abs_grad_y, dst;
////	Mat src= imread("./7-1/1.jpg");
////	imshow("scharrSRC", src);
////
////	Scharr(src, grad_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
////	convertScaleAbs(grad_x, abs_grad_x);
////	imshow("grad_xScharr", abs_grad_x);
////
////	Scharr(src, grad_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
////	convertScaleAbs(grad_y, abs_grad_y);
////	imshow("grad_yScharr", abs_grad_y);
////
////	addWeighted(
////		abs_grad_x, 0.5,
////		abs_grad_y, 0.5,
////		0, dst
////	);
////	imshow("x+yscharr", dst);
////}
//
////窗口宏
//#define WINDOW_NAME_SRCIMAGE "原始图片窗口"
//#define WINDOW_NAME_CANNY "canny检测窗口"
//#define WINDOW_NAME_SOBEL "sobel检测窗口"
//#define WINDOW_NAME_SCHARR "scharr检测窗口"
//
////全局变量
//
//Mat g_srcImage, g_srcGrayImage, g_dstImage;
//
////Canny
//Mat g_cannyDetectedEdges; //blur 降噪之后的灰度图
//int g_cannyLowThreshold = 1;//TrackBar
//
////sobel
//Mat g_sobelGradient_X, g_sobelGradient_Y;
//Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
//int g_sobelKernelSize = 1; //TrackBar
//
////Scharr
//Mat g_scharrGradient_X, g_scharrGradient_Y;
//Mat g_scharrAbsGradient_X, g_scharrAbsGradient_Y;
//
////函数声明
//static void on_Canny(int, void*);//canny 边缘检测回调
//static void on_Sobel(int, void*);//sobel 边缘检测回调
//void Scharr();// 封装scharr相关代码
//
//int main() {
//
//	g_srcImage = imread("./7-1/1.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	namedWindow(WINDOW_NAME_SRCIMAGE);
//	imshow(WINDOW_NAME_SRCIMAGE, g_srcImage);
//
//	//2 gary
//	cvtColor(g_srcImage, g_srcGrayImage, COLOR_BGR2GRAY);
//	//init g_dstImage
//	g_dstImage.create(g_srcImage.size(), g_srcImage.type());
//
//	namedWindow(WINDOW_NAME_CANNY, WINDOW_AUTOSIZE);
//	namedWindow(WINDOW_NAME_SOBEL, WINDOW_AUTOSIZE);
//
//	createTrackbar("参数值：", WINDOW_NAME_CANNY, &g_cannyLowThreshold, 120, on_Canny);
//	createTrackbar("参数值：", WINDOW_NAME_SOBEL, &g_sobelKernelSize, 3, on_Sobel);
//
//	on_Canny(0, 0);
//	on_Sobel(0, 0);
//	Scharr();
//	waitKey(0);
//	return 0;
//}
//
//void on_Canny(int, void *)
//{
//	//3x3内核降噪
//	blur(g_srcGrayImage, g_cannyDetectedEdges, Size(3, 3));
//	Canny(
//		g_cannyDetectedEdges,
//		g_cannyDetectedEdges,
//		g_cannyLowThreshold,
//		g_cannyLowThreshold * 3,
//		3
//	);
//
//	g_dstImage = Scalar::all(0);
//	g_srcImage.copyTo(g_dstImage, g_cannyDetectedEdges);
//	imshow(WINDOW_NAME_CANNY, g_dstImage);
//
//}
//
//void on_Sobel(int, void *)
//{
//	// X
//	Sobel(g_srcImage,g_sobelGradient_X,CV_16S,1, 0,(2 * g_sobelKernelSize + 1),1, 1,BORDER_DEFAULT);
//	convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);
//	// Y
//	Sobel(g_srcImage, g_sobelGradient_Y, CV_16S, 0, 1, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
//	convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y);
//
//	addWeighted(g_sobelAbsGradient_X, 0.5,g_sobelAbsGradient_Y, 0.5,0,g_dstImage);
//	imshow(WINDOW_NAME_SOBEL, g_dstImage);
//}
//
//
//
//void Scharr()
//{
//	// X
//	Scharr(
//		g_srcImage,
//		g_scharrGradient_X,
//		CV_16S,
//		1, 0, 1, 0,
//		BORDER_DEFAULT
//	);
//	convertScaleAbs(g_scharrGradient_X, g_scharrAbsGradient_X);
//	// Y
//	Scharr(
//		g_srcImage,
//		g_scharrGradient_Y,
//		CV_16S,
//		0, 1, 1, 0,
//		BORDER_DEFAULT
//	);
//	convertScaleAbs(g_scharrGradient_Y, g_scharrAbsGradient_Y);
//
//	addWeighted(
//		g_scharrAbsGradient_X, 0.5,
//		g_scharrAbsGradient_Y, 0.5,
//		0,
//		g_dstImage
//	);
//	imshow(WINDOW_NAME_SCHARR, g_dstImage);
//}
