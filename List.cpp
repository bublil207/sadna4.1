
#include "List.h"

List::List() : head(nullptr)
{
	// no further initialization
}

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}
					// List dtor
List::~List()
{
	clear();
}

void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}

void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

List& List::operator=(List&& lst)
{
	if (!isEmpty())
		clear();
	if (lst.isEmpty())// if list is empty
	{
		head = nullptr;
		return *this;
	}
	head = new Link((lst.head->value), nullptr);
	Link* p = lst.head->next;
	Link* q = p->next;
	if (p!=nullptr)
	{
		while (q != nullptr)
		{
			add(p->value);
			p = p->next;
			q = q->next;
		}
		add(p->value);
	}
		return *this;
}

ostream& operator<<(ostream& cout, const List& l)
{

	while (l.head == nullptr)
		return cout;
	if (l.head->next == nullptr)
	{		cout << l.head->value;
			return cout;
	}
	List::Link* p = l.head;
	List::Link* q = l.head->next;
	while (q != nullptr)
	{
		cout << p->value<<' ';
		p = p->next;
		q = q->next;
	}
	cout << p->value << endl;
	return cout;
}

istream& operator>>(istream& cin, List& l)
{
	int num,num1;
	cin >> num;
	l.add(num);
		cin >> num1;
		while (num1 >= num);
		{
			l.add(num1);
			num = num1;
			cin >> num1;
		}
	return cin;
}

void List::insert(int const key)
{
	if (key >= head->value||head==nullptr)
		add(key);
	Link* p = head;
	Link* n = new Link(key,nullptr);
	if (head->next == nullptr)
	{
		head->next = n;
			return;
	}
		Link* q = head->next;
	while (key <= p->value)
	{
		if (key >= p->next->value || p->next != nullptr)
		{
			if (key >= q->value)
			{
				p->next = n;
				n->next = q;
				return;
			}
			p->next = n;
			return;
		}
	}
	return;
}

