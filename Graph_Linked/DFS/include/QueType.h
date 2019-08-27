// QueType.h
// 2019-08-05
// kdj6724@naver.com
#include <cstddef>
#include <new>

class FullQueue {
};
class EmptyQueue {
};

template <class ItemType>
struct NodeType {
	ItemType info;
	NodeType<ItemType>* next;	
};

template <class ItemType>
class QueType {
public:
	QueType();
	~QueType();
	void MakeEmpty();
	void Enqueue(ItemType);
	void Dequeue(ItemType&);
	bool IsEmpty() const;
	bool IsFull() const;
private:
	NodeType<ItemType>* front_;
	NodeType<ItemType>* rear_;
};

template <class ItemType>
QueType<ItemType>::QueType() {
	front_ = nullptr;
	rear_ = nullptr;
}

template <class ItemType>
QueType<ItemType>::~QueType() {
	MakeEmpty();
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty() {
	NodeType<ItemType>* temp;
	while (front_ != nullptr) {
		temp = front_;
		front_ = front_->next;
		delete temp;
	}
	rear_ = nullptr;
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType item) {
	NodeType<ItemType>* temp;	
	if (IsFull()) {
		throw FullQueue();
	} else {
		temp = new NodeType<ItemType>;
		temp->info = item;
		temp->next = nullptr;
		if (rear_ == nullptr)
			front_ = temp;
		else
			rear_->next = temp;
		rear_ = temp;
	}
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item) {
	if (IsEmpty()) {
		throw EmptyQueue();
	} else {
		NodeType<ItemType>* temp;
		temp = front_;
		item = front_->info;
		front_ = front_->next;
		if (front_ == nullptr)
			rear_ = nullptr;
		delete temp;
	}
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const {
	return (front_ == nullptr);
}

template <class ItemType>
bool QueType<ItemType>::IsFull() const {
	NodeType<ItemType>* location;
	try {
		location = new NodeType<ItemType>;
		delete location;
		return false;
	} catch(std::bad_alloc exception) {
		return true;
	}
}
