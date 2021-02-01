#include <iostream>
using namespace std;

int main() {

	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);
		for (int i = 0; i < mat1.cols; i++) {
			p[i]++;
		}
	}
}