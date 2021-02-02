#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void camera_in_video_out();

int main(void)
{
	camera_in_video_out();

	return 0;
}

void camera_in_video_out()
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));	// ī�޶� �������� ���� ũ��
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));	// ī�޶� �������� ���� ũ��
	double fps = cap.get(CAP_PROP_FPS);	// ī�޶��� FPS ��

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps);	// DivX MPEG-4 �ڵ��� �ش��ϴ� fourcc �ڵ带 ������

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));	// ������ ���������� ����. �̸��� output.avi

	if (!outputVideo.isOpened()) {
		cout << "File open failed!" << endl;
		return;
	}

	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;
		outputVideo << inversed;	// ������ ī�޶� ������ ���� inversed�� ��� ������ �߰���

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();
}