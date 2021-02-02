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

void video_in()
{
	VideoCapture cap("stopwatch.avi");	// stopwatch.avi ������ �ҷ��ͼ� cap ��ü�� ������

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;		// ������ ���� ũ��
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;	// ������ ���� ũ��
	cout << "Frame count: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;		// ��ü ������ ��

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;	// ���� ������ �ʴ� ������ ��

	int delay = cvRound(1000 / fps);	// FPS �����κ��� �� ������ ������ �ð� ���� delay�� �����

	Mat frame, inversed;	
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) // 27 : ESC key, delay �ð���ŭ Ű �Է��� ��ٸ���, ESC�� ������ while �ݺ����� ��������
			break;
	}

	destroyAllWindows();
}