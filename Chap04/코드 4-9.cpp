#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawText2();

int main(void)
{
	drawText2();

	return 0;
}

void drawText2()
{
	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));

	const String text = "Hello, OpenCV";
	int fontFace = FONT_HERSHEY_TRIPLEX;
	double fontScale = 2.0;
	int thickness = 1;

	Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);	// ����� ���ڿ��� ������ �簢�� ������ ũ�⸦ ���Ͽ� sizeText�� ����
	Size sizeImg = img.size();	// ����� ��� ���� ũ�⸦ sizeImg ������ ����

	// sizeText�� sizeImg ũ�� ������ �̿��Ͽ� ���ڿ��� ����� ��ǥ�� �����
	Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);

	// ���� ���ڿ��� ����ϰ� ���ڿ��� ���δ� �簢���� �׸�
	putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
	rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(0, 255, 0), 1);

	imshow("img", img);
	waitKey();

	destroyAllWindows();
}