//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//using namespace cv;
//
//int main() {
//	//ͼ���������ʾ
//	Mat girl = imread("./3_1_9/girl.jpg");
//	namedWindow("[1]����ͼ");
//	imshow("[1]����ͼ", girl);
//	//ͼ����
//	Mat image = imread("./3_1_9/dota.jpg", 199);
//	Mat logo = imread("./3_1_9/dota_logo.jpg");
//	namedWindow("[2]ԭ��ͼ");
//	imshow("[2]ԭ��ͼ", image);
//	namedWindow("[3]ԭ��ͼlogo");
//	imshow("[3]ԭ��ͼlogo", logo);
//	
//	Mat imageROI;
//	imageROI = image(Rect(800, 350, logo.cols, logo.rows));
//	//������
//	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));
//	addWeighted(imageROI, 0.5, logo, 0.3, 0.0, imageROI);
//	namedWindow("[4]ԭ��ͼ+logo");
//	imshow("[4]ԭ��ͼ+logo", image);
//	//ͼ�����
//	imwrite("imwrite_create.jpg", image);
//	waitKey();
//
//	return 0;
//}