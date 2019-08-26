// StackType.h
// 2019-08-03
// kdj6724@naver.com

class FullStack {
};

class EmptyStack {
};

typedef char ItemType;

template<class ItemType>
struct NodeType {
	ItemType info;
	NodeType* next;
};

class StackType {
public:
	StackType();
	~StackType();
	void Push(ItemType item);
	void Pop();
	ItemType Top();
	bool IsEmpty() const;
	bool IsFull() const;
private:
	NodeType* topPtr_;
};
