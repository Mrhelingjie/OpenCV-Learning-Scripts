#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
#define WINDOW_NAME "[线性混合示例]"
//
//全局变量
//
const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

//储存图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

//on_Trackbar()函数
//响应滑动条的回调函数
void on_Trackbar(int, void*) {
	//求滑动比例
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	//剩余
	g_dBetaValue = (1.0 - g_dAlphaValue);
	//混合
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
	imshow(WINDOW_NAME, g_dstImage);
}

int main(int argc,char** argv) {
	g_srcImage1 = imread("./3_2_1/1.jpg");
	g_srcImage2 = imread("./3_2_1/2.jpg");

	if (!g_srcImage1.data)
	{
		printf("1 error");
		return -1;
	}
	if (!g_srcImage2.data)
	{
		printf("2 error");
		return -1;
	}
	//滑动条初值
	g_nAlphaValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);

	char TrackbarName[50];
	sprintf(TrackbarName, "透明值%d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
	on_Trackbar(g_nAlphaValueSlider, 0);
	waitKey(0);
	return 0;




}