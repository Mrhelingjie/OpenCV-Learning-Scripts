//#include<iostream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
//
////ȫ�ֺ�������
//void colorReduce(Mat& inputImage, Mat& outputImage, int div);
//
//int main() {
//	Mat srcImage = imread("./5_1/1.jpg");
//	imshow("ԭʼͼ��", srcImage);
//
//	Mat dstImage;
//	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());
//
//	double time0 = static_cast<double>(getTickCount());
//	colorReduce(srcImage, dstImage, 32);
//	time0 = ((double)getTickCount() - time0) / getTickFrequency();
//	cout << "����ʱ��" << time0 << endl;
//	imshow("Ч��ͼ", dstImage);
//	waitKey(0);
//	return 0;
//}
//
//
////����һ
//void colorReduce(Mat& inputImage, Mat& outputImage, int div) {
//	
//	outputImage = inputImage.clone();
//	int rowNumber = outputImage.rows;
//	//����Ϊͼ������*ͨ����
//	int colNumber = outputImage.cols * outputImage.channels();
//
//	for (int i = 0; i < rowNumber; i++)
//	{
//		//Mat��Ϊuchar�������� dataΪָ��outputImage��i�е��׵�ַ
//		uchar* data = outputImage.ptr<uchar>(i);
//		for (int j = 0; j < colNumber; j++)
//		{
//			data[j] = data[j] / div * div + div / 2;
//		}
//	}
//}

////������
//void colorReduce(Mat& inputImage, Mat& outputImage, int div) {
//
//	outputImage = inputImage.clone();
//	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
//	for (; it!=outputImage.end<Vec3b>();it++)
//	{
//		(*it)[0] = (*it)[0] / div * div + div / 2;
//		(*it)[1] = (*it)[1] / div * div + div / 2;
//		(*it)[2] = (*it)[2] / div * div + div / 2;
//
//	}
//}
//
////������
//void colorReduce(Mat& inputImage, Mat& outputImage, int div) {
//
//	outputImage = inputImage.clone();
//	
//	int rowNumber = outputImage.rows;
//	int colNumber = outputImage.cols;
//
//	for (int i = 0; i < rowNumber; i++)
//	{
//		for (int j = 0; j < colNumber; j++)
//		{
//			//��ɫ
//			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
//			//��ɫ
//			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;
//			//��ɫ
//			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;
//			//BGR
//		}
//	}
//}