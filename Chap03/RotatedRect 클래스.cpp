class RotatedRect {
public:
	RotatedRect();
	RotatedRect(const Point2f& _center, const Size2f& _size, float angle);
	RotatedRect(const Poitn2f& point1, const Point2f& point2, const Point2f& point3);	// (poinr1, point2, point3)�� ���ڷ� �޴� ������. �� ���� ȸ���� �簢���� �� ������ ��ǥ

	void points(Point2f pts[]) const;	// RotatedRect::points() : ȸ���� �簢���� �� ������ ��ǥ�� pts ���ڿ� ������
	Rect boundingRect() const;			// RotatedRect::boundingRect() : ȸ���� �簢���� �����ϴ� �ּ� ũ���� �簢���� ������ ��ȯ��(���� ����)
	Rect_<float> boundingRect2f() const;// RotatedRect::boundingRect2f() : ȸ���� �簢���� �����ϴ� �ּ� ũ���� �簢���� ������ ��ȯ��(�Ǽ� ����)

	Point2f center;						// center : �簢�� �߽� ��ǥ
	Size2f size;						// size : �簢�� ũ��
	float angle;						// angle : �ð� ���� ȸ�� ����
};