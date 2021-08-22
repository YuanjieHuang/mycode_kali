//比较两个记录大小
template <class Record >
class Compare {
public:
	static bool lt(Record x, Record y) { return x.key<y.key; }
	static bool lteq(Record x, Record y) { return x.key<=y.key; }
	static bool gteq(Record x, Record y) { return x.key>=y.key; }
	static bool eq(Record x, Record y) { return x.key ==y.key; }
	static bool gt(Record x, Record y) { return x.key >y.key; }
};
