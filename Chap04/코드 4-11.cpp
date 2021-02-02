#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
Point ptOld;	// on_mouse()���� ���� ���콺 �̺�Ʈ �߻� ��ġ�� �����ϱ� ���� �뵵�� pt0ld ������ ���� ���� ���·� ������

void on_mouse(int event, int x, int y, int flags, void*);

int main(void)
{
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// setMouseCallback()�� ����ϱ� ���� ���콺 �̺�Ʈ�� ���� â�� �̸� �����Ǿ� �־�� ��.
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
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;	// ���콺 ���� ��ư�� ���� ��ǥ�� �ܼ� â�� ���
		break;
	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;	// ���콺 ���� ��ư�� ������ ��ǥ�� �ܼ� â�� ���
		break;
	case EVENT_MOUSEMOVE:
	// ���콺�� �����̴� ���, ���콺 ���� ��ư�� �����ִ� ���¶�� img ���� ���� ����� ������ �̾� �׸�.
	// ������ pt0ld��ǥ���� ���� ���콺 �̺�Ʈ �߻� ��ǥ���� �׸���, ������ �׸��� �� �Ŀ��� ���� ���콺 �̺�Ʈ �߻� ��ǥ�� ptOld�� ������
		if (flags & EVENT_FLAG_LBUTTON) {
		// ����ڰ� ���콺 ���� ��ư�� ���� ���¿��� ���콺�� ������ �� ����Ǵ� �ڵ� ���
			line(img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
			imshow("img", img);
			ptOld = Point(x, y);
		}
		break;
	default:
		break;
	}
}