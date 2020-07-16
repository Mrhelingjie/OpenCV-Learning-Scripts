#include<opencv2/opencv.hpp>
using namespace cv;



#define WINDOW_WIDTH 600
#define WINDOW_NAME1 "绘制图1"
#define WINDOW_NAME2 "绘制图2"




//DrawEllipse() 画椭圆
void DrawEllipse(Mat img, double angle) {
	int thickness = 2;
	int lineType = 8;
	// ellipse 将椭圆画到img图像上
	ellipse(img,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),
		angle, //旋转角度
		0,
		360,
		Scalar(255, 129, 0),//颜色为蓝色
		thickness,//线宽
		lineType//线型
	);
}


//DrawFilledCircle() 画圆
void DrawFilledCircle(Mat img,Point center) {
	int thickness = -1;//此时圆为实心
	int lineType = 8;
	circle(
		img,
		center,
		WINDOW_WIDTH / 32,//半径
		Scalar(0, 0, 255),
		thickness,
		lineType
	);
}

//DrawPolygon() 画多边形
void DrawPolygon(Mat img) {
	int lineType = 8;
	Point rookPoints[1][20];
	rookPoints[0][0] = Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][1] = Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][2] = Point(3 * WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][3] = Point(11 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][4] = Point(19 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][5] = Point(3 * WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][6] = Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][7] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][8] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][9] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][10] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][11] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][12] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][13] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][14] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][15] = Point(WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][16] = Point(WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][17] = Point(13 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][18] = Point(5 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][19] = Point(WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);

	const Point* ppt[1] = { rookPoints[0] };//顶点集合
	int npt[] = { 20 };//点的数目
	fillPoly(
		img,
		ppt,
		npt,
		1,//多边形数量
		Scalar(255, 255, 255),
		lineType
	);

}

//DrawLine() 画线
void DrawLine(Mat img,Point start, Point end) {
	int thickness = 2;
	int lineType = 8;
	line(
		img,
		start,
		end,
		Scalar(0, 0, 0),
		thickness,
		lineType
	);
}

//main 
int main() {
	//创建空白图像
	Mat atoImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	
	//环绕的椭圆
	DrawEllipse(atoImage, 90);
	DrawEllipse(atoImage, 0);
	DrawEllipse(atoImage, 45);
	DrawEllipse(atoImage, -45);
	
	//圆心
	DrawFilledCircle(atoImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));

	//绘制椭圆
	DrawPolygon(rookImage);
	rectangle(
		rookImage,
		Point(0, 7 * WINDOW_WIDTH / 8),
		Point(WINDOW_WIDTH, WINDOW_WIDTH),
		Scalar(0, 255, 255),
		-1,
		8
	);

	DrawLine(rookImage, Point(0, 15 * WINDOW_WIDTH / 16), Point(WINDOW_WIDTH, 15 * WINDOW_WIDTH / 16));
	DrawLine(rookImage, Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 4, WINDOW_WIDTH));
	DrawLine(rookImage, Point(WINDOW_WIDTH / 2, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 2, WINDOW_WIDTH));
	DrawLine(rookImage, Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8), Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH));



	//显示图像
	imshow(WINDOW_NAME1, atoImage);
	moveWindow(WINDOW_NAME1, 0, 200);
	imshow(WINDOW_NAME2, rookImage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);
	
	waitKey(0);
	return 0;
}