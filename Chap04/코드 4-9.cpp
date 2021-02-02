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

	Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);	// 출력할 문자열이 차지할 사각형 영역의 크기를 구하여 sizeText에 저장
	Size sizeImg = img.size();	// 출력할 대상 영상 크기를 sizeImg 변수에 저장

	// sizeText와 sizeImg 크기 정보를 이용하여 문자열을 출력할 좌표를 계산함
	Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);

	// 실제 문자열을 출력하고 문자열을 감싸는 사각형을 그림
	putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
	rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(0, 255, 0), 1);

	imshow("img", img);
	waitKey();

	destroyAllWindows();
}