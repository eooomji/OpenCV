class Range {
public:
	Range();
	Range(int _start, int _end);

	int size() const;		// Range::size() : ���� ũ��(end-start)�� ��ȯ��
	bool empty() const;		// Range::empty() : start�� end�� ������ true�� ��ȯ��
	static Range all();		// Range::all() : start = INT_MIN, end = INT_MAX�� ������ Range ��ü�� ��ȯ��

	int start, end;
};