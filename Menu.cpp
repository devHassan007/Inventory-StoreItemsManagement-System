#include <iostream>
#include "Menu.h"

using namespace std;
using namespace MainMenu;

int Menu::menu()
{
	int opt;
	cout<<"\n--------------------";
	cout<<"\n Items Informations ";
	cout<<"\n--------------------";
	cout<<"\n  ......MENU......";
	cout<<"\n1.Add Item";
	cout<<"\n2.List Items";
	cout<<"\n0.Quit";
	
	cout<<"\n\nEnter Your Choice : ";
	cin>>opt;
	
	return opt;
}


