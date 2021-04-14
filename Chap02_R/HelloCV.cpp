#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img;
	img = imread("lena.jpg");	// imread : 영상 읽기

	if (img.empty()) {
		cerr << "Image load failed!" << endl;	// true -> 저 문자열을 출력한 후 프로그램을 종료함
		return -1;
	}

	namedWindow("image");	// namedWindow : 영상을 화면에 나타내기 위한 새로운 창을 생성 -> 그 창에 image라는 이름 부여
	imshow("image", img);	// imshow : 영상 읽기

	waitKey(0);	// waitKey : 사용자의 키보드 입력을 기다리는 함수. 사용자가 키보드를 누르기 전까지 영상을 화면에 나타나게 해줌
	return 0;
}
