#include <iostream>
using namespace std;

int main() {
	Mat img1 = imread("lenna.bmp");

	cout << "Width: " << img1.cols << endl;
	cout << "Height: " << img1.rows << endl;
}
