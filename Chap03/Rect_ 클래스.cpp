// ����ȭ�� Rect_ Ŭ���� ���ǿ� �̸� ������

template<typename _Tp> class Rect_ {
public:
	Rect_();												// �⺻ ������. ��� 0���� �ʱ�ȭ ��
	Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);			// (_x, _y, _width, _height) �簢�� ������ ���ڷ� �޴� ������. x=_x, y=_y, width=_width, height=_height�� �ʱ�ȭ ��
	Rect_(const Point& r);									// ���� ������. x=r.x, y=r.y, width=r.width, height=r.height�� �ʱ�ȭ ��
	Rect_(const Point_<_Tp>& org, const Size_<_Tp>& sz);	// ���� ��� ���� ��ǥ�� �簢���� ũ�� ������ ���ڷ� �޴� ������
	Rect_(const Point_<_Tp>& pt1, const Point_<_Tp>& pt2);	// �簢������ ���� �밢 ��ġ�� �ִ� �� ���� ��ǥ�� ���ڷ� �޴� ������

	Rect_& operator = (const Rect_& r);						// ���� ������ ������

	Point_<_Tp> tl() const;									// Rect::tl() : �簢���� ���� ��� ���� ��ǥ�� ��ȯ��
	Point_<_Tp> br() const;									// Rect::br() : �簢���� ���� �ϴ� ���� ��ǥ�� ��ȯ��
	Size_<_Tp> size() const;								// Rect::size() : �簢���� ũ�� ������ ��ȯ��
	_Tp area() const;										// Rect::area() : �簢���� ����(widthxheight)�� ��ȯ��
	bool empty() const;										// Rect::empty() : ��ȿ���� ���� �簢���̸� true�� ��ȯ��
	bool contains(const Point_<_Tp>& pt) const;				// Rect::contains() : ���ڷ� ���޵� pt���� �簢�� ���ο� ������ true�� ��ȯ��

	_Tp x, y, width, height;
};

// �پ��� �ڷ����� ���� Rect_ Ŭ���� �̸� ������
typedef Rect_<int> Rect2i;
typedef Rect_<float> Rect2f;
typedef Rect_<double> Rect2d;
typedef Rect2i Rect;