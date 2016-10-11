#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class Node
{
public:
	Node(const T &value, Node *prev, Node *next)
		: _value(value)
		, _prev(prev)
		, _next(next)
	{}
	Node(const T&value)
		: _value(value)
		, _prev(nullptr)
		, _next(nullptr)
	{}
	~Node() {}

	T value() const { return _value; }
	Node<T> *prev() const { return _prev; }
	Node<T> *next() const { return _next; }

	void setValue(T value) { _value = value; }
	void setPrev(Node<T> *prev) { _prev = prev; }
	void setNext(Node<T> *next) { _next = next; }

	bool hasPrev() const { return _prev != nullptr; }
	bool hasNext() const { return _next != nullptr; }
private:
	T _value;
	Node<T> *_prev;
	Node<T> *_next;
};

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void clear();
	void push(const T &obj);
	void pushFront(const T&obj);
	void pop();
	void popFront();

	T first() const;
	T last() const;

	bool isEmpty() const;
	int count() const;

private:
	Node<T> *_first;
	Node<T> *_last;
	int _count;
};

#endif // !DOUBLYLINKEDLIST_H