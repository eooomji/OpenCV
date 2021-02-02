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
	VideoCapture cap(0);	// 컴퓨터에 연결되어있는 기본 카메라 사용하려면 0을 넣음

	if (!cap.isOpened()) {	// 카메라 장치가 사용 가능한 상태로 열렸는지 확인
		cerr << "Camera open failed!" << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	// 카메라로부터 일정 시간 간격마다 프레임을 받아와서 화면에 출력
	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())	// 카메라로부터 받아온 frame 영상이 비어있는 경우
			break;			// while 빠져나가기

		inversed = ~frame;	// 현재 프레임을 반전하여 inversed에 저장

		imshow("frame", frame);	// frame에 저장된 정지 영상을 화면에 출력함	
		imshow("inversed", inversed);	// inversed에 저장된 정지 영상을 화면에 출력함

		if (waitKey(10) == 27) // ESC key
			break;
	}

	destroyAllWindows();	// 모든 창을 닫음
}