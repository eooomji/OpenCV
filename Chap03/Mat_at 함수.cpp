#include <iostream>
using namespace std;

int main() {
	Mat mat1 = Mat::zeros(3, 4, CU_8UC1);	// mat1: 0���� �ʱ�ȭ�� 3x4 ���

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}
}