#include "DoublyListCustomer.h"
#include "DoublyListCashier.h"
bool login();
void username();
void password();
void menu();
void newreciept(DoublyListCashier POS, DoublyListCustomer pos);
void seereciept(DoublyListCashier POS, DoublyListCustomer pos);
DoublyListCashier POS;
DoublyListCustomer pos;
void main()
{
	if (login())
		menu();
	system("pause");
}

void menu()
{
	string name;
	char ch;
	do
	{
		cout << "Super Mart Billing" << endl << endl;
		cout << "Press Following options to proceed \n\nPress 1 to start new reciept \nPress 2 to see existing reciept \nPress 3 to delete a record \nPress 4 to change username \nPress 5 to change password \nPress 6 to return to login menu \nPress 7 to Search Customer by name\nPress 8 to Delete Customer by name\nPress 9 to Search Item\nPress 10 to Delete Item\nPress 11 to exit" << endl;//Ask users to enter option for to perform following tasks
		int option;
		cout << "\nOption : ";
		cin >> option;//User enters required option
		switch (option)
		{
		case(1):
			system("cls");
			newreciept(POS, pos);//New reciept function is called
			break;
		case(2):
			system("cls");
			//seereciept();//See reciept function is called
			break;
		case(3):
			system("cls");
			//deleterecord();Delete record function is called
			break;
		case(4):
			system("cls");
			username();//User name function is called
			break;
		case(5):
			system("cls");
			password();//Password function is called
			break;
		case(6):
			system("cls");
			login();//Login function is called
			break;
		case(7):
			cout << "Enter Customer Name for searching: ";
			getline(cin, name);
			cin.ignore();
			POS.searchCustomer(name);
			break;
		case(8):
			cout << "Enter Customer Name for deletion: ";
			getline(cin, name);
			cin.ignore();
			POS.deleteCustomer(name);
			break;
		case(9):
			cout << "Enter Item Name for searching : ";
			getline(cin, name);
			cin.ignore();
			POS.searchItem(name);
			pos.searchItem(name);
			break;
		case(10):
			cout << "Enter Item Name for deletion : ";
			getline(cin, name);
			cin.ignore();
			POS.deleteItem(name);
			pos.deleteItem(name);
			break;
		case(11):
			exit(0);
			break;
		default:
			system("cls");
			cout << "Wrong Selection" << endl;
		}
		cout << endl << "Press Y to return to main menu : ";//Ask user if he/she wants to continue with other tasks
		cin >> ch;//User enters his/her choice
		system("cls");
	} while (ch != 'n' || ch != 'N');
}


bool login()
{
	char x = 'y';
	while (x == 'y' || x == 'Y')
	{
		string user_name, uname, pass1, pass;
		cout << "Enter Username and Password to continue" << endl << endl << "Username : ";//Asks user to input username
		cin >> user_name;//User enters username
		cout << endl << "Password : ";//Asks user to input password
		cin >> pass;//User enters password
		ifstream username;
		username.open("user_name.txt");//File name user_name is openned
		getline(username, uname);//Reads from file and save it in variable uname
		ifstream password;
		password.open("pass.txt");//File name pass is openned
		password >> pass1;//Data from file is saved into the variable pass1
		if (pass == pass1 && user_name == uname)//Username and password entered by user is checked with the data saved in files
		{
			system("cls");
			return true;
		}
		else
			cout << "\nInvalid Login\n";
		cout << "Do you want to try again? \nPress Y for yes and N for no : ";//Asks user if he/she wants to continue
		cin >> x;//User enters option
		if (x == 'y' || x == 'Y')
			system("cls");
		else
			exit(0);
	}
}

void username()//Username function defination
{
	char u = 'y';
	while (u == 'y' || u == 'Y')
	{
		string old, n;
		ifstream old_u;
		old_u.open("user_name.txt");//File user_name is openned
		old_u >> n;//Data from file is transferred to variable n
		old_u.close();//File is closed
		cout << "Enter Current Username : ";//Asks user to enter current username
		cin >> old;//User enters the username
		if (old == n)//Checks if old username matches the username from file 
		{
			ofstream uname;
			string newname;
			uname.open("user_name.txt");//Fill is openned with new variable
			cout << "Enter new username : ";//Ask user to enter new username
			cin >> newname;//User enters new username
			if (newname == n)//Checks if the new username is not as same as new username
			{
				cout << "Name cannot be old one used\n";
				uname << n;
				cout << "Want to try again? Press Y for yes or N for no : ";
				cin >> u;
				if (u == 'y' || u == 'Y')
					system("cls");
				else
					return;
			}
			else
			{
				uname << newname;
				uname.close();
				cout << endl;
				system("cls");
				cout << "User name changed successfully\n\n";
				return;
			}
		}
		else
		{
			cout << "Invalid Username\n";
			cout << "Want to try again? Press Y for yes or N for no : ";
			cin >> u;
			if (u == 'y' || u == 'Y')
			{
				system("cls");
			}
			else
				return;
		}
		cout << endl;
	}
}

void password()//Function defination 
{
	char p = 'y';
	while (p == 'y' || p == 'Y')
	{
		string s, c;
		cout << "Enter current password : ";//Asks user to enter password
		cin >> s;//User enters password
		ifstream old_pass;
		old_pass.open("pass.txt");//Opens file pass
		old_pass >> c;
		old_pass.close();//File is closed
		if (s == c)
		{

			ofstream pass;
			string newpass;
			pass.open("pass.txt");//Opens file pass
			cout << "Enter new password : ";//Asks user to enter new pasword
			cin >> newpass;//User enters new password
			if (newpass == c)//Checks if old password is equal to new password
			{
				cout << "Password cannot be old one\n";
				pass << c;
				cout << "Want to try again? Press Y for yes or N for no : ";
				cin >> p;
				if (p == 'y' || p == 'Y')
				{
					system("cls");
				}
				else
					return;
			}
			else
			{
				pass << newpass;
				pass.close();//File pass is closed
				cout << endl;
				system("cls");
				cout << "Password changed successfully\n\n";
				return;
			}
		}
		else
		{
			cout << "Wrong Password Entered\n";
			cout << "Want to try again? Press Y for yes or N for no : ";
			cin >> p;
			if (p == 'y' || p == 'Y')
			{
				system("cls");
			}
			else
				return;
		}
		cout << endl;
	}
}

void newreciept(DoublyListCashier POS, DoublyListCustomer pos)
{
	string customername;
	string itemname;
	int quantity;
	int price;
	char choice;
	cout << "Enter Customer Name : ";
	cin >> customername;
	do
	{
		cout << "Enter Item Name : ";
		cin >> itemname;
		cout << "Enter Quantity : ";
		cin >> quantity;
		cout << "Enter Price : ";
		cin >> price;
		POS.insert(customername, itemname, quantity, price);
		pos.insert(itemname, quantity, price);
		system("cls");
		cout << "Want to enter new item : ";
		cin >> choice;
	} while (choice=='Y'||choice=='y');
	POS.write(customername + ".txt");
	pos.write();
	menu();
}

void seereciept(DoublyListCashier POS, DoublyListCustomer pos)
{
	POS.display();
	pos.display();
}
