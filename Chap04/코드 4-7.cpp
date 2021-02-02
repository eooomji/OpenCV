#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawPolys();

int main(void)
{
	drawPolys();

	return 0;
}

void drawPolys()
{
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	// 사각형
	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);	
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);

	// 원
	circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);	// 내부 채우기
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);

	// 타원
	ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), FILLED, LINE_AA);
	ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);

	// 계단 모양의 다각형을 두께 2인 선으로 그림 (보라색)
	vector<Point> pts;
	pts.push_back(Point(250, 250)); pts.push_back(Point(300, 250));
	pts.push_back(Point(300, 300)); pts.push_back(Point(350, 300));
	pts.push_back(Point(350, 350)); pts.push_back(Point(250, 350));
	polylines(img, pts, true, Scalar(255, 0, 255), 2);

	imshow("img", img);
	waitKey();

	destroyAllWindows();
}
