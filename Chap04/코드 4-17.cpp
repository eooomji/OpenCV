#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void mask_copyTo();


int main(void)
{
	mask_copyTo();

	return 0;
}


void mask_copyTo()
{
	Mat src = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// mask 영상에서 흰색 영역 위치에서만 src 영상 픽셀 값을 dst로 복사함
	src.copyTo(dst, mask);

	imshow("src", src);
	imshow("dst", dst);
	imshow("mask", mask);

	waitKey(0);
	destroyAllWindows();
}