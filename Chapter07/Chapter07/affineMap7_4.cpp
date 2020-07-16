//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;
//
//#define WINDOW_NAME_SRC "原始图窗口"
//#define WINDOW_NAME_WRAP "经过warp后图像窗口"
//#define WINDOW_NAME_WARPANDROTATE "经过warp和rotate窗口"
//
//int main() {
//	//定义两组点，代表两个三角形
//	Point2f srcTriangle[3];
//	Point2f dstTriangle[3];
//
//	Mat rotMat(2, 3, CV_32FC1);
//	Mat warpMat(2, 3, CV_32FC1);
//	Mat srcImage, dstImage_warp, dstImage_warp_rotate;
//
//	srcImage = imread("./7-4/1.jpg");
//	if (!srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	dstImage_warp = Mat::zeros(srcImage.rows, srcImage.cols, srcImage.type());
//	srcTriangle[0] = Point2f(0, 0);
//	srcTriangle[1] = Point2f(static_cast<float>(srcImage.cols - 1), 0);
//	srcTriangle[2] = Point2f(0, static_cast<float>(srcImage.rows - 1));
//
//	dstTriangle[0] = Point2f(static_cast<float>(srcImage.cols*0.0), static_cast<float>(srcImage.rows*0.33));
//	dstTriangle[1] = Point2f(static_cast<float>(srcImage.cols*0.65), static_cast<float>(srcImage.rows*0.35));
//	dstTriangle[2] = Point2f(static_cast<float>(srcImage.cols*0.15), static_cast<float>(srcImage.rows*0.6));
//
//	warpMat = getAffineTransform(srcTriangle, dstTriangle);
//	warpAffine(srcImage, dstImage_warp, warpMat, dstImage_warp.size());
//
//	Point center = Point(dstImage_warp.cols / 2, dstImage_warp.rows / 2);
//	double angle = -30.0;
//	double scale = 0.8;
//	rotMat = getRotationMatrix2D(center, angle, scale);
//	warpAffine(dstImage_warp, dstImage_warp_rotate, rotMat, dstImage_warp.size());
//
//
//	imshow(WINDOW_NAME_SRC, srcImage);
//	imshow(WINDOW_NAME_WRAP, dstImage_warp);
//	imshow(WINDOW_NAME_WARPANDROTATE, dstImage_warp_rotate);
//
//	waitKey(0);
//	return 0;
//
//
//}