
#pragma once
#include <iostream>
using namespace std;
class List
{
protected:
	
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	
public:
	// constructors
	List();
	List(const List&);
	~List();

	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	List& operator=(List&& lst);
	friend ostream& operator<<(ostream& cout, const List& l);
	friend istream& operator>>(istream& cin, List& l);
	void insert(int const key);

protected:
	// data field
	Link* head;
};

