#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;	// Mat과 imread, nameWindow, imshow, waitkey

int main() {
	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img;
	img = imread("lenna.bmp");	// imread() 함수 : 영상 읽기

	if (img.empty()) {	// lenna.bmp를 제대로 불러오지 못했을 경우에 대한 예외 처리 코드
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image");	// namedWindow() : 영상을 화면에 나타내기 위한 새로운 창을 생성, 그 창 이름 "image"
	imshow("image", img);	// imshow() : 영상 보여 주기(image show)

	waitKey();	// waitKey() : 사용자의 키보드 입력을 기다리는 함수. 사용자가 키보드를 누르기 전까지 영상을 화면에 나타나게 해줌
				//			   만약 사용자가 키보드에서 아무 키나 누르면 19행을 지나가게 되고, 20행의 return 구문을 만나 프로그램이 종료됨
	return 0;
}