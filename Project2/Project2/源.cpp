#include<opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include"opencv2/opencv.hpp"

using namespace cv;

int main() {
	//image show
	/*Mat img = imread("1.jpg");
	imshow("�����ͼƬ",img);
	waitKey(0);*/
	//ͼ��ʴ
	/*Mat img = imread("1.jpg");
	imsuhow("ԭͼ-��ʴ", img);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(img, dstImage, element);
	imshow("Ч��ͼ-��ʴ", dstImage);
	waitKey(0);*/
	//ͼ��ģ��
	/*Mat srcImage = imread("1.jpg");
	imshow("ԭͼ-��ֵ�˲�", srcImage);
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));
	imshow("Ч��ͼ-��ֵ�˲�", dstImage);
	waitKey(0);*/
	//canny ��Ե���
	/*Mat srcImage = imread("1.jpg");
	Mat dstImage, edge, grayImage;
	dstImage.create(srcImage.size(), srcImage.type());
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	blur(grayImage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("Ч��", edge);
	waitKey(0);*/
	//��ȡ��Ƶ----�ļ���
	//ʹ������ͷ--0
	/*VideoCapture capture(0);
	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("��ȡ��Ƶ", frame);
		waitKey(30);

	}*/
	printf(CV_VERSION);
	VideoCapture capture(0);
	Mat edges;
	while (true)
	{
		//����ͼ��
		Mat frame;
		//��ȡ��ǰ֡
		capture >> frame;
		//ת��Ϊ�Ҷ�
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		//����
		blur(edges, edges, Size(7, 7));
		//canny��Ե��Ⲣ��ʾ
		Canny(edges, edges, 0, 30, 3);

		imshow("��ȡ��Ƶ", edges);
		if(waitKey(30)>=0)break;

	}
	return 0;



}