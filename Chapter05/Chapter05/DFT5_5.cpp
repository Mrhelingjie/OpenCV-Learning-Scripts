#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;


int main() {
	//读图并显示
	Mat srcImage = imread("./5_5/1.jpg", 0);
	if (!srcImage.data)
	{
		cout << "load error" << endl;
		return 0;
	}
	imshow("原始图像", srcImage);

	//得到最优补边，并补边
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);

	Mat padded;

	copyMakeBorder(
		srcImage,//原图像
		padded,//补边后图像
		0,//top补0个像素
		m - srcImage.rows,//bottom
		0,// left
		n - srcImage.cols,//right
		BORDER_CONSTANT,//边界类型
		Scalar::all(0)//边界值
	);
	//增加通道存复数部分
	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };

	Mat complexI;
	//将planes前两个图像合并在一起
	merge(planes, 2, complexI);

	//就地傅里叶变换
	dft(complexI, complexI);
	//分离结果 组成单通道
	split(complexI, planes);
	//计算幅值 并存到planes[0]
	magnitude(planes[0], planes[1], planes[0]);
	//幅值矩阵
	Mat magnitudeImage = planes[0];
	//尺度缩放 
	magnitudeImage += Scalar::all(1);
	//计算log值
	log(magnitudeImage, magnitudeImage);
	
	//【7】剪切和重分布幅度图象限
	//若有奇数行或奇数列，进行频谱裁剪      
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
	//重新排列傅立叶图像中的象限，使得原点位于图像中心  
	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;
	Mat q0(magnitudeImage, Rect(0, 0, cx, cy));   // ROI区域的左上
	Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));  // ROI区域的右上
	Mat q2(magnitudeImage, Rect(0, cy, cx, cy));  // ROI区域的左下
	Mat q3(magnitudeImage, Rect(cx, cy, cx, cy)); // ROI区域的右下
	//交换象限（左上与右下进行交换）
	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	//交换象限（右上与左下进行交换）
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	//【8】归一化，用0到1之间的浮点值将矩阵变换为可视的图像格式
	normalize(magnitudeImage, magnitudeImage, 0, 1, CV_MINMAX);

	//【9】显示效果图
	imshow("频谱幅值", magnitudeImage);
	waitKey();

	return 0;
}

