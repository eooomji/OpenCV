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
		int keycode = waitKey();	// waitKey()�� ��ȯ���� keycode ������ ����

		if (keycode == 'i' || keycode == 'I') {	// Ű������ i or I Ű�� ������
			img = ~img;							// img ������ �����Ͽ�
			imshow("img", img);					// "img" â�� ��Ÿ��
		}
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q') {
			break;
		}
	}

	return 0;
}