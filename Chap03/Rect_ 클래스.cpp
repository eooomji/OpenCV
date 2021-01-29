// 간략화한 Rect_ 클래스 정의와 이름 재정의

template<typename _Tp> class Rect_ {
public:
	Rect_();												// 기본 생성자. 모두 0으로 초기화 됨
	Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);			// (_x, _y, _width, _height) 사각형 정보를 인자로 받는 생성자. x=_x, y=_y, width=_width, height=_height로 초기화 됨
	Rect_(const Point& r);									// 복사 생성자. x=r.x, y=r.y, width=r.width, height=r.height로 초기화 됨
	Rect_(const Point_<_Tp>& org, const Size_<_Tp>& sz);	// 좌측 상단 점의 좌표와 사각형의 크기 정보를 인자로 받는 생성자
	Rect_(const Point_<_Tp>& pt1, const Point_<_Tp>& pt2);	// 사각형에서 서로 대각 위치에 있는 두 점의 좌표를 인자로 받는 생성자

	Rect_& operator = (const Rect_& r);						// 대입 연산자 재정의

	Point_<_Tp> tl() const;									// Rect::tl() : 사각형의 좌측 상단 점의 좌표를 반환함
	Point_<_Tp> br() const;									// Rect::br() : 사각형의 우측 하단 점의 좌표를 반환함
	Size_<_Tp> size() const;								// Rect::size() : 사각형의 크기 정보를 반환함
	_Tp area() const;										// Rect::area() : 사각형의 면적(widthxheight)를 반환함
	bool empty() const;										// Rect::empty() : 유효하지 않은 사각형이면 true를 반환함
	bool contains(const Point_<_Tp>& pt) const;				// Rect::contains() : 인자로 전달된 pt점이 사각형 내부에 있으면 true를 반환함

	_Tp x, y, width, height;
};

// 다양한 자료형에 대한 Rect_ 클래스 이름 재정의
typedef Rect_<int> Rect2i;
typedef Rect_<float> Rect2f;
typedef Rect_<double> Rect2d;
typedef Rect2i Rect;