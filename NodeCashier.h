#pragma once
#include "NodeItem.h"
class NodeCashier
{
public:
	string Customername;
	string name;
	int quantity;
	int price;
	NodeCashier *next;
	NodeCashier *prev;
	NodeCashier();
	NodeCashier(string, string, int, int);
	~NodeCashier();
};

