#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// Ʈ���� �ݹ� �Լ��� ������. �� Ʈ���� �ݹ� �Լ��� ���Ǵ� 23-29�� ����
void on_level_change(int pos, void* userdata);

int main(void)
{
	Mat img = Mat::zeros(400, 400, CV_8UC1);

	namedWindow("image");	// Ʈ���ٸ� ������ image â�� �̸� ������
	// Ʈ���ٸ� �����ϰ� Ʈ���� �ݹ� �Լ��� �����
	// Ʈ���� �̸� : level, �ִ� ��ġ : 16, Ʈ���� �ݹ� �Լ� �̸� : on_level_change, img ��ü �ּҸ� ����ڰ� �����ͷ� ������
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

	imshow("image", img);
	waitKey();

	return 0;
}

void on_level_change(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;	// void* Ÿ���� ���� userdata�� Mat* Ÿ������ ����ȯ�� ��, img ������ ������

	img.setTo(pos * 16);	// Ʈ���� ��ġ pos�� 16�� ���� ����� img ������ ��ü �ȼ� ������ ������.
							// ���� pos * 16 ����� 255���� ũ��, ��ȭ ������ �����
	imshow("image", img);	// �ȼ� ���� ������ img ������ image â�� �����
}