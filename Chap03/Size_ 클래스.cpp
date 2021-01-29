template<typename _Tp> class Size_ {
public:
	Size_();								// �⺻ ������. width=0, height=0���� �ʱ�ȭ ��
	Size_(_Tp _width, _Tp _height);			// (_width, _height)��ǥ�� ���ڷ� �޴� ������. x=_width, y=_height�� �ʱ�ȭ ��
	Size_(const Size_& sz);					// ���� ������. width=sz.width, height=sz.height�� �ʱ�ȭ ��

	Size_& operator = (const Size_& sz);	// ���� ������ ������

	_Tp area() const;						// Size::area() : �簢�� ũ�⿡ �ش��ϴ� ����(width*height)�� ��ȯ��
	bool empty() const;						// Size::empty() : ��ȿ���� ���� ũ���̸� true�� ��ȯ��

	_Tp width, height;						// ��� ����. width(�簢�� ������ ���� ũ��), height(�簢�� ������ ���� ũ��)
};

// �پ��� �ڷ����� ���� Size_ Ŭ���� �̸� ������
typedef Size_<int> Size2i;
typedef Size_<float> Size2f;
typedef Size_<double> Size2d;
typedef Size2i Size;