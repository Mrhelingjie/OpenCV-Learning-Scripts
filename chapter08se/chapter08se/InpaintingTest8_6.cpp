#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/photo/photo.hpp>
#include<iostream>
using namespace cv;
using namespace std;

#define WINDOW_NAME_SRC "原始图"
#define WINDOW_NAME_DST "效果图"

Mat g_srcImage, g_inpaintMask;
Point previousPoint(-1, -1);

static void on_Mouse(int event,int x,int y,int flags,void*) {
	
	if (event ==EVENT_LBUTTONUP||!(flags&EVENT_FLAG_LBUTTON))
	{
		previousPoint = Point(-1, -1);
	}
	else if (event == EVENT_LBUTTONDOWN)
	{
		previousPoint = Point(x, y);
	}
	else if (event ==EVENT_MOUSEMOVE&&(flags&EVENT_FLAG_LBUTTON))
	{
		Point pt(x, y);
		if (previousPoint.x<0)
		{
			previousPoint = pt;
		}
		line(g_inpaintMask, previousPoint, pt, Scalar::all(255), 5, 8, 0);
		line(g_srcImage, previousPoint, pt, Scalar::all(255), 5, 8, 0);
		previousPoint = pt;
		imshow(WINDOW_NAME_SRC, g_srcImage);
	}
}

int main() {
	Mat srcImage = imread("./8-6/1.jpg", -1);
	if (!srcImage.data)
	{
		printf("load error");
		return 0;
	}
	srcImage.copyTo(g_srcImage);

	g_inpaintMask = Mat::zeros(g_srcImage.size(), CV_8U);
	imshow(WINDOW_NAME_SRC, g_srcImage);

	setMouseCallback(WINDOW_NAME_SRC, on_Mouse, 0);
	while (true)
	{
		char c = (char)waitKey();
		if (c == 27)break;
		if (c=='2')
		{
			g_inpaintMask = Scalar::all(0);
			srcImage.copyTo(g_srcImage);
			imshow(WINDOW_NAME_SRC, g_srcImage);
		}
		if (c=='1'||c==' ')
		{
			Mat inpaintedImage;
			inpaint(g_srcImage, g_inpaintMask, inpaintedImage, 3, INPAINT_TELEA);
			imshow(WINDOW_NAME_DST, inpaintedImage);
		}
	}
}