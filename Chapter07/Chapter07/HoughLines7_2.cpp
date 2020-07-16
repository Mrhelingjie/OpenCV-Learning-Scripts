//#include<opencv2/opencv.hpp>
//#include<vector>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
////void HoughLinesShow() {
////	Mat srcImage = imread("./7-2/1.jpg");
////	if (!srcImage.data)
////	{
////		printf("load error");
////		return;
////	}
////	Mat tmpImage, dstImage;
////
////	Canny(srcImage,tmpImage,50, 200, 3);
////	cvtColor(tmpImage, dstImage, COLOR_GRAY2BGR);
////
////	vector<Vec2f> lines;
////	HoughLines(tmpImage, lines, 1, CV_PI / 180, 150, 0, 0);
////
////	for (size_t i = 0; i < lines.size(); i++)
////	{
////		float rho = lines[i][0], theta = lines[i][1];
////		Point pt1, pt2;
////		double a = cos(theta), b = sin(theta);
////		double x0 = a * rho, y0 = b * rho;
////
////		pt1.x = cvRound(x0 + 1000 * (-b));
////		pt1.y = cvRound(y0 + 1000 * (a));
////		pt2.x = cvRound(x0 - 1000 * (-b));
////		pt2.y = cvRound(y0 - 1000 * (a));
////
////		line(dstImage, pt1, pt2, Scalar(55, 100, 195), 1, CV_AA);
////	}
////	imshow("yuanshitu", srcImage);
////
////	imshow("canny", tmpImage);
////
////	imshow("result", dstImage);
////	waitKey(0);
////
////}
////void HoughLinesPShow() {
////	Mat srcImage = imread("./7-2/1.jpg");
////	if (!srcImage.data)
////	{
////		printf("load error");
////		return;
////	}
////	Mat tmpImage, dstImage;
////
////	Canny(srcImage, tmpImage, 50, 200, 3);
////	cvtColor(tmpImage, dstImage, COLOR_GRAY2BGR);
////
////	vector<Vec4i> lines;
////	HoughLinesP(tmpImage, lines, 1, CV_PI / 180, 80, 50, 10);
////
////	for (size_t i = 0; i < lines.size(); i++)
////	{
////		Vec4i l = lines[i];
////
////		line(dstImage,Point(l[0],l[1]), Point(l[2],l[3]), Scalar(186, 88, 255), 1, CV_AA);
////	}
////	imshow("yuanshitu", srcImage);
////
////	imshow("canny", tmpImage);
////
////	imshow("result", dstImage);
////	waitKey(0);
////}
////void HoughCirclesShow() {
////	Mat srcImage = imread("./7-2/2.jpg");
////	if (!srcImage.data)
////	{
////		printf("load error");
////		return;
////	}
////	Mat tmpImage, dstImage;
////	imshow("yuanshitu", srcImage);
////
////	cvtColor(srcImage, tmpImage, COLOR_BGR2GRAY);
////	GaussianBlur(tmpImage, tmpImage, Size(9, 9), 2, 2);
////
////
////	vector<Vec3f> circles;
////	HoughCircles(tmpImage, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);
////
////	for (size_t i = 0; i < circles.size(); i++)
////	{
////		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
////		int radius = cvRound(circles[i][2]);
////		
////		circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
////		circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
////	}
////	imshow("result", srcImage);
////	waitKey(0);
////}
////���ں�
//#define WINDOW_NAME_SRC "ԭʼͼ"
//#define WINDOW_NAME_HOUGHLINE "��������"
//#define WINDOW_NAME_HOUGHLINEP "�������Ը���"
//#define WINDOW_NAME_HOUGECIRCLE "����Բ"
////ȫ�ֱ���
//Mat g_srcImage, g_midImage, g_dstImage;
//vector<Vec4i> g_lines;
//int g_nthreshold = 100;
//
////ȫ�ֺ���
//
//static void on_HoughLines(int, void *);
//
//
//int main() {
//	
//	
//	
//
//	
//	Mat g_srcImage = imread("./7-2/2.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	//����ԭʼͼ��Mat��������   
//	
//
//	//��ʾԭʼͼ  
//	imshow("��ԭʼͼ��", g_srcImage);
//
//	//����������
//	namedWindow("��Ч��ͼ��", 1);
//	createTrackbar("ֵ", "��Ч��ͼ��", &g_nthreshold, 200, on_HoughLines);
//
//	//���б�Ե����ת��Ϊ�Ҷ�ͼ
//	Canny(g_srcImage, g_midImage, 50, 200, 3);//����һ��canny��Ե���
//	cvtColor(g_midImage, g_dstImage, CV_GRAY2BGR);//ת����Ե�����ͼΪ�Ҷ�ͼ
//
//	//����һ�λص�����������һ��HoughLinesP����
//	on_HoughLines(g_nthreshold, 0);
//	HoughLinesP(g_midImage, g_lines, 1, CV_PI / 180, 80, 50, 10);
//
//	//��ʾЧ��ͼ  
//	imshow("��Ч��ͼ��", g_dstImage);
//
//
//	waitKey(0);
//
//	return 0;
//
//}
//
//
////-----------------------------------��on_HoughLines( )������--------------------------------
////		����������ñ����/��ñ���㡿���ڵĻص�����
////----------------------------------------------------------------------------------------------
//static void on_HoughLines(int, void*)
//{
//	//����ֲ���������ȫ�ֱ���
//	Mat dstImage = g_dstImage.clone();
//	Mat midImage = g_midImage.clone();
//
//	//����HoughLinesP����
//	vector<Vec4i> mylines;
//	HoughLinesP(midImage, mylines, 1, CV_PI / 180, g_nthreshold + 1, 50, 10);
//
//	//ѭ����������ÿһ���߶�
//	for (size_t i = 0; i < mylines.size(); i++)
//	{
//		Vec4i l = mylines[i];
//		line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(23, 180, 55), 1, CV_AA);
//	}
//	//��ʾͼ��
//	imshow("��Ч��ͼ��", dstImage);
//}
