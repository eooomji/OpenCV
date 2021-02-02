#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	Mat img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	imshow("img", img);

	while (true) {
		int keycode = waitKey();	// waitKey()의 반환값을 keycode 변수에 저장

		if (keycode == 'i' || keycode == 'I') {	// 키보드의 i or I 키를 누르면
			img = ~img;							// img 영상을 반전하여
			imshow("img", img);					// "img" 창에 나타냄
		}
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q') {
			break;
		}
	}

	return 0;
}