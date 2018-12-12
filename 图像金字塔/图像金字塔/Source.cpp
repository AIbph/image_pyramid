#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int agrc, char** argv){
	// ͼ�������

	// ��ȡͼ��
	Mat src = imread("D:/OpenCVProject/day1212/ͼ�������/ͼ�������/test.jpg");
	imshow("origin image", src);

	// �ϲ���
	/*
		pyrUp(Mat src, Mat dst, Size(src.cols*2, src.rows*2)) 		���ɵ�ͼ����ԭͼ�ڿ���߸��Ŵ�����
	*/
	Mat up_img;
	pyrUp(src, up_img, Size(src.cols * 2, src.rows * 2));
	//imshow("up_img", up_img);

	// ������
	/*
		pyrDown(Mat src, Mat dst, Size(src.cols/2, src.rows/2))		���ɵ�ͼ����ԭͼ�ڿ���߸���С1/2
	*/
	Mat down_img;
	pyrDown(src, down_img, Size(src.cols / 2, src.rows / 2));
	//imshow("down_img", down_img);

	// DOG��˹��ͬ  ���ǰ�ͬһ��ͼ���ڲ�ͬ�Ĳ���������˹ģ��֮��Ľ��������õ������ͼ�񡣳�Ϊ��˹��ͬ(DOG)����˹��ͬ��ͼ��������������ڻҶ�ͼ����ǿ���ǵ����о����õ���
	Mat gray_img, g1, g2, final_img;
	cvtColor(src, gray_img, CV_BGR2GRAY);
	GaussianBlur(gray_img, g1, Size(5, 5), 0, 0);
	GaussianBlur(g1, g2, Size(5, 5), 0, 0);
	// ͼ���������
	subtract(g2, g1, final_img, Mat());

	// ��һ����ʾ
	normalize(final_img, final_img, 0, 255, NORM_MINMAX);
	imshow("final_img", final_img);

	waitKey(0);
	return 0;
}