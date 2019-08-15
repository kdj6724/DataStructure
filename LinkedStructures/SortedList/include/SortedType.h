// SortedType.h
// 2019-08-07
// kdj6724@naver.com

template <class ItemType>
struct NodeType {
	ItemType info;
	NodeType<ItemType>* next;
};

template <class ItemType>
class SortedType {
public:
	SortedType();
	~SortedType();
	bool IsFull() const;
	int LengthIs() const;
	void MakeEmpty();
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	void GetNextItem(ItemType& item);
private:
	NodeType<ItemType>* listData_;
	int length_;
	NodeType<ItemType>* currentPos_;
};

template <class ItemType>
SortedType<ItemType>::SortedType() {
	length_ = 0;
	listData_ = nullptr;
}

template <class ItemType>
SortedType<ItemType>::~SortedType() {
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const {
	NodeType<ItemType>* location;
	try {
		location = new NodeType<ItemType>;
		delete location;
		return false;	
	} catch (std::bad_alloc exception) {
		return true;
	}
}

template <class ItemType>
int SortedType<ItemType>::LengthIs() const {
	return length_;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty() {
	NodeType<ItemType>* temp;
	while(listData_ != NULL) {
		temp = listData_;
		listData_ = listData_->next;
		delete temp;
	}
	length_ = 0;
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	bool moreToSearch;
	NodeType<ItemType>* location;
	
	location = listData_;
	found = false;
	moreToSearch = (location != nullptr);
	while (moreToSearch && !found) {
		if (location->info < item) {
			location = location->next;
			moreToSearch = (location != nullptr);
		} else if (item == location->info) {
			found = true;
			item = location->info;	
		} else {
			moreToSearch = false;
		}
	}
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item) {
	NodeType<ItemType>* newNode;
	NodeType<ItemType>* predLoc;
	NodeType<ItemType>* location;
	bool moreToSearch;

	location = listData_;
	predLoc = nullptr;
	moreToSearch = (location != nullptr);

	while (moreToSearch) {
		if (location->info < item) {
			predLoc = location;
			location = location->next;
			moreToSearch = (location != nullptr);
		} else {
			moreToSearch = false;
		}
	}		
	newNode = new NodeType<ItemType>;
	newNode->info = item;
	if (predLoc == nullptr) {
		newNode->next = listData_;
		listData_ = newNode;
	} else {
		newNode->next = location;
		predLoc->next = newNode;
	}
	length_++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* location;
	NodeType<ItemType>* temp;
	
	location = listData_;
	if (item == location->info) {
		temp = location;
		location = location->next;	
	} else {
		while(!(item == (location->next)->info))
			location = location->next;
		temp = location->next;
		location->next = (location->next)->next;
	}
	delete temp;
	length_--;
}

template <class ItemType>
void SortedType<ItemType>::ResetList() {
	currentPos_ = nullptr;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item) {
	if (currentPos_ == nullptr)
		currentPos_ = listData_;
	else
		currentPos_ = currentPos_->next;
	item = currentPos_->info;
}

