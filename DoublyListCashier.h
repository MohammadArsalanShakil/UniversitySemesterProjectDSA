#pragma once
#include "NodeCashier.h"
class DoublyListCashier
{
public:
	NodeCashier *start;
	DoublyListCashier();
	DoublyListCashier(string, string, int, int);
	~DoublyListCashier();
	void insert(string, string, int, int);
	void deleteCustomer(string);
	void searchCustomer(string);
	void deleteItem(string);
	void searchItem(string);
	void write(string);
	void display();
};

