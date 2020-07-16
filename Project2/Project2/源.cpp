#include<opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include"opencv2/opencv.hpp"

using namespace cv;

int main() {
	//image show
	/*Mat img = imread("1.jpg");
	imshow("载入的图片",img);
	waitKey(0);*/
	//图像腐蚀
	/*Mat img = imread("1.jpg");
	imsuhow("原图-腐蚀", img);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(img, dstImage, element);
	imshow("效果图-腐蚀", dstImage);
	waitKey(0);*/
	//图像模糊
	/*Mat srcImage = imread("1.jpg");
	imshow("原图-均值滤波", srcImage);
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));
	imshow("效果图-均值滤波", dstImage);
	waitKey(0);*/
	//canny 边缘检测
	/*Mat srcImage = imread("1.jpg");
	Mat dstImage, edge, grayImage;
	dstImage.create(srcImage.size(), srcImage.type());
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	blur(grayImage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("效果", edge);
	waitKey(0);*/
	//读取视频----文件名
	//使用摄像头--0
	/*VideoCapture capture(0);
	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("读取视频", frame);
		waitKey(30);

	}*/
	printf(CV_VERSION);
	VideoCapture capture(0);
	Mat edges;
	while (true)
	{
		//读入图像
		Mat frame;
		//读取当前帧
		capture >> frame;
		//转换为灰度
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		//降噪
		blur(edges, edges, Size(7, 7));
		//canny边缘检测并显示
		Canny(edges, edges, 0, 30, 3);

		imshow("读取视频", edges);
		if(waitKey(30)>=0)break;

	}
	return 0;



}