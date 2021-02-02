#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void camera_in();
void video_in();
void camera_in_video_out();

int main(void)
{
	camera_in();
	video_in();
	camera_in_video_out();

	return 0;
}

void camera_in()
{
	VideoCapture cap(0);	// ��ǻ�Ϳ� ����Ǿ��ִ� �⺻ ī�޶� ����Ϸ��� 0�� ����

	if (!cap.isOpened()) {	// ī�޶� ��ġ�� ��� ������ ���·� ���ȴ��� Ȯ��
		cerr << "Camera open failed!" << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	// ī�޶�κ��� ���� �ð� ���ݸ��� �������� �޾ƿͼ� ȭ�鿡 ���
	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())	// ī�޶�κ��� �޾ƿ� frame ������ ����ִ� ���
			break;			// while ����������

		inversed = ~frame;	// ���� �������� �����Ͽ� inversed�� ����

		imshow("frame", frame);	// frame�� ����� ���� ������ ȭ�鿡 �����	
		imshow("inversed", inversed);	// inversed�� ����� ���� ������ ȭ�鿡 �����

		if (waitKey(10) == 27) // ESC key
			break;
	}

	destroyAllWindows();	// ��� â�� ����
}