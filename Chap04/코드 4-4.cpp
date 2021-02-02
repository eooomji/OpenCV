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

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));	// 카메라 프레임의 가로 크기
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));	// 카메라 프레임의 세로 크기
	double fps = cap.get(CAP_PROP_FPS);	// 카메라의 FPS 값

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps);	// DivX MPEG-4 코덱에 해당하는 fourcc 코드를 생성함

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));	// 저장할 동영상파일 생성. 이름은 output.avi

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
		outputVideo << inversed;	// 반전된 카메라 프레임 영상 inversed를 출력 동영상에 추가함

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();
}