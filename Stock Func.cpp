#include<iomanip>
#include <fstream>
#include <conio.h>
#include <iostream>
#include "StoreItem main.h"

using namespace std;
using namespace StoreItems;

void Stock::ReciptEntry()
{
	int codecheck;
	char name[15];
	SubFunc sf;
	char che;
	
	//indicate this is Issue transaction
	stock.transType='R';
	
	//Get the item code for issue item
	cout<<"\nEnter the Item Code :";
	cin>>stock.itemCode;
	
	//If user enter the character then show the error and return from the function
	if(cin.fail()){
		cin.clear();
		cin.ignore();	 
		cout<<"\nItem code only accept Numeric Values...";
		getch();
		return;	   	   
	}
	   
	//checking item code is correct
	codecheck=sf.findCode(stock.itemCode);	   
	if(codecheck==0)
	{
	cout<<"\nItem Code does not exist";
	cout<<"\n\nPress any key to continue...";
	getch();
	return;
	}
		
	//check the item name is correct or not
	sf.getName(stock.itemCode,name);
	cout<<"\nThe Item Name : "<<name<<endl;
	cout<<"\nName is it correct? : (Y/N)";
	cin>>che;
	
	
	if(che=='y'||che=='Y'){
	
	//Get the quantity
	cout<<"\nEnter the Quantity of the Item :";
	cin>>stock.qty;
	
	//write the content to file
	ofstream file;
	file.open("Stock.bin",ios::app|ios::binary);
	file.write((char*)&stock, sizeof(stock));
	file.close();
	}
	else
	{
	cout<<"\nSorry, Name is not correct...";
	getch();
	return;
	}
	
	//just wait for screen
	cout<<"\n\npress any key to continue...";
	getch();

}

void Stock::IssueEntry()
{
	int codecheck;
	char name[15];
	SubFunc sf;
	char cho;
	//indicate this is Issue transaction
	stock.transType='I';
	//Get the item code for issue item
	cout<<"\nEnter the Item Code :";
	cin>>stock.itemCode;
	
	//If user enter the character then show the error and return from the function
	if(cin.fail()){
		cin.clear();
		cin.ignore();	 
		cout<<"\nItem code only accept Numeric Values...";
		getch();
		return;	   	   
	}

	//checking item code is correct
	codecheck=sf.findCode(stock.itemCode);
	if(codecheck==0)
	{
	cout<<"\nItem Code does not exit";
	cout<<"\n\npress any key to continue...";
	getch();
	return;
	}
	
	//check the item name is correct or not
	sf.getName(stock.itemCode,name);
	cout<<"\nThe Item Name : "<<name<<endl;
	cout<<"\nName is it correct? : (Y/N)";
	cin>>cho;
	
	
	if(cho=='y'||cho=='Y'){
	//Get the quantity
	cout<<"\nEnter the Quantity of the Item :";
	cin>>stock.qty;
	
	//write the content to file
	ofstream file;
	file.open("Stock.bin",ios::app|ios::binary);
	file.write((char*)&stock, sizeof(stock));
	file.close();
	}
	else
	{
	cout<<"\nSorry, Name is not correct...";
	getch();
	return;
	}
	
	//just wait for screen
	cout<<"\n\npress any key to continue...";
	getch();

}

void Stock::StockList()
{
	SubFunc sb;
	int code;
	string name;
	ifstream file;
	file.open(".//Items//Itemlist.txt",ios::in);
	cout<<"\n ------------------------------------------------";
	cout<<"\n"<<" |"<<setw(27)<<fixed<<right<<"STOCK LIST"<<setw(20)<<"|";
	cout<<"\n ------------------------------------------------\n";
	cout<<" | "<<setw(10)<<fixed<<left<<"Item Code"<<" | "<<setw(15)<<fixed<<left<<"Item Name"<<" | "<<setw(14)<<fixed<<"Stock"<<"|";
	cout<<"\n ------------------------------------------------";
	while(!file.eof())
	{
		file>>code>>name;
		cout<<"\n"<<" | "<<setw(10)<<fixed<<left<<code<<" | "<<setw(15)<<fixed<<left<<name<<" | "<<setw(14)<<fixed<<sb.getTotal(code)<<"|";
	}
	cout<<"\n ------------------------------------------------";
	
	file.close();
	
	//just wait the screen
	cout<<"\n\npress any key to continue...";	 
	getch();
}

void Stock::TransHis()	//reading the stock list
{
	SubFunc sf;		//object for get name func
	int code,codecheck;
	char name[15];
	
	//get the item code from user
	cout<<"\nEnter Item code :";
	cin>>code;
	
	//If user enter the character then show the error and return from the function
	if(cin.fail()){
		cin.clear();
		cin.ignore();	 
		cout<<"\nItem code only accept Numeric Values...";
		getch();
		return;	   	   
	}
	
	//checking item code is correct
	codecheck=sf.findCode(code);
	if(codecheck==0)
	{
	cout<<"\nItem Code does not exist";
	cout<<"\n\npress any key to continue...";
	getch();
	return;
	}
	
	//find total for recipt and issue
	float totalRecipt=0,totalIssue=0,total=0;
	total=sf.findTotal(code,totalRecipt,totalIssue);
	
	//get the item name using item code
	sf.getName(code,name);
	
	//opened the file in binary mode
	ifstream file;
	file.open("Stock.bin",ios::in|ios::binary);
	
	//print the item name	
	cout<<"\n-----------------------------------\n";
	cout<<fixed<<right<<setw(20)<<name;
	cout<<"\n-----------------------------------";  
	cout<<"\n"<<fixed<<"TransType"<<fixed<<right<<setw(14)<<"Recipt"<<fixed<<setw(11)<<"Issue";
	cout<<"\n-----------------------------------";
	
	//print the trans history for recipt and issue in order
	while(file.read((char*)&stock, sizeof(stock)))
	{
	if(code==stock.itemCode){
		if(stock.transType=='R')
		cout<<"\n"<<fixed<<stock.transType<<setw(22)<<right<<fixed<<setprecision(2)<<stock.qty;	  
		else if(stock.transType=='I')
		cout<<"\n"<<fixed<<stock.transType<<setw(33)<<fixed<<right<<setprecision(2)<<stock.qty;	    	
	}	 
	}
	
	//printing total stocks
	cout<<"\n-----------------------------------";  
	cout<<"\n"<<fixed<<setw(16)<<left<<"Total:"<<setw(10)<<fixed<<totalRecipt<<setw(8)<<fixed<<right<<totalIssue;
	cout<<"\n-----------------------------------";
	cout<<"\n"<<fixed<<setw(20)<<right<<"Closing stock : "<<total;
	cout<<"\n-----------------------------------";
	
	//closing file
	file.close();
	
	//just wait the screen
	cout<<"\n\npress any key to continue...";	 
	getch();
}

void Stock::ViewStoreItem()
{

	cout<<"\n     Stored Items";
	cout<<"\n---------------------\n";
	ifstream file;
	file.open(".//Items//Itemlist.txt",ios::in);
	string read;
	while(getline(file,read))
	{
	
	cout<<"      "<<read<<endl;
	
	}
	file.close();
	
	cout<<"\nPress any key to continue..";
	getch();
}


