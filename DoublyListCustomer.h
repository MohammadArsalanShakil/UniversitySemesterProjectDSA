#pragma once
#include "NodeItem.h"
class DoublyListCustomer
{
public:
	NodeItem *start;
	DoublyListCustomer();
	DoublyListCustomer(string, int, int);
	~DoublyListCustomer();
	void insert(string, int, int);
	void deleteItem(string);
	void searchItem(string);
	void write();
	void display();
};

