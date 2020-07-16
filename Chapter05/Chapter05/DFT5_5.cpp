#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;


int main() {
	//��ͼ����ʾ
	Mat srcImage = imread("./5_5/1.jpg", 0);
	if (!srcImage.data)
	{
		cout << "load error" << endl;
		return 0;
	}
	imshow("ԭʼͼ��", srcImage);

	//�õ����Ų��ߣ�������
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);

	Mat padded;

	copyMakeBorder(
		srcImage,//ԭͼ��
		padded,//���ߺ�ͼ��
		0,//top��0������
		m - srcImage.rows,//bottom
		0,// left
		n - srcImage.cols,//right
		BORDER_CONSTANT,//�߽�����
		Scalar::all(0)//�߽�ֵ
	);
	//����ͨ���渴������
	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };

	Mat complexI;
	//��planesǰ����ͼ��ϲ���һ��
	merge(planes, 2, complexI);

	//�͵ظ���Ҷ�任
	dft(complexI, complexI);
	//������ ��ɵ�ͨ��
	split(complexI, planes);
	//�����ֵ ���浽planes[0]
	magnitude(planes[0], planes[1], planes[0]);
	//��ֵ����
	Mat magnitudeImage = planes[0];
	//�߶����� 
	magnitudeImage += Scalar::all(1);
	//����logֵ
	log(magnitudeImage, magnitudeImage);
	
	//��7�����к��طֲ�����ͼ����
	//���������л������У�����Ƶ�ײü�      
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
	//�������и���Ҷͼ���е����ޣ�ʹ��ԭ��λ��ͼ������  
	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;
	Mat q0(magnitudeImage, Rect(0, 0, cx, cy));   // ROI���������
	Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));  // ROI���������
	Mat q2(magnitudeImage, Rect(0, cy, cx, cy));  // ROI���������
	Mat q3(magnitudeImage, Rect(cx, cy, cx, cy)); // ROI���������
	//�������ޣ����������½��н�����
	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	//�������ޣ����������½��н�����
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	//��8����һ������0��1֮��ĸ���ֵ������任Ϊ���ӵ�ͼ���ʽ
	normalize(magnitudeImage, magnitudeImage, 0, 1, CV_MINMAX);

	//��9����ʾЧ��ͼ
	imshow("Ƶ�׷�ֵ", magnitudeImage);
	waitKey();

	return 0;
}

