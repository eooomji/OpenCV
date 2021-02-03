#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void time_inverse();

int main(void)
{
	time_inverse();

	return 0;
}

void time_inverse()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	TickMeter tm;	// TickMeter 클래스 객체 tm을 선언함
	tm.start();	// 시간 측정 시작

	// 영상의 모든 픽셀을 반전시킴
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
		}
	}
	
	tm.stop();	// 시간 측정 종료
	cout << "Image inverse took " << tm.getTimeMilli() << "ms." << endl;	// 측정된 시간을 콘솔 창에 출력
}
