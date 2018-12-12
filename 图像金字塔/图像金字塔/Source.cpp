#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int agrc, char** argv){
	// 图像金字塔

	// 读取图像
	Mat src = imread("D:/OpenCVProject/day1212/图像金字塔/图像金字塔/test.jpg");
	imshow("origin image", src);

	// 上采样
	/*
		pyrUp(Mat src, Mat dst, Size(src.cols*2, src.rows*2)) 		生成的图像是原图在宽与高各放大两倍
	*/
	Mat up_img;
	pyrUp(src, up_img, Size(src.cols * 2, src.rows * 2));
	//imshow("up_img", up_img);

	// 降采样
	/*
		pyrDown(Mat src, Mat dst, Size(src.cols/2, src.rows/2))		生成的图像是原图在宽与高各缩小1/2
	*/
	Mat down_img;
	pyrDown(src, down_img, Size(src.cols / 2, src.rows / 2));
	//imshow("down_img", down_img);

	// DOG高斯不同  就是把同一张图像在不同的参数下做高斯模糊之后的结果相减，得到的输出图像。称为高斯不同(DOG)，高斯不同是图像的内在特征，在灰度图像增强、角点检测中经常用到。
	Mat gray_img, g1, g2, final_img;
	cvtColor(src, gray_img, CV_BGR2GRAY);
	GaussianBlur(gray_img, g1, Size(5, 5), 0, 0);
	GaussianBlur(g1, g2, Size(5, 5), 0, 0);
	// 图像像素相减
	subtract(g2, g1, final_img, Mat());

	// 归一化显示
	normalize(final_img, final_img, 0, 255, NORM_MINMAX);
	imshow("final_img", final_img);

	waitKey(0);
	return 0;
}