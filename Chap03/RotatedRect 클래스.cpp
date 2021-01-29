class RotatedRect {
public:
	RotatedRect();
	RotatedRect(const Point2f& _center, const Size2f& _size, float angle);
	RotatedRect(const Poitn2f& point1, const Point2f& point2, const Point2f& point3);	// (poinr1, point2, point3)을 인자로 받는 생성자. 세 점은 회전된 사각형의 세 꼭지점 좌표

	void points(Point2f pts[]) const;	// RotatedRect::points() : 회전된 사각형은 네 꼭지점 좌표를 pts 인자에 저장함
	Rect boundingRect() const;			// RotatedRect::boundingRect() : 회전된 사각형을 포함하는 최소 크기의 사각형의 정보를 반환함(정수 단위)
	Rect_<float> boundingRect2f() const;// RotatedRect::boundingRect2f() : 회전된 사각형을 포함하는 최소 크기의 사각형의 정보를 반환함(실수 단위)

	Point2f center;						// center : 사각형 중심 좌표
	Size2f size;						// size : 사각형 크기
	float angle;						// angle : 시계 방향 회전 각도
};