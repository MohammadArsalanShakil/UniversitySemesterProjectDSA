#include "NodeCashier.h"



NodeCashier::NodeCashier()
{
	next = prev = NULL;
}

NodeCashier::NodeCashier(string Customername, string name, int quantity, int price)
{
	this->Customername = Customername;
	this->name = name;
	this->quantity = quantity;
	this->price = price;
	next = prev = NULL;
}


NodeCashier::~NodeCashier()
{
}
