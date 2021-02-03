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
	// ���Ͽ� ������ ������ ������ ������
	String name = "Jane";
	int age = 10;
	Point pt1(100, 200);
	vector<int> scores = { 80, 90, 50 };
	Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	FileStorage fs;
	fs.open(filename, FileStorage::WRITE);	// FileStorage ��ü�� ���� ���� ������

	if (!fs.isOpened()) {
		cerr << "File open failed!" << endl;
		return;
	}
	// << �����ڸ� �̿��� �غ��� �����͸� ���Ͽ� ����
	fs << "name" << name;
	fs << "age" << age;
	fs << "point" << pt1;
	fs << "scores" << scores;
	fs << "data" << mat1;

	fs.release();	// ������ ���� �� ---> ����
}