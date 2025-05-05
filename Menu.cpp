#include <conio.h>
#include <iostream>
#include "MenuHeader.h"
#include "StoreItem main.h"

using namespace std;
using namespace MainMenu;
using namespace StoreItems;

int Menu::menu(){
	int opt;
	
	cout<<"\n------------------------";
	cout<<"\n    STOCK MANAGEMENT     ";
	cout<<"\n------------------------";
	cout<<"\n\n\tMenu:";
	cout<<"\n     -----------      ";
	cout<<"\n1.Reciept Entry";
	cout<<"\n2.Issue Entry";
	cout<<"\n3.Stock List";
	cout<<"\n4.Stock Transaction Report";
	cout<<"\n5.View Store Item";
	cout<<"\n0.Quit";
	
	cout<<"\n\nEnter your choice : ";
	cin>>opt;
	
	return opt;
}

void Menu::start()
{
	int cho;
	do
	{
		system("cls");
		cho=menu();
		
		if(cho==0) break;
		
		switch(cho)
		{
			case 1:
			stk.ReciptEntry();
			break;
			
			case 2:
			stk.IssueEntry();
			break;
			
			case 3:
			stk.StockList();
			break;
			
			case 4:
			stk.TransHis();
			break;
			
			case 5:
			stk.ViewStoreItem();
			break;
			
			default:
			cout<<"\nInvalid Input. Please Enter the Valid Input....";
			cout<<"\nPress any key to continue...";
			getch();
			break;
			
		}
	}while(cho!=0);
}

