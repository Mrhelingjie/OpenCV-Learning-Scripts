//#include<opencv2/opencv.hpp>
//#include<iostream>
//#define WINDOW_NAME_START "ԭʼͼ"
//#define WINDOW_NAMW_END "Ч��ͼ"
//using namespace std;
//using namespace cv;
//
////void MorphologyDilate() {
////	Mat image = imread("./6-3/1.jpg");
////	namedWindow("����ԭͼ");
////	namedWindow("����Ч��ͼ");
////	imshow("����ԭͼ", image);
////	
////	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
////	Mat out;
////	dilate(image, out, element);
////
////	imshow("����Ч��ͼ", out);
////}
////void MorphologyErode() {
////	Mat image = imread("./6-3/1.jpg");
////	namedWindow("��ʴԭͼ");
////	namedWindow("��ʴЧ��ͼ");
////	imshow("��ʴԭͼ", image);
////	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
////	Mat out;
////	erode(image, out, element);
////
////	imshow("��ʴЧ��ͼ", out);
////}
//
//Mat g_srcImage, g_dstImage;
//int g_nTrackbarNumber = 0;
//int g_nStructElementSize = 3;
//
//void Process();//���ͺ͸�ʴ�Ĵ�����
//void on_TrackbarNumChange(int, void *);//�ص�����
//void on_ElementSizeChange(int, void *);//�ص�����
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
//	createTrackbar("��ʴ/����", WINDOW_NAMW_END, &g_nTrackbarNumber, 1, on_TrackbarNumChange);
//	createTrackbar("�ں˳ߴ�", WINDOW_NAMW_END, &g_nStructElementSize, 21, on_ElementSizeChange);
//	//���һЩ������Ϣ
//	cout << endl << "\t���гɹ���������������۲�ͼ��Ч��~\n\n"
//		<< "\t���¡�q����ʱ�������˳���\n";
//
//	//��ѯ��ȡ������Ϣ������q���������˳�
//	while (char(waitKey(1)) != 'q') {}
//	return 0;
//}
//void Process() {
//	Mat element = getStructuringElement(
//		MORPH_RECT,
//		Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1),//����size�Ĵ�С
//		Point(g_nStructElementSize, g_nStructElementSize)//ȡ����size������λ
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
