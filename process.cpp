#include <iostream>
#include <conio.h>
#include "ProcessHeader.h"
#include "ItemsHeader.h"

using namespace std;
using namespace Process;
using namespace ItemsInfo;

void Process1::start()
{
	while(1){
	system("cls");
	int cho=menu.menu();
	Items item;
	switch(cho)
	{
		case 1:
		item.addItem();
		break;
		
		case 2:
		item.listItem();
		break;
		
		case 0:
		return;
		break;
		
		default:
		cout<<"\nInvalid Input Please, Enter Valid Input...";
		getch();
		break;
	}
	}
}

