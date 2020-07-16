#include<opencv2/opencv.hpp>

using namespace cv;

int main() {
	Mat srcImage, dstImage;
	srcImage = imread("./7-5/1.jpg");
	if (!srcImage.data)
	{
		printf("load error");
		return 0;
	}
	cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);
	imshow("ԭʼͼ", srcImage);

	equalizeHist(srcImage, dstImage);
	imshow("Ч��ͼ", dstImage);
	waitKey(0);
	return 0;
}