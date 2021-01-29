template<typename _Tp> class Point_ {
public:
	Point_();								// 기본 생성자. x=0, y=0으로 초기화 됨
	Point_(_Tp _x, _Tp _y);					// (_x, _y)좌표를 인자로 받는 생성자. x=+x, y=_y로 초기화 됨
	Point_(const Point& pt);				// 복사 생성자. x=pt.x, y=pt.y로 초기화 됨

	Point_& operator = (const Point_ pt);	// 대입 연산자 재정의

	_Tp dot(const Point_& pt) const;		// Point::dot() : 두 점 사이의 내적을 계산하여 반환함
	double ddot(const Point_& pt) const;	// Point::ddot() : 두 점 사이의 내적을 실수형으로 계산해 double 자료형으로 반환함
	double cross(const Point_& pt) const;	// Point::cross() : 두 점 사이의 외적을 반환함
	bool inside(const Rect_<_Tp>& r) const;	// Point::inside() : 점의 좌표가 사각형 r 영역 안에 있으면 true를 반환함
	_Tp x, y;								// 멤버 변수. x는 x축 좌표, y는 y축 좌표를 나타냄
};

// 다양한 자료형에 대한 Point_ 클래스 이름 재정의
typedef Point_<int> Point2i;
typedef Point_<float> Point2f;
typedef Point_<double> Point2d;
typedef Point2i Point;