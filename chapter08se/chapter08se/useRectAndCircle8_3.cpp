////#include<opencv2/opencv.hpp>
////#include<iostream>
////using namespace std;
////using namespace cv;
////
////void useRecToShow() {
////	Mat image(600, 600, CV_8UC3);
////	RNG& rng = theRNG();
////	while (true)
////	{
////		int count = rng.uniform(3, 103);
////		vector<Point> points;
////
////		for (int i = 0; i < count; i++)
////		{
////			Point point;
////			point.x = rng.uniform(image.cols / 4, image.cols * 3 / 4);
////			point.y = rng.uniform(image.rows / 4, image.rows * 3 / 4);
////			points.push_back(point);
////		}
////
////		RotatedRect box = minAreaRect(Mat(points));
////		Point2f vertex[4];
////		box.points(vertex);
////
////		image = Scalar::all(0);
////		for (int i = 0; i < count; i++)
////		{
////			circle(
////				image,
////				points[i], 3,
////				Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),
////				CV_FILLED,
////				CV_AA
////			);
////		}
////
////		for (int i = 0; i < 4; i++)
////		{
////			line(
////				image,
////				vertex[i],
////				vertex[(i + 1) % 4],
////				Scalar(100, 200, 211),
////				2, CV_AA
////			);
////		}
////		imshow("�����Χ", image);
////		char key = (char)waitKey();
////		if (key == 27 || key == 'q') {
////			break;
////		}
////
////	}
////	return ;
////}
////
////void useCircleToShow() {
////	Mat image(600, 600, CV_8UC3);
////	RNG& rng = theRNG();
////	while (true)
////	{
////		int count = rng.uniform(3, 103);
////		vector<Point> points;
////
////		for (int i = 0; i < count; i++)
////		{
////			Point point;
////			point.x = rng.uniform(image.cols / 4, image.cols * 3 / 4);
////			point.y = rng.uniform(image.rows / 4, image.rows * 3 / 4);
////			points.push_back(point);
////		}
////
////		Point2f center;
////		float radius = 0;
////		minEnclosingCircle(Mat(points),center,radius);
////		
////
////		image = Scalar::all(0);
////		for (int i = 0; i < count; i++)
////		{
////			circle(
////				image,
////				points[i], 3,
////				Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),
////				CV_FILLED,
////				CV_AA
////			);
////		}
////
////		circle(
////			image, 
////			center, 
////			cvRound(radius), 
////			Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)),
////			2, 
////			CV_AA
////		);
////		imshow("Բ�ΰ�Χ", image);
////		char key = (char)waitKey();
////		if (key == 27 || key == 'q') {
////			break;
////		}
////
////	}
////	return;
////}
////int main() {
////	useRecToShow();
////	useCircleToShow();
////	return 0;
////}
//
//
//
//
//
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//
//using namespace cv;
//using namespace std;
//
//#define WINDOW_NAME1 "��ԭʼͼ���ڡ�"        //Ϊ���ڱ��ⶨ��ĺ� 
//#define WINDOW_NAME2 "��Ч��ͼ���ڡ�"        //Ϊ���ڱ��ⶨ��ĺ� 
//
////  ȫ�ֱ���������
//Mat g_srcImage;
//Mat g_grayImage;
//int g_nThresh = 50;//��ֵ
//int g_nMaxThresh = 255;//��ֵ���ֵ
//RNG g_rng(12345);//�����������
//
//void on_ContoursChange(int, void*);
//
//int main()
//{
//	
//	//��1������3ͨ����ԭͼ��
//	g_srcImage = imread("1.jpg", 1);
//	if (!g_srcImage.data) 
//	{ 
//		printf("load error"); 
//		return 0; 
//	}
//
//	//��2���õ�ԭͼ�ĻҶ�ͼ�񲢽���ƽ��
//	cvtColor(g_srcImage, g_grayImage, CV_BGR2GRAY);
//	blur(g_grayImage, g_grayImage, Size(3, 3));
//
//	//��3������ԭʼͼ���ڲ���ʾ
//	namedWindow(WINDOW_NAME1, CV_WINDOW_AUTOSIZE);
//	imshow(WINDOW_NAME1, g_srcImage);
//
//	//��4�����ù�����������һ�λص�����
//	createTrackbar(" ��ֵ:", WINDOW_NAME1, &g_nThresh, g_nMaxThresh, on_ContoursChange);
//	on_ContoursChange(0, 0);
//
//	waitKey(0);
//
//	return(0);
//}
//
//void on_ContoursChange(int, void*)
//{
//	Mat threshold_output;
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	
//	//��Ե���
//	threshold(g_grayImage, threshold_output, g_nThresh, 255, THRESH_BINARY);
//
//	//������
//	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	//����αƽ����� + �����Բ��
//	vector<vector<Point>> contours_poly(contours.size());
//	vector<Rect> boundRect(contours.size());
//	//ÿ��������ԭ����뾶
//	vector<Point2f> center(contours.size());
//	vector<float> radius(contours.size());
//	//��ÿ������ѭ�� �õ���ͼ����
//	for (unsigned int i = 0; i < contours.size(); i++)
//	{
//		//�ƽ��Ķ��������
//		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
//		//��������ľ���
//		boundRect[i] = boundingRect(Mat(contours_poly[i]));
//		//��С��ΧԲ
//		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
//	}
//	//������ͼ ����ͨ������һ��
//	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
//
//	for (unsigned int i = 0; i < contours.size(); i++)
//	{
//		Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
//		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
//		rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
//		circle(drawing, center[i], cvRound(radius[i]), color, 2, 8, 0);
//	}
//	namedWindow(WINDOW_NAME2, WINDOW_AUTOSIZE);
//	imshow(WINDOW_NAME2, drawing);
//}
//
//
