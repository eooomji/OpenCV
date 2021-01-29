class Range {
public:
	Range();
	Range(int _start, int _end);

	int size() const;		// Range::size() : 범위 크기(end-start)를 반환함
	bool empty() const;		// Range::empty() : start와 end와 같으면 true를 반환함
	static Range all();		// Range::all() : start = INT_MIN, end = INT_MAX로 설정한 Range 객체를 반환함

	int start, end;
};