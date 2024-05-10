#include "List_3.h"
#include <iostream>
using namespace std;

List::List(int s)
{
	size = s;
	Node* new_elem = new Node;
	head = new_elem;
	tail = new_elem;

	for (int i = 0; i < size - 1; i++) 
	{
		Node* new_elem = new Node;
		new_elem->data = i+1;
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
	}
	beg.elem = head;
	end.elem = tail;
}

List::List(const List& l)
{
	Node* elem = l.head;
	while (elem != nullptr) {
		PushBack(elem->data);
		elem = elem->next;
	}
	beg.elem = head;
	end.elem = tail;
}

List::~List()
{
	Node* curr = head;
	while (curr != nullptr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

List& List::operator= (const List& l)
{
	if (this == &l)return *this;

	if (head != nullptr)
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

	Node* elem = l.head;
	while (elem != nullptr) {
		PushBack(elem->data);
		elem = elem->next;
	}
	beg.elem = head;
	end.elem = tail;
	return *this;
}

int& List::operator[] (int i)
{
	Node* curr = head;
	for (int j = 0; j < i; j++) {
		curr = curr->next;
	}
	return curr->data;
}

List List::operator*(List& l)
{
	List base = *this;
	int s = this->size;
	List temp;

	for (int i = 0; i < s; i++)
	{
		temp.PushBack(base[i] * l[i]);
	}

	return temp;
}

int& List::operator()() {
	return size;
}

Iterator List::first()
{
	return beg;
}

Iterator List::last()
{
	return end;
}

void List::PushBack(int a)
{
	Node* new_elem = new Node;
	new_elem->data = a;

	if (size == 0)
	{
		head = new_elem;
		tail = new_elem;
		size++;
		beg.elem = head;
		end.elem = tail;
	}
	else
	{
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
		size++;
		end.elem = tail;
	}
}

void List::PopBack()
{
	Node* curr = tail;
	tail = curr->prev;
	delete curr;
	tail->next = nullptr;
	size--;
	end.elem = tail;
}

Iterator::Iterator() {
	elem = nullptr;
}

Iterator::Iterator(const Iterator& it) {
	elem = it.elem;
}

Iterator& Iterator::operator=(const Iterator& a)
{
	elem = a.elem;
	return *this;
}

int& Iterator::operator*() const
{
	return elem->data;
}

Iterator& Iterator::operator+ (const int& a)
{
	for (int i = 0; i < a; ++i) {
		elem = elem->next;	
	}
	return *this;
}