//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//
//
////----------------------------------��ROI_AddImage( )������----------------------------------
//// ��������ROI_AddImage����
////	���������ø���Ȥ����ROIʵ��ͼ�����
////----------------------------------------------------------------------------------------------
//bool  ROI_AddImage()
//{
//	// ��1������ͼ��
//	Mat srcImage1 = imread("./5_2/dota_pa.jpg");
//	Mat logoImage = imread("./5_2/dota_logo.jpg");
//	if (!srcImage1.data) { 
//		printf("��ȡsrcImage1����~�� \n"); 
//		return false; 
//	}
//	if (!logoImage.data) { 
//		printf("��ȡlogoImage����~�� \n");
//		return false; 
//	}
//
//	// ��2������һ��Mat���Ͳ������趨ROI����
//	Mat imageROI = srcImage1(Rect(200, 250, logoImage.cols, logoImage.rows));
//
//	// ��3��������ģ�������ǻҶ�ͼ��
//	Mat mask = imread("./5_2/dota_logo.jpg", 0);
//
//	//��4������Ĥ������ROI
//	logoImage.copyTo(imageROI, mask);
//
//	// ��5����ʾ���
//	namedWindow("<1>����ROIʵ��ͼ�����ʾ������");
//	imshow("<1>����ROIʵ��ͼ�����ʾ������", srcImage1);
//	
//	return true;
//}
//
//
////---------------------------------��LinearBlending����������-------------------------------------
//// ��������LinearBlending����
//// ����������cv::addWeighted��������ʵ��ͼ�����Ի��
////--------------------------------------------------------------------------------------------
//bool LinearBlending() {
//	double alphaValue = 0.5;
//	double betaValue;
//	Mat srcImage2, srcImage3, dstImage;
//	srcImage2 = imread("./5_2/mogu.jpg");
//	srcImage3 = imread("./5_2/rain.jpg");
//	if (!srcImage2.data) {
//		printf("��ȡmogu.jpg����~�� \n");
//		return false;
//	}
//	if (!srcImage3.data) {
//		printf("��ȡrain.jpg����~�� \n");
//		return false;
//	}
//	betaValue = 1.0 - alphaValue;
//	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);
//	
//	namedWindow("ԭͼ", 1);
//	imshow("ԭͼ", srcImage2);
//
//	namedWindow("Ч��ͼ", 1);
//	imshow("Ч��ͼ", dstImage);
//	
//	return true;
//}
//
////ROI_LnearBlending()
//bool ROI_Linearblending() {
//	Mat srcImage4 = imread("./5_2/dota_pa.jpg", 1);
//	Mat logoImage = imread("./5_2/dota_logo.jpg");
//	if (!srcImage4.data)
//	{
//		printf("pa load error");
//		return false;
//	}
//	if (!logoImage.data)
//	{
//		printf("logo load error");
//		return false;
//	}
//	Mat imageROI;
//
//	imageROI = srcImage4(Rect(200, 250, logoImage.cols, logoImage.rows));
//	addWeighted(imageROI, 0.5, logoImage, 0.3, 0.0, imageROI);
//	
//	namedWindow("��������ͼ����");
//	imshow("��������ͼ����", srcImage4);
//	return true;
//}
//int main() {
//	if (LinearBlending()&&ROI_AddImage()&&ROI_Linearblending())
//	{
//		cout << "success" << endl;
//	}
//	else {
//		cout << "fail" << endl;
//	}
//	waitKey(0);
//	return 0;
//}