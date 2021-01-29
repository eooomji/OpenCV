template<typename _Tp> class Size_ {
public:
	Size_();								// 기본 생성자. width=0, height=0으로 초기화 됨
	Size_(_Tp _width, _Tp _height);			// (_width, _height)좌표를 인자로 받는 생성자. x=_width, y=_height로 초기화 됨
	Size_(const Size_& sz);					// 복사 생성자. width=sz.width, height=sz.height로 초기화 됨

	Size_& operator = (const Size_& sz);	// 대입 연산자 재정의

	_Tp area() const;						// Size::area() : 사각형 크기에 해당하는 면적(width*height)을 반환함
	bool empty() const;						// Size::empty() : 유효하지 않은 크기이면 true를 반환함

	_Tp width, height;						// 멤버 변수. width(사각형 영역의 가로 크기), height(사각형 영역의 세로 크기)
};

// 다양한 자료형에 대한 Size_ 클래스 이름 재정의
typedef Size_<int> Size2i;
typedef Size_<float> Size2f;
typedef Size_<double> Size2d;
typedef Size2i Size;