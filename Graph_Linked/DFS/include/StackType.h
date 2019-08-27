// StackType.h
// 2019-08-03
// kdj6724@naver.com

class FullStack {
};

class EmptyStack {
};

template <class ItemType>
struct QNodeType {
	ItemType info;
	QNodeType<ItemType>* next;
};

template <class ItemType>
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
	QNodeType<ItemType>* topPtr_;
};

template <class ItemType>
StackType<ItemType>::StackType() {
	topPtr_ = nullptr;
}

template <class ItemType>
StackType<ItemType>::~StackType() {
	QNodeType<ItemType>* tmp;

	while (topPtr_ != nullptr) {
		tmp = topPtr_;
		topPtr_ = topPtr_->next;
		delete tmp;
	}
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType item) {
	if (IsFull()) {
		throw FullStack();
	} else {
		QNodeType<ItemType>* location;
		location = new QNodeType<ItemType>;
		location->info = item;
		location->next = topPtr_;
		topPtr_ = location;	
	}
}

template <class ItemType>
void StackType<ItemType>::Pop() {
	if (IsEmpty()) {
		throw EmptyStack();
	} else {
		QNodeType<ItemType>* tmp;
		tmp = topPtr_;
		topPtr_ = topPtr_->next;
		delete tmp;
	}
}

template <class ItemType>
ItemType StackType<ItemType>::Top() {
	if (IsEmpty()) {
		throw EmptyStack();
	} else {
		return topPtr_->info;
	}
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const {
	return (topPtr_ == nullptr);
}

template <class ItemType>
bool StackType<ItemType>::IsFull() const {
	QNodeType<ItemType>* location;
	try {
		location = new QNodeType<ItemType>;
		delete location;
		return false;
	} catch (std::bad_alloc exception) {
		return true;
	}
}
