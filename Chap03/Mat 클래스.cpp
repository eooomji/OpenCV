class Mat {
public:
	// Mat 클래스의 다양한 생성자와 소멸자들
	Mat();
	Mat(int rows, int cols, int type);
	Mat(Size size, int type);
	Mat(int rows, int cols, int type, const Scalar& s);
	Mat(Size size, int type, const Scalar& s);
	Mat(const Mat& m);
	~Mat();

	// Mat 클래스의 멤버 함수. 연산자 재정의 함수와 정적 멤버 변수도 포함됨
	void create(int rows, int cols, int type);
	bool empty() const;

	Mat clone() const;
	void vopyTo(OutpputArray m) const;
	Mat& setTo(InputArray value, InputArray mask = noArray());

	static MatExpr zeros(int rows, int cols, int type);
	static MatExpr ones(int rows, int cols, int type);

	Mat& operator = (const Mat& m);
	Mat operator() (const Rect& roi) consst;

	template<typename _Tp> _Tp* ptr(int i0 = 0);
	template<typename _Tp> _Tp& at(int row, int col);

	// Mat 클래스의 주요 멤버 변수
	int dims;			// Mat::dims : Mat 행열의 차원을 나타냄
	int rows, cols;		// Mat::rows, Mat::cols : 2차원 행렬의 크기 
						// if Mat 객체에 정지 영상이 저장되어있으면? Mat::rows : 영상의 세로 픽셀 크기, Mat::cols : 영상의 가로 픽셀 크기
						// Mat::rows, Mat::cols는 Mat 객체가 2차원 행렬인 경우에만 의미있는 값을 가지며, 3차원 이상의 행렬에서는 -1이 저장됨
	uchar* data;		// Mat::data : 행렬의 원소 데이터가 저장되어 있는 메모리 공간을 가리키는 포인터형 멤버 변수
						//			   행렬에 아무 것도 저장되어 있지 않으면 0(NULL)을 가짐
	MatSize size;
	...
};