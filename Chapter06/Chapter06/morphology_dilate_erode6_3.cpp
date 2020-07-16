//#include<opencv2/opencv.hpp>
//#include<iostream>
//#define WINDOW_NAME_START "原始图"
//#define WINDOW_NAMW_END "效果图"
//using namespace std;
//using namespace cv;
//
////void MorphologyDilate() {
////	Mat image = imread("./6-3/1.jpg");
////	namedWindow("膨胀原图");
////	namedWindow("膨胀效果图");
////	imshow("膨胀原图", image);
////	
////	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
////	Mat out;
////	dilate(image, out, element);
////
////	imshow("膨胀效果图", out);
////}
////void MorphologyErode() {
////	Mat image = imread("./6-3/1.jpg");
////	namedWindow("腐蚀原图");
////	namedWindow("腐蚀效果图");
////	imshow("腐蚀原图", image);
////	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
////	Mat out;
////	erode(image, out, element);
////
////	imshow("腐蚀效果图", out);
////}
//
//Mat g_srcImage, g_dstImage;
//int g_nTrackbarNumber = 0;
//int g_nStructElementSize = 3;
//
//void Process();//膨胀和腐蚀的处理函数
//void on_TrackbarNumChange(int, void *);//回调函数
//void on_ElementSizeChange(int, void *);//回调函数
//
//int main() {
//	g_srcImage= imread("./6-3/1.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	namedWindow(WINDOW_NAME_START);
//	imshow(WINDOW_NAME_START, g_srcImage);
//	Mat element = getStructuringElement(
//		MORPH_RECT,
//		Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1),
//		Point(g_nStructElementSize, g_nStructElementSize)
//	);
//	erode(
//		g_srcImage,
//		g_dstImage,
//		element
//	);
//	imshow(WINDOW_NAMW_END, g_dstImage);
//
//	createTrackbar("腐蚀/膨胀", WINDOW_NAMW_END, &g_nTrackbarNumber, 1, on_TrackbarNumChange);
//	createTrackbar("内核尺寸", WINDOW_NAMW_END, &g_nStructElementSize, 21, on_ElementSizeChange);
//	//输出一些帮助信息
//	cout << endl << "\t运行成功，请调整滚动条观察图像效果~\n\n"
//		<< "\t按下“q”键时，程序退出。\n";
//
//	//轮询获取按键信息，若下q键，程序退出
//	while (char(waitKey(1)) != 'q') {}
//	return 0;
//}
//void Process() {
//	Mat element = getStructuringElement(
//		MORPH_RECT,
//		Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1),//控制size的大小
//		Point(g_nStructElementSize, g_nStructElementSize)//取上面size的中心位
//	);
//	if (g_nTrackbarNumber == 0)
//	{
//		erode(
//			g_srcImage,
//			g_dstImage,
//			element
//		);
//	}
//	else {
//		dilate(
//			g_srcImage,
//			g_dstImage,
//			element
//		);
//	}
//	imshow(WINDOW_NAMW_END, g_dstImage);
//}
//
//void on_TrackbarNumChange(int, void *)
//{
//	Process();
//}
//
//void on_ElementSizeChange(int, void *)
//{
//	Process();
//}
