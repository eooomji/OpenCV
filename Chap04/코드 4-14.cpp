#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void writeData();

// String filename = "mydata.xml";
// String filename = "mydata.yml";
String filename = "mydata.json";

int main(void)
{
	writeData();

	return 0;
}

void writeData()
{
	// 파일에 저장할 데이터 변수를 선언함
	String name = "Jane";
	int age = 10;
	Point pt1(100, 200);
	vector<int> scores = { 80, 90, 50 };
	Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	FileStorage fs;
	fs.open(filename, FileStorage::WRITE);	// FileStorage 객체를 쓰기 모드로 생성함

	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}
	// << 연산자를 이용해 준비한 데이터를 파일에 저장
	fs << "name" << name;
	fs << "age" << age;
	fs << "point" << pt1;
	fs << "scores" << scores;
	fs << "data" << mat1;

	fs.release();	// 데이터 저장 끝 ---> 닫음
}