#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

#define WINDOW_NAME_SRC "原始窗口"
#define WINDOW_NAME_DST "效果窗口"

Mat g_srcImage, g_templateImage, g_resultImage;
int g_nMatchMethod;
int g_nMaxTrackBarNum = 5;

void on_Matching(int, void*);

int main() {
	g_srcImage = imread("./9-5/1.jpg", 1);
	g_templateImage = imread("./9-5/2.jpg", 1);
	
	namedWindow(WINDOW_NAME_SRC, WINDOW_AUTOSIZE);
	namedWindow(WINDOW_NAME_DST, WINDOW_AUTOSIZE);

	createTrackbar("方法id", WINDOW_NAME_SRC, &g_nMatchMethod, g_nMaxTrackBarNum, on_Matching);
	on_Matching(0, 0);
	waitKey(0);
	return 0;
}

void on_Matching(int, void *)
{
	Mat srcImage;
	g_srcImage.copyTo(srcImage);

	int resultImage_cols = g_srcImage.cols - g_templateImage.cols + 1;
	int resultImage_rows = g_srcImage.rows - g_templateImage.rows + 1;
	g_resultImage.create(resultImage_cols, resultImage_rows, CV_32FC1);

	matchTemplate(g_srcImage, g_templateImage, g_resultImage, g_nMatchMethod);
	normalize(g_resultImage, g_resultImage, 0, 1, NORM_MINMAX, -1, Mat());

	double minValue, maxValue;
	Point minLocation, maxLocation;
	Point matchLocation;
	minMaxLoc(g_resultImage, &minValue, &maxValue, &minLocation, &maxLocation, Mat());


	if (g_nMatchMethod == CV_TM_SQDIFF || g_nMatchMethod == CV_TM_SQDIFF_NORMED)
	{
		matchLocation = minLocation;
	}
	else
	{
		matchLocation = maxLocation;
	}

	rectangle(
		srcImage, matchLocation,
		Point(matchLocation.x + g_templateImage.cols, matchLocation.y + g_templateImage.rows),
		Scalar(0, 0, 255), 2, 8, 0
	);

	rectangle(
		g_resultImage, matchLocation,
		Point(matchLocation.x + g_templateImage.cols, matchLocation.y + g_templateImage.rows),
		Scalar(0, 0, 255), 2, 8, 0
	);
	imshow(WINDOW_NAME_SRC, srcImage);
	imshow(WINDOW_NAME_DST, g_resultImage);
}
