#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;	// Mat�� imread, nameWindow, imshow, waitkey

int main() {
	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img;
	img = imread("lenna.bmp");	// imread() �Լ� : ���� �б�

	if (img.empty()) {	// lenna.bmp�� ����� �ҷ����� ������ ��쿡 ���� ���� ó�� �ڵ�
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image");	// namedWindow() : ������ ȭ�鿡 ��Ÿ���� ���� ���ο� â�� ����, �� â �̸� "image"
	imshow("image", img);	// imshow() : ���� ���� �ֱ�(image show)

	waitKey();	// waitKey() : ������� Ű���� �Է��� ��ٸ��� �Լ�. ����ڰ� Ű���带 ������ ������ ������ ȭ�鿡 ��Ÿ���� ����
				//			   ���� ����ڰ� Ű���忡�� �ƹ� Ű�� ������ 19���� �������� �ǰ�, 20���� return ������ ���� ���α׷��� �����
	return 0;
}