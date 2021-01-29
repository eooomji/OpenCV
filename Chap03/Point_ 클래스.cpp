template<typename _Tp> class Point_ {
public:
	Point_();								// �⺻ ������. x=0, y=0���� �ʱ�ȭ ��
	Point_(_Tp _x, _Tp _y);					// (_x, _y)��ǥ�� ���ڷ� �޴� ������. x=+x, y=_y�� �ʱ�ȭ ��
	Point_(const Point& pt);				// ���� ������. x=pt.x, y=pt.y�� �ʱ�ȭ ��

	Point_& operator = (const Point_ pt);	// ���� ������ ������

	_Tp dot(const Point_& pt) const;		// Point::dot() : �� �� ������ ������ ����Ͽ� ��ȯ��
	double ddot(const Point_& pt) const;	// Point::ddot() : �� �� ������ ������ �Ǽ������� ����� double �ڷ������� ��ȯ��
	double cross(const Point_& pt) const;	// Point::cross() : �� �� ������ ������ ��ȯ��
	bool inside(const Rect_<_Tp>& r) const;	// Point::inside() : ���� ��ǥ�� �簢�� r ���� �ȿ� ������ true�� ��ȯ��
	_Tp x, y;								// ��� ����. x�� x�� ��ǥ, y�� y�� ��ǥ�� ��Ÿ��
};

// �پ��� �ڷ����� ���� Point_ Ŭ���� �̸� ������
typedef Point_<int> Point2i;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point2i Point;