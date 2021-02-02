#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
Point ptOld;	// on_mouse()에서 이전 마우스 이벤트 발생 위치를 저장하기 위한 용도로 pt0ld 변수를 전역 변수 형태로 선언함

void on_mouse(int event, int x, int y, int flags, void*);

int main(void)
{
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// setMouseCallback()을 사용하기 전에 마우스 이벤트를 받을 창이 미리 생성되어 있어야 함.
	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);
	waitKey();

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*)
{
	switch (event) {
	case EVENT_LBUTTONDOWN:
		ptOld = Point(x, y);
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;	// 마우스 왼쪽 버튼이 눌린 좌표를 콘솔 창에 출력
		break;
	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;	// 마우스 왼쪽 버튼이 떼어진 좌표를 콘솔 창에 출력
		break;
	case EVENT_MOUSEMOVE:
	// 마우스가 움직이는 경우, 마우스 왼쪽 버튼이 눌려있는 상태라면 img 영상 위에 노란색 직선을 이어 그림.
	// 직선은 pt0ld좌표부터 현재 마우스 이벤트 발생 좌표까지 그리며, 직선을 그리고 난 후에는 현재 마우스 이벤트 발생 좌표를 ptOld에 저장함
		if (flags & EVENT_FLAG_LBUTTON) {
		// 사용자가 마우스 왼쪽 버튼을 누른 상태에서 마우스를 움직일 때 실행되는 코드 블록
			line(img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
			imshow("img", img);
			ptOld = Point(x, y);
		}
		break;
	default:
		break;
	}
}