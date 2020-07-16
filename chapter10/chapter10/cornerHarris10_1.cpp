#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

#define WINDOW_NAME1 "���򴰿�1"
#define WINDOW_NAME2 "���򴰿�2"
#define WINDOW_NAME_GOOD "shi-tomasi�ǵ���"
//harris
//Mat g_srcImage, g_srcImage1, g_grayImage;
//int thresh = 30;
//int max_thresh = 175;

//shi-tomasi
Mat g_srcImage, g_grayImage;
int g_maxCornerNumber = 33;
int g_maxTrackbarNumber = 500;
RNG g_rng(12345);


void on_CornerHarris(int, void*);
void on_GoodFeaturesToTrack(int, void*);
int main() {
	
	g_srcImage = imread("./10-1/1.jpg", 1);
	if (!g_srcImage.data)
	{
		printf("load error");
		return 0;
	}
	//g_srcImage1 = g_srcImage.clone();
	//// ����һ�ŻҶ�ͼ
	//cvtColor(g_srcImage1, g_grayImage, COLOR_BGR2GRAY);
	//namedWindow(WINDOW_NAME1, WINDOW_AUTOSIZE);
	//createTrackbar("��ֵ", WINDOW_NAME1, &thresh, max_thresh, on_CornerHarris);
	//on_CornerHarris(0, 0);
	//waitKey(0);
	//return 0;
	
	
	cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);

	namedWindow(WINDOW_NAME_GOOD, WINDOW_AUTOSIZE);
	createTrackbar("���ǵ���", WINDOW_NAME_GOOD, &g_maxCornerNumber, g_maxTrackbarNumber,on_GoodFeaturesToTrack);
	imshow(WINDOW_NAME_GOOD, g_srcImage);
	on_GoodFeaturesToTrack(0, 0);
	waitKey(0);
	return 0;
}

//void on_CornerHarris(int, void *)
//{
//	Mat dstImage;//Ŀ��ͼ
//	Mat normImage;//��һ��ͼ
//	Mat scaledImage;//���Ա任���8λ�޷�������ͼ
//	//�����һ�ε���
//	dstImage = Mat::zeros(g_srcImage.size(), CV_32FC1);
//	g_srcImage1 = g_srcImage.clone();
//	//���
//	cornerHarris(g_grayImage, dstImage, 2, 3, 0.04, BORDER_DEFAULT);
//	// ��һ��
//	normalize(dstImage, normImage, 0, 255, NORM_MINMAX, CV_32FC1);
//	//ת��8λ�޷�������
//	convertScaleAbs(normImage, scaledImage);
//
//	//����
//	for (int j = 0; j < normImage.rows; j++)
//	{
//		for (int i = 0; i < normImage.cols; i++)
//		{
//			if ((int)normImage.at<float>(j,i)>thresh+80)
//			{
//				circle(g_srcImage1, Point(i, j), 5, Scalar(10, 10, 255), 2, 8, 0);
//				circle(scaledImage, Point(i, j), 5, Scalar(0, 10, 255), 2, 8, 0);
//
//			}
//		}
//	}
//	imshow(WINDOW_NAME1, g_srcImage1);
//	imshow(WINDOW_NAME2, scaledImage);
//}

void on_GoodFeaturesToTrack(int, void *)
{
	if (g_maxCornerNumber<=1)
	{
		g_maxCornerNumber = 1;
	}
	//����׼��
	vector<Point2f> corners;
	double qualityLevel = 0.01;
	double minDistance = 10;
	int blockSize = 3;
	double k = 0.04;
	Mat copy = g_srcImage.clone();

	goodFeaturesToTrack(
		g_grayImage,
		corners,
		g_maxCornerNumber,
		qualityLevel,
		minDistance,
		Mat(),
		blockSize,
		false,
		k
	);
	cout << "�˴μ�⵽�Ľǵ�����Ϊ" << corners.size() << endl;

	int r = 4;
	for (unsigned int i = 0; i < corners.size(); i++)
	{
		Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
		circle(copy, corners[i], r, color, -1, 8, 0);
	}
	imshow(WINDOW_NAME_GOOD, copy);

	//�����ؽǵ���

	Size winSize = Size(5, 5);
	Size zeroSize = Size(-1, -1);
	TermCriteria criteria = TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 40, 0.001);

	cornerSubPix(g_grayImage, corners, winSize, zeroSize, criteria);

	for (size_t i = 0; i < corners.size(); i++)
	{
		cout << " \t>>��ȷ�ǵ�����[" << i << "]  (" << corners[i].x << "," << corners[i].y << ")" << endl;
	}
}
