#include "DoublyListCashier.h"

int transactionNumber = 0;

DoublyListCashier::DoublyListCashier()
{
}

DoublyListCashier::DoublyListCashier(string Customername, string name, int quantity, int price)
{
	start = new NodeCashier(Customername, name, quantity, price);
	start->prev = start->next = NULL;
}


DoublyListCashier::~DoublyListCashier()
{
}

void DoublyListCashier::insert(string CustomerName, string ItemName, int quantity, int price)
{
	NodeCashier *item = new NodeCashier(CustomerName, ItemName, quantity, price);
	if (start == NULL)
		start = item;
	if (start != NULL)
	{
		item->next = start->next;
		start->next = item;
		item->prev = start;
	}
}

void DoublyListCashier::deleteCustomer(string name)
{
	NodeCashier *temp = start;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		temp = temp->next;
	}
}

void DoublyListCashier::searchCustomer(string name)
{
	NodeCashier *temp = start;
	if (temp->name == name)
	{
		cout << setw(5) << "Customer Name : " << temp->Customername << endl;
		cout << setw(5) << "Item Name : " << temp->name << endl;
		cout << setw(5) << "Item quantity : " << temp->quantity << endl;
		cout << setw(5) << "Item price : " << temp->price << endl;
		cout << endl << endl;
	}
	temp = temp->next;
}

void DoublyListCashier::deleteItem(string item)
{
	NodeCashier *temp = start;
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

void DoublyListCashier::searchItem(string item)
{
	NodeCashier *temp = start;
	if (temp->name == item)
	{
		cout << setw(5) << "Customer Name : " << temp->Customername << endl;
		cout << setw(5) << "Item Name : " << temp->name << endl;
		cout << setw(5) << "Item quantity : " << temp->quantity << endl;
		cout << setw(5) << "Item price : " << temp->price << endl;
		cout << endl << endl;
	}
	temp = temp->next;
}

void DoublyListCashier::write(string filename)
{
	transactionNumber++;
	ofstream file(filename, ios::app);
	NodeCashier *temp = start;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		if (i == 1)
		{
			file << "Transaction : " << transactionNumber << endl;
			file << setw(5) << "Customer Name : " << temp->Customername << endl;
		}
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
	file << endl << "*********************************************************" << endl << endl;
	file.close();
}

void DoublyListCashier::display()
{
	NodeCashier *temp = start;
	while (temp != NULL)
	{
		cout << "Transaction : " << transactionNumber << endl;
		cout << setw(5) << "Customer Name : " << temp->Customername << endl;
		cout << setw(5) << "Item Name : " << temp->name << endl;
		cout << setw(5) << "Item quantity : " << temp->quantity << endl;
		cout << setw(5) << "Item price : " << temp->price << endl;
		cout << endl << endl;
		temp = temp->next;
	}
}
