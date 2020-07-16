//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
//int main() {
//	Mat srcImage, hsvImage;
//	srcImage = imread("./9-1/1.jpg");
//	// H               S           V
//	//������ɫλ��0-360    ���Ͷ�       ����
//	cvtColor(srcImage, hsvImage, COLOR_BGR2HSV);
//	//ɫ��ֱ��ͼֱ������
//	int hueBinNum = 30;
//	//���Ͷ�ֱ������
//	int saturationBinNum = 32;
//	int histSize[] = { hueBinNum,saturationBinNum };
//	
//	
//	//ɫ���仯��Χ0---179
//	float hueRanges[] = { 0,180 };
//	//���Ͷȷ�Χ
//	float saturationRanges[] = { 0,256 };
//	const float* ranges[] = { hueRanges,saturationRanges };
//
//	MatND dstHist;
//	//����0��1ͨ��
//	int channels[] = { 0,1 };
//	//����
//	calcHist(
//		&hsvImage,    //��������
//		1,            //�����������
//		channels,     //ͨ������
//		Mat(),        //��ʹ����Ĥ
//		dstHist,      //���Ŀ��ֱ��ͼ
//		2,            //������ֱ��ͼά��Ϊ2
//		histSize,     //ֱ��ͼ�ߴ�����
//		ranges,		  //ֱ��ͼ��Χ
//		true,		  //ֱ��ͼ����
//		false		  //���ý׶�����
//	);
//	//����
//	double maxValue = 0;
//	minMaxLoc(dstHist, 0, &maxValue, 0, 0);
//	int scale = 10;
//	Mat histImg = Mat::zeros(saturationBinNum*scale, hueBinNum*scale, CV_8UC3);
//	for (int hue = 0; hue < hueBinNum; hue++)
//	{
//		for (int saturation = 0; saturation < saturationBinNum; saturation++)
//		{
//			float binValue = dstHist.at<float>(hue, saturation);
//			int intensity = cvRound(binValue * 255 / maxValue);
//			rectangle(
//				histImg,
//				Point(hue*scale, saturation*scale),
//				Point((hue + 1)*scale - 1, (saturation + 1)*scale - 1),
//				Scalar::all(intensity),
//				CV_FILLED
//			);
//		}
//	}
//	imshow("sucaitu", srcImage);
//	imshow("zhifangtu", histImg);
//	waitKey(0);
//	return 0;
//
//}
//int main() {
//	Mat srcImage = imread("./9-1/2.jpg", 0);
//	imshow("ԭͼ", srcImage);
//	if (!srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	MatND dstHist;
//	int dims = 1;
//	float hranges[] = { 0,255 };
//	const float* ranges[] = { hranges };
//	int size = 256;
//	int channels = 0;
//	calcHist(&srcImage, 1, &channels, Mat(), dstHist, dims, &size, ranges);    
//	
//	int scale = 1;
//	Mat dstImage(size*scale, size, CV_8U, Scalar(0));
//	double minValue = 0;
//	double maxValue = 0;
//	minMaxLoc(dstHist, &minValue, &maxValue, 0, 0);
//
//	int hpt = saturate_cast<int>(0.9*size);
//	for (int i = 0; i < 256; i++)
//	{
//		float binValue = dstHist.at<float>(i);
//		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
//		rectangle(dstImage, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realValue), Scalar(255));
//	}
//	imshow("һάֱ��ͼ", dstImage);
//	waitKey(0);
//	return 0;
//}
//
//
// RGB��ɫֱ��ͼ
//int main() {
//	Mat srcImage;
//	srcImage = imread("./9-1/3.jpg");
//	if (!srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	imshow("ԭʼͼ", srcImage);
//	int bins = 256;
//	int hist_size[] = { bins };
//	float range[] = { 0,256 };
//	const float* ranges[] = { range };
//
//	MatND redHist, blueHist, grayHist;
//
//	int channels_r[] = { 0 };
//	calcHist(
//		&srcImage,
//		1,
//		channels_r,
//		Mat(),
//		redHist,
//		1,
//		hist_size,
//		ranges,
//		true,
//		false
//	);
//	int channels_g[] = { 1 };
//	calcHist(
//		&srcImage,
//		1,
//		channels_g,
//		Mat(),
//		grayHist,
//		1,
//		hist_size,
//		ranges,
//		true,
//		false
//	);
//	int channels_b[] = { 2 };
//	calcHist(
//		&srcImage,
//		1,
//		channels_b,
//		Mat(),
//		blueHist,
//		1,
//		hist_size,
//		ranges,
//		true,
//		false
//	);
//
//	double maxValue_red, maxValue_green, maxValue_blue;
//
//	minMaxLoc(redHist, 0, &maxValue_red, 0, 0);
//	minMaxLoc(grayHist, 0, &maxValue_green, 0, 0);
//	minMaxLoc(blueHist, 0, &maxValue_blue, 0, 0);
//
//	int scale = 1;
//	int histHeight = 256;
//	Mat histImage = Mat::zeros(histHeight, bins * 3, CV_8UC3);
//
//	for (int i = 0; i < bins; i++)
//	{
//		float binValue_red = redHist.at<float>(i);
//		float binValue_green = grayHist.at<float>(i);
//		float binValue_blue = blueHist.at<float>(i);
//
//		int intensity_red = cvRound(binValue_red*histHeight / maxValue_red);
//		int intensity_green = cvRound(binValue_green*histHeight / maxValue_green);
//		int intensity_blue = cvRound(binValue_blue*histHeight / maxValue_blue);
//
//		rectangle(
//			histImage,
//			Point(i*scale, histHeight - 1),
//			Point((i + 1)*scale - 1, histHeight - intensity_red),
//			Scalar(255, 0, 0)
//		);
//		rectangle(
//			histImage,
//			Point((i + bins)*scale, histHeight - 1),
//			Point((i + bins + 1)*scale - 1, histHeight - intensity_green),
//			Scalar(0, 255, 0)
//		);
//		rectangle(
//			histImage,
//			Point((i + bins * 2)*scale, histHeight - 1),
//			Point((i + bins * 2 + 1)*scale - 1, histHeight - intensity_blue),
//			Scalar(0, 0, 255)
//		);
//	}
//	imshow("rgbֱ��ͼ", histImage);
//	waitKey(0);
//	return 0;
//}
//
//
//
//
//	