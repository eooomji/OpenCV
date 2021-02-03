#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void readData();

// String filename = "mydata.xml";
// String filename = "mydata.yml";
String filename = "mydata.json";

int main(void)
{
	readData();

	return 0;
}

void readData()
{
	String name;
	int age;
	Point pt1;
	vector<int> scores;
	Mat mat1;

	FileStorage fs(filename, FileStorage::READ);

	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}

	// 파일에서 데이터를 읽음
	fs["name"] >> name;
	fs["age"] >> age;
	fs["point"] >> pt1;
	fs["scores"] >> scores;
	fs["data"] >> mat1;

	fs.release();

	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "point: " << pt1 << endl;
	cout << "scores: " << Mat(scores).t() << endl;
	cout << "data:\n" << mat1 << endl;
}