void Mat0p5() {
	Mat img1 = imread("lenna.bmp");

	cout << "Width: " << img1.cols << endl;
	cout << "Height: " << img1.rows << endl;
	cout << "Channels: " << img1.channels() << endl;

	if (img1.type() == CV_8UC1)
		cout << "img5 is a grayscale image." << endl;
	if (img1.type() == CV_8UC3)
		cout << "img5 is a truecolor image." << endl;

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;
}