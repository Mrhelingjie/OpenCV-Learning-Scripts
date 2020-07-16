//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//using namespace cv;
//
//int main() {
//	//图像载入和显示
//	Mat girl = imread("./3_1_9/girl.jpg");
//	namedWindow("[1]动漫图");
//	imshow("[1]动漫图", girl);
//	//图像混合
//	Mat image = imread("./3_1_9/dota.jpg", 199);
//	Mat logo = imread("./3_1_9/dota_logo.jpg");
//	namedWindow("[2]原画图");
//	imshow("[2]原画图", image);
//	namedWindow("[3]原画图logo");
//	imshow("[3]原画图logo", logo);
//	
//	Mat imageROI;
//	imageROI = image(Rect(800, 350, logo.cols, logo.rows));
//	//方法二
//	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));
//	addWeighted(imageROI, 0.5, logo, 0.3, 0.0, imageROI);
//	namedWindow("[4]原画图+logo");
//	imshow("[4]原画图+logo", image);
//	//图像输出
//	imwrite("imwrite_create.jpg", image);
//	waitKey();
//
//	return 0;
//}