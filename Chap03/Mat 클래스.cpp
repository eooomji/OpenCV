class Mat {
public:
	// Mat Ŭ������ �پ��� �����ڿ� �Ҹ��ڵ�
	Mat();
	Mat(int rows, int cols, int type);
	Mat(Size size, int type);
	Mat(int rows, int cols, int type, const Scalar& s);
	Mat(Size size, int type, const Scalar& s);
	Mat(const Mat& m);
	~Mat();

	// Mat Ŭ������ ��� �Լ�. ������ ������ �Լ��� ���� ��� ������ ���Ե�
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

	// Mat Ŭ������ �ֿ� ��� ����
	int dims;			// Mat::dims : Mat �࿭�� ������ ��Ÿ��
	int rows, cols;		// Mat::rows, Mat::cols : 2���� ����� ũ�� 
						// if Mat ��ü�� ���� ������ ����Ǿ�������? Mat::rows : ������ ���� �ȼ� ũ��, Mat::cols : ������ ���� �ȼ� ũ��
						// Mat::rows, Mat::cols�� Mat ��ü�� 2���� ����� ��쿡�� �ǹ��ִ� ���� ������, 3���� �̻��� ��Ŀ����� -1�� �����
	uchar* data;		// Mat::data : ����� ���� �����Ͱ� ����Ǿ� �ִ� �޸� ������ ����Ű�� �������� ��� ����
						//			   ��Ŀ� �ƹ� �͵� ����Ǿ� ���� ������ 0(NULL)�� ����
	MatSize size;
	...
};