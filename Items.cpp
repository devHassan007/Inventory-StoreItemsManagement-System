#include <iostream>
#include <fstream>
#include <conio.h>
#include "ItemsHeader.h"

using namespace std;
using namespace ItemsInfo;

void Items::addItem()
{
	HelpFunc help;
	int nameAndCode;
	cout<<"\n-----------------------------";
	cout<<"\n\tADD ITEMS";
	cout<<"\n-----------------------------";
	cout<<"\nEnter the Item Code : ";
	cin>>itemCode;
	getchar();
	cout<<"\nEnter the Item Name : ";
	cin>>itemName;
	
	//pass the values to check the name and code has already exit or not
	nameAndCode=help.checkExistItem(itemCode,itemName);
	
	//check the name and code is already exist or not
	if(nameAndCode==3)
	{
		cout<<"\nItem code : "<<itemCode;
		cout<<"\nItem name : "<<itemName;
		cout<<"\nSorry. Code And Name has been Already Exist...";
		cout<<"\n\npress any key to contunue...";
		getch();
		return;
	}else if(nameAndCode==2)
	{
		cout<<"\nItem name : "<<itemName;
		cout<<"\nSorry. Name has been Already Exist...";
		cout<<"\n\npress any key to contunue...";
		getch();
		return;
	}else if(nameAndCode==1)
	{
		cout<<"\nItem code : "<<itemCode;
		cout<<"\nSorry. Code has been Already Exist...";
		cout<<"\n\npress any key to contunue...";
		getch();
		return;
	}
	
	//write the content in file
	ofstream file;
	file.open("Itemlist.txt",ios::app);
	file<<itemCode<<" "<<itemName<<"\n";
	file.close();

	//waiting screen
	cout<<"\n\npress any key to contunue...";
	getch();
}

void Items::listItem()
{
	string read;
	ifstream file;
	
	//open the file
	file.open("Itemlist.txt",ios::in);
	cout<<"\n---------------------";
	cout<<"\n    STORED ITEMS";
	cout<<"\n---------------------\n";
	while(getline(file,read))
	{
		cout<<read<<endl;
	}
	
	file.close();

	//waiting screen	
	cout<<"\n\npress any key to continue...";
	getch();
}

