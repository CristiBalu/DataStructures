#include "DoublyLinkedList.h"
#include <cassert>

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	_count = 0;
	_first = nullptr;
	_last = nullptr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
	delete _first;
	delete _last;
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
	if (_count > 0)
	{
		Node<T> *current;

		while (_first != nullptr)
		{
			current = _first;
			_first = _first->next();
			delete current;
		}

		_last = nullptr;
		_count = 0;
	}
}

template<typename T>
void DoublyLinkedList<T>::push(const T & obj)
{
	if (_count == 0) {
		_first = _last = new Node<T>(obj);
	}
	else {
		Node<T> *newNode = new Node<T>(obj, _last, nullptr);
		_last->setNext(newNode);
		_last = _last->next();
	}

	++_count;
}

template<typename T>
void DoublyLinkedList<T>::pushFront(const T & obj)
{
	if (_count == 0) {
		_first = _last = new Node<T>(obj);
	}
	else {
		Node<T> *newNode = new Node<T>(obj, nullptr, _first);
		_first->setPrev(newNode);
		_first = _first->prev();
	}

	++_count;
}

template<typename T>
void DoublyLinkedList<T>::pop()
{
	assert(_count > 0);

	if (_count != 1)
	{
		Node<T> *tmp = _last;
		_last = _last->prev();
		_last->setNext(nullptr);
		delete tmp;
		tmp = nullptr;
	}
	else
	{
		clear();
	}
}

template<typename T>
void DoublyLinkedList<T>::popFront()
{
	assert(_count > 0);
	
	if (_count != 1)
	{
		Node<T> *tmp = _first;
		_first = _first->next();
		_first->setPrev(nullptr);
		delete tmp;
		tmp = nullptr;
	}
	else
	{
		clear();
	}
}

template<typename T>
T DoublyLinkedList<T>::first() const
{
	return _first->value();
}

template<typename T>
T DoublyLinkedList<T>::last() const
{
	return _last->value();
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
	return _count == 0;
}

template<typename T>
int DoublyLinkedList<T>::count() const
{
	return _count;
}
