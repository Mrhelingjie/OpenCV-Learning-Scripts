//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//
//
////----------------------------------【ROI_AddImage( )函数】----------------------------------
//// 函数名：ROI_AddImage（）
////	描述：利用感兴趣区域ROI实现图像叠加
////----------------------------------------------------------------------------------------------
//bool  ROI_AddImage()
//{
//	// 【1】读入图像
//	Mat srcImage1 = imread("./5_2/dota_pa.jpg");
//	Mat logoImage = imread("./5_2/dota_logo.jpg");
//	if (!srcImage1.data) { 
//		printf("读取srcImage1错误~！ \n"); 
//		return false; 
//	}
//	if (!logoImage.data) { 
//		printf("读取logoImage错误~！ \n");
//		return false; 
//	}
//
//	// 【2】定义一个Mat类型并给其设定ROI区域
//	Mat imageROI = srcImage1(Rect(200, 250, logoImage.cols, logoImage.rows));
//
//	// 【3】加载掩模（必须是灰度图）
//	Mat mask = imread("./5_2/dota_logo.jpg", 0);
//
//	//【4】将掩膜拷贝到ROI
//	logoImage.copyTo(imageROI, mask);
//
//	// 【5】显示结果
//	namedWindow("<1>利用ROI实现图像叠加示例窗口");
//	imshow("<1>利用ROI实现图像叠加示例窗口", srcImage1);
//	
//	return true;
//}
//
//
////---------------------------------【LinearBlending（）函数】-------------------------------------
//// 函数名：LinearBlending（）
//// 描述：利用cv::addWeighted（）函数实现图像线性混合
////--------------------------------------------------------------------------------------------
//bool LinearBlending() {
//	double alphaValue = 0.5;
//	double betaValue;
//	Mat srcImage2, srcImage3, dstImage;
//	srcImage2 = imread("./5_2/mogu.jpg");
//	srcImage3 = imread("./5_2/rain.jpg");
//	if (!srcImage2.data) {
//		printf("读取mogu.jpg错误~！ \n");
//		return false;
//	}
//	if (!srcImage3.data) {
//		printf("读取rain.jpg错误~！ \n");
//		return false;
//	}
//	betaValue = 1.0 - alphaValue;
//	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);
//	
//	namedWindow("原图", 1);
//	imshow("原图", srcImage2);
//
//	namedWindow("效果图", 1);
//	imshow("效果图", dstImage);
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
//	namedWindow("区域线性图像混合");
//	imshow("区域线性图像混合", srcImage4);
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