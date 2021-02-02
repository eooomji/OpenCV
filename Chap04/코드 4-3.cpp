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
	VideoCapture cap("stopwatch.avi");	// stopwatch.avi 파일을 불러와서 cap 객체를 생성함

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;		// 프레임 가로 크기
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;	// 프레임 세로 크기
	cout << "Frame count: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;		// 전체 프레임 수

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;	// 비디오 파일의 초당 프레임 수

	int delay = cvRound(1000 / fps);	// FPS 값으로부터 각 프레임 사이의 시간 간격 delay를 계산함

	Mat frame, inversed;	
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) // 27 : ESC key, delay 시간만큼 키 입력을 기다리고, ESC가 눌리면 while 반복문을 빠져나감
			break;
	}

	destroyAllWindows();
}