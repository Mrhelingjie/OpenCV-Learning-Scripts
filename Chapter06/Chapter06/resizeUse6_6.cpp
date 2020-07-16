//#include<opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//#define WINDOW_NAME "���򴰿�"
//
//Mat g_srcImage, g_dstImage, g_tmpImage;
//int main() {
//	g_srcImage = imread("./6-6/2.jpg");
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
//
//	imshow(WINDOW_NAME, g_srcImage);
//
//	g_srcImage.copyTo(g_tmpImage);
//	g_srcImage.copyTo(g_dstImage);
//	
//	int key = 0;
//	while (true)
//	{
//		key = waitKey(9);//��ȡ��ֵ��key������
//
//		//����key������ֵ�����в�ͬ�Ĳ���
//		switch (key)
//		{
//			//======================�������˳���ؼ�ֵ����=======================  
//		case 27://����ESC
//			return 0;
//			break;
//
//		case 'q'://����Q
//			return 0;
//			break;
//
//			//======================��ͼƬ�Ŵ���ؼ�ֵ����=======================  
//		case 'a'://����A���£�����pyrUp����
//			pyrUp(g_tmpImage, g_dstImage, Size(g_tmpImage.cols * 2, g_tmpImage.rows * 2));
//			printf(">��⵽������A�������£���ʼ���л��ڡ�pyrUp��������ͼƬ�Ŵ�ͼƬ�ߴ��2 \n");
//			break;
//
//		case 'w'://����W���£�����resize����
//			resize(g_tmpImage, g_dstImage, Size(g_tmpImage.cols * 2, g_tmpImage.rows * 2));
//			printf(">��⵽������W�������£���ʼ���л��ڡ�resize��������ͼƬ�Ŵ�ͼƬ�ߴ��2 \n");
//			break;
//
//		case '1'://����1���£�����resize����
//			resize(g_tmpImage, g_dstImage, Size(g_tmpImage.cols * 2, g_tmpImage.rows * 2));
//			printf(">��⵽������1�������£���ʼ���л��ڡ�resize��������ͼƬ�Ŵ�ͼƬ�ߴ��2 \n");
//			break;
//
//		case '3': //����3���£�����pyrUp����
//			pyrUp(g_tmpImage, g_dstImage, Size(g_tmpImage.cols * 2, g_tmpImage.rows * 2));
//			printf(">��⵽������3�������£���ʼ���л��ڡ�pyrUp��������ͼƬ�Ŵ�ͼƬ�ߴ��2 \n");
//			break;
//			//======================��ͼƬ��С��ؼ�ֵ����=======================  
//		case 'd': //����D���£�����pyrDown����
//			pyrDown(g_tmpImage, g_dstImage, Size(g_tmpImage.cols / 2, g_tmpImage.rows / 2));
//			printf(">��⵽������D�������£���ʼ���л��ڡ�pyrDown��������ͼƬ��С��ͼƬ�ߴ�/2\n");
//			break;
//
//		case  's': //����S���£�����resize����
//			resize(g_tmpImage, g_dstImage, Size(g_tmpImage.cols / 2, g_tmpImage.rows / 2));
//			printf(">��⵽������S�������£���ʼ���л��ڡ�resize��������ͼƬ��С��ͼƬ�ߴ�/2\n");
//			break;
//
//		case '2'://����2���£�����resize����
//			resize(g_tmpImage, g_dstImage, Size(g_tmpImage.cols / 2, g_tmpImage.rows / 2));
//			printf(">��⵽������2�������£���ʼ���л��ڡ�resize��������ͼƬ��С��ͼƬ�ߴ�/2\n");
//			break;
//
//		case '4': //����4���£�����pyrDown����
//			pyrDown(g_tmpImage, g_dstImage, Size(g_tmpImage.cols / 2, g_tmpImage.rows / 2));
//			printf(">��⵽������4�������£���ʼ���л��ڡ�pyrDown��������ͼƬ��С��ͼƬ�ߴ�/2\n");
//			break;
//		}
//
//		//������������ʾ�仯���ͼ
//		imshow(WINDOW_NAME, g_dstImage);
//
//		//��g_dstImage����g_tmpImage��������һ��ѭ��
//		g_tmpImage = g_dstImage;
//	}
//
//	return 0;
//}
