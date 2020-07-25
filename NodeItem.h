#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class NodeItem
{
public:
	string name;
	int quantity;
	int price;
	NodeItem *next;
	NodeItem *prev;
	NodeItem();
	NodeItem(string, int, int);
	~NodeItem();
};

