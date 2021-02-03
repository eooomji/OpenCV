#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void mask_setTo();

int main(void)
{
	mask_setTo();

	return 0;
}

void mask_setTo()
{
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);	// ����ũ ������ mask ������ ������

	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// mask ���󿡼� �ȼ� ���� 0�� �ƴ� ��ġ������ src ���� �ȼ��� ��������� ������
	src.setTo(Scalar(0, 255, 255), mask);

	imshow("src", src);
	imshow("mask", mask);

	waitKey(0);
	destroyAllWindows();
}