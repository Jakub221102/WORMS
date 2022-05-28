
#include <iostream>

template<class Type>
struct Node {
	Type value;
	Node* next;
	Node(const Type& value, Node* next = nullptr);
	inline Type getValue() const { return value; }
};

template<class Type>
class CyclicSinglyLinkedList {
	Node<Type>* head;
	Node<Type>* tail;
public:
	CyclicSinglyLinkedList();
	~CyclicSinglyLinkedList();
	void addToTail(const Type& value);
	void remove(const Type& value);
	template<class Type>
	friend std::ostream& operator<<(std::ostream& out, const CyclicSinglyLinkedList<Type>& list);
};

template<class Type>
Node<Type>::Node(const Type& value, Node<Type>* next) 
	: value(value), next(next){

}

template<class Type>
CyclicSinglyLinkedList<Type>::CyclicSinglyLinkedList()
	: head(nullptr), tail(nullptr) {

}

template<class Type>
void CyclicSinglyLinkedList<Type>::addToTail(const Type& value) {
	if (head == nullptr) {
		head = tail = new Node<Type>(value);
		head->next = head;
	}
	else {
		tail->next = new Node<Type>(value, head);
		tail = tail->next;
	}
}

template<class Type>
void CyclicSinglyLinkedList<Type>::remove(const Type& value) {
	if (head == nullptr) return;
	else if (head == tail) {
		if (head->value == value) {
			delete head;
			head = tail = nullptr;
		}
	}
	else {
		Node<Type>* ptr = nullptr, * prev = tail;
		for (ptr = head; ptr != tail && !(ptr->value == value); prev = ptr, ptr = ptr->next);
		if (ptr && ptr->value == value) {
			if (ptr == tail) tail = prev;
			if (ptr == head) head = ptr->next;
			prev->next = ptr->next;
			delete ptr;
		}
	}
}

template<class Type>
std::ostream& operator<<(std::ostream& out, const CyclicSinglyLinkedList<Type>& list) {
	Node<Type>* ptr = list.head;
	if (!ptr) return out;
	for (; ptr != list.tail; ptr = ptr->next)
		out << ptr->value << ' ';
	out << ptr->value;
	return out;
}

template<class Type>
CyclicSinglyLinkedList<Type>::~CyclicSinglyLinkedList() {
	Node<Type>* ptr = head;
	while (ptr != tail) {
		Node<Type>* buf = ptr;
		ptr = ptr->next;
		delete buf;
	}
	delete ptr;
}