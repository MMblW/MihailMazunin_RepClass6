#pragma once

struct Node {
	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class Iterator
{
	friend class List;
	Node* elem;
public:
	Iterator();
	Iterator(const Iterator& it);
	Iterator& operator=(const Iterator& a);
	int& operator*() const;
	Iterator& operator+ (const int& a);
};

class List
{
	int size;
	Node* head = nullptr;
	Node* tail = nullptr;
	Iterator beg;
	Iterator end;

public:
	List()
	{
		size = 0;
		head = nullptr;
		Node* tail = nullptr;
	}
	List(int s);
	List(const List& l);
	~List();

	Iterator first();
	Iterator last();
	void PushBack(int a);
	void PopBack();

	List& operator= (const List& l);
	int& operator[] (int i);
	int& operator()();
	List operator*(List& l);
	
};