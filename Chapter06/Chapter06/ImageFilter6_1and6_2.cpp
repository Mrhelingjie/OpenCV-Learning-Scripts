//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
////-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
////	������ȫ�ֱ�������
////-----------------------------------------------------------------------------------------------
//Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3,g_dstImage4,g_dstImage5;//�洢ͼƬ��Mat����
//int g_nBoxFilterValue = 3;  //�����˲�����ֵ
//int g_nMeanBlurValue = 3;  //��ֵ�˲�����ֵ
//int g_nGaussianBlurValue = 3;  //��˹�˲�����ֵ
//int g_nMedianBlurValue = 3;  //��ֵ�˲�
//int g_nBilateralFilterValue = 3; //˫���˲�
//
//
//
////-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
////	������ȫ�ֺ�������
////-----------------------------------------------------------------------------------------------
////�ĸ��켣���Ļص�����
//static void on_BoxFilter(int, void *);		//��ֵ�˲�
//static void on_MeanBlur(int, void *);		//��ֵ�˲�
//static void on_GaussianBlur(int, void *);			//��˹�˲�
//static void on_MedianBlur(int, void *);
//static void on_BilateralFilter(int, void *);
//
////void BoxFilterImage() {
////	Mat image = imread("./6-1/1.jpg");
////
////	namedWindow("�����˲�-ԭͼ");
////	imshow("�����˲�-ԭͼ", image);
////	Mat dstImage;
////	boxFilter(
////		image,
////		dstImage,
////		-1,
////		Size(5, 5),
////		Point(-1,-1),
////		true
////	);
////	namedWindow("�����˲�-Ч��ͼ");
////	imshow("�����˲�-Ч��ͼ", dstImage);
////}
////void BlurFilterImage() {
////	Mat image = imread("./6-1/1.jpg");
////
////	namedWindow("��ֵ�˲�-ԭͼ");
////	imshow("��ֵ�˲�-ԭͼ", image);
////	Mat dstImage;
////	blur(
////		image,
////		dstImage,
////		Size(7, 7)	
////	);
////	namedWindow("��ֵ�˲�-Ч��ͼ");
////	imshow("��ֵ�˲�-Ч��ͼ", dstImage);
////}
////
////void GaussianBlurImage() {
////	Mat image = imread("./6-1/1.jpg");
////
////	namedWindow("��˹�˲�-ԭͼ");
////	imshow("��˹�˲�-ԭͼ", image);
////	Mat dstImage;
////	GaussianBlur(
////		image,
////		dstImage,
////		Size(3, 3),
////		0,
////		0
////	);
////	namedWindow("��˹�˲�-Ч��ͼ");
////	imshow("��˹�˲�-Ч��ͼ", dstImage);
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
//	namedWindow("ԭͼ",1);
//	imshow("ԭͼ", g_srcImage);
//
//
//	namedWindow("�����˲�",1);
//	createTrackbar("�ں�ֵ��", "�����˲�", &g_nBoxFilterValue, 40, on_BoxFilter);
//	on_BoxFilter(g_nBoxFilterValue, 0);
//	
//	
//	namedWindow("��ֵ�˲�", 1);
//	createTrackbar("�ں�ֵ��", "��ֵ�˲�", &g_nMeanBlurValue, 40, on_MeanBlur);
//	on_MeanBlur(g_nMeanBlurValue, 0);
//	
//	namedWindow("��˹�˲�", 1);
//	createTrackbar("�ں�ֵ��", "��˹�˲�", &g_nGaussianBlurValue, 40, on_GaussianBlur);
//	on_MeanBlur(g_nGaussianBlurValue, 0);
//
//	namedWindow("��ֵ�˲�", 1);
//	createTrackbar("����ֵ��", "��ֵ�˲�", &g_nMedianBlurValue, 50, on_MedianBlur);
//	on_MedianBlur(g_nMedianBlurValue, 0);
//	
//	namedWindow("˫���˲�", 1);
//	createTrackbar("����ֵ��", "˫���˲�", &g_nBilateralFilterValue, 50, on_BilateralFilter);
//	on_BilateralFilter(g_nBilateralFilterValue, 0);
//
//	cout << endl << "\t���гɹ���������������۲�ͼ��Ч��~\n\n"
//		<< "\t���¡�q����ʱ�������˳���\n";
//
//	//���¡�q����ʱ�������˳�
//	while (char(waitKey(1)) != 'q') {}
//	return 0;
//
//}
////�����˲�
//static void on_BoxFilter(int, void *) {
//	boxFilter(
//		g_srcImage,
//		g_dstImage1,
//		-1,
//		Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1),
//		Point(-1,-1),
//		false
//	);
//	imshow("�����˲�", g_dstImage1);
//}
////��ֵ�˲�
//static void on_MeanBlur(int, void *) {
//	blur(
//		g_srcImage,
//		g_dstImage2,
//		Size(g_nMeanBlurValue + 1, g_nGaussianBlurValue + 1),
//		Point(-1, -1)
//	);
//	imshow("��ֵ�˲�", g_dstImage2);
//
//}
////��˹�˲�
//static void on_GaussianBlur(int, void *) {
//	GaussianBlur(
//		g_srcImage,
//		g_dstImage3,
//		Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1),
//		0,
//		0
//	);
//	imshow("��˹�˲�", g_dstImage3);
//
//}
//static void on_MedianBlur(int, void *)
//{
//	medianBlur(
//		g_srcImage, 
//		g_dstImage4, 
//		g_nMedianBlurValue * 2 + 1
//	);
//	imshow("��ֵ�˲�", g_dstImage4);
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
//	imshow("˫���˲�", g_dstImage5);
//}