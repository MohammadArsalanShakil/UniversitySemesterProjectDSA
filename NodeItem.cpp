#include "NodeItem.h"



NodeItem::NodeItem()
{
	next = prev = NULL;
}

NodeItem::NodeItem(string name, int quantity, int price)
{
	this->name = name;
	this->quantity = quantity;
	this->price = price;
	next = prev = NULL;
}


NodeItem::~NodeItem()
{
}
