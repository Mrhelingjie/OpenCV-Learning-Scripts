//#include<opencv2/imgproc/imgproc.hpp>
//#include<opencv2/highgui/highgui.hpp>
//using namespace cv;
//
//#define WINDOW_NAME_SRC "原始图"
//
//Mat g_srcImage, g_hsvImage, g_hueImage;
//int g_bins = 30;//直方图组距
//
//void on_BinChange(int, void*);
//
//int main() {
//	g_srcImage = imread("./9-4/1.jpg", 1);
//	if (!g_srcImage.data)
//	{
//		printf("load error");
//		return 0;
//	}
//	cvtColor(g_srcImage, g_hsvImage, COLOR_BGR2HSV);
//
//	g_hueImage.create(g_hsvImage.size(), g_hsvImage.depth());
//	int ch[] = { 0,0 };
//	mixChannels(&g_hsvImage, 1, &g_hueImage, 1, ch, 1);
//
//	namedWindow(WINDOW_NAME_SRC, WINDOW_AUTOSIZE);
//	createTrackbar("色调组距", WINDOW_NAME_SRC, &g_bins, 180, on_BinChange);
//	on_BinChange(0, 0);
//	
//	imshow(WINDOW_NAME_SRC, g_srcImage);
//	waitKey(0);
//	return 0;
//}
//void on_BinChange(int, void*) {
//	MatND hist;
//	int histSize = MAX(g_bins, 2);
//	float hue_range[] = { 0,180 };
//	const float* ranges = { hue_range };
//	
//	calcHist(&g_hueImage, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);
//	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());
//	
//	MatND backproj;
//	calcBackProject(&g_hueImage, 1, 0, hist, backproj, &ranges, 1, true);
//	imshow("反向投影", backproj);
//	int w = 400; int h = 400;
//	int bin_w = cvRound((double)w / histSize);
//	Mat histImg = Mat::zeros(w, h, CV_8UC3);
//
//	for (int i = 0; i < g_bins; i++)
//	{
//		rectangle(
//			histImg, Point(i*bin_w, h), Point((i + 1)*bin_w, h - cvRound(hist.at<float>(i)*h / 255.0)),
//			Scalar(100, 123, 255), -1
//		);
//	}
//	imshow("直方图", histImg);
//}