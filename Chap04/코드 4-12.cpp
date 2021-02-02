#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// 트랙바 콜백 함수를 선언함. 이 트랙바 콜백 함수의 정의는 23-29에 있음
void on_level_change(int pos, void* userdata);

int main(void)
{
	Mat img = Mat::zeros(400, 400, CV_8UC1);

	namedWindow("image");	// 트랙바를 부착할 image 창을 미리 생성함
	// 트랙바를 생성하고 트랙바 콜백 함수를 등록함
	// 트랙바 이름 : level, 최대 위치 : 16, 트랙바 콜백 함수 이름 : on_level_change, img 객체 주소를 사용자가 데이터로 지정함
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

	imshow("image", img);
	waitKey();

	return 0;
}

void on_level_change(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;	// void* 타입의 인자 userdata를 Mat* 타입으로 형변환한 후, img 변수로 참조함

	img.setTo(pos * 16);	// 트랙바 위치 pos에 16을 곱한 결과를 img 영상의 전체 픽셀 값으로 설정함.
							// 만약 pos * 16 결과가 255보다 크면, 포화 연산이 적용됨
	imshow("image", img);	// 픽셀 값이 설정된 img 영상을 image 창에 출력함
}