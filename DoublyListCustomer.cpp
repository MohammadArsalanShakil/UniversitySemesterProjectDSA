#include "DoublyListCustomer.h"



DoublyListCustomer::DoublyListCustomer()
{
}

DoublyListCustomer::DoublyListCustomer(string name, int quantity, int price)
{
	start = new NodeItem(name, quantity, price);
	start->next = start->prev = NULL;
}


DoublyListCustomer::~DoublyListCustomer()
{
}

void DoublyListCustomer::insert(string name, int quantity, int price)
{
	NodeItem *item = new NodeItem(name, quantity, price);
	if (start == NULL)
		start = item;
	if (start != NULL)
	{
		item->next = start->next;
		start->next = item;
		item->prev = start;
	}
}

void DoublyListCustomer::deleteItem(string item)
{
	NodeItem *temp = start;
	while (temp != NULL)
	{
		if (temp->name == item)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		temp = temp->next;
	}
}

void DoublyListCustomer::searchItem(string item)
{
	NodeItem *temp = start;
	if (temp->name == item)
	{
		cout << setw(5) << "Item Name : " << temp->name << endl;
		cout << setw(5) << "Item quantity : " << temp->quantity << endl;
		cout << setw(5) << "Item price : " << temp->price << endl;
		cout << endl << endl;
	}
	temp = temp->next;
}

void DoublyListCustomer::write()
{
	ofstream file("Reciept.txt");
	NodeItem *temp = start;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		file << "Item " << i << " : " << endl;
		file << setw(5) << "Item Name : " << temp->name << endl;
		file << setw(5) << "Item quantity : " << temp->quantity << endl;
		file << setw(5) << "Item price : " << temp->price << endl;
		file << endl << endl;
		temp = temp->next;
	}
	temp = start;
	int total = 0;
	while (temp != NULL)
	{
		total += (temp->price*temp->quantity);
		temp = temp->next;
	}
	file << endl << endl << setw(25) << "Total : " << total << endl << endl;
	file.close();
}

void DoublyListCustomer::display()
{
	NodeItem *temp = start;
	while (temp != NULL)
	{
		cout << setw(5) << "Item Name : " << temp->name << endl;
		cout << setw(5) << "Item quantity : " << temp->quantity << endl;
		cout << setw(5) << "Item price : " << temp->price << endl;
		cout << endl << endl;
		temp = temp->next;
	}
}

