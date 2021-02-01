#include <iostream>
using namespace std;

void Mat0p6() {
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32FC1, data); 
	cout << "mat1:\n" << mat1 << endl;	// 1 1 / 2 3

	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;	// 3 -1 / -2 1

	cout << "mat1.t():\n" << mat1.t() << endl;	// 1 2 / 1 3
	cout << "mat1 + 3:\n" << mat1 + 3 << endl;

	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;
}