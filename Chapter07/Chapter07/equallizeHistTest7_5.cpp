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
	imshow("原始图", srcImage);

	equalizeHist(srcImage, dstImage);
	imshow("效果图", dstImage);
	waitKey(0);
	return 0;
}