#include <ctype.h>
#include <sstream>
#include<iostream>
#include <fstream>
#include <string.h>
#include "ItemsHeader.h"

using namespace std;
using namespace ItemsInfo;

int HelpFunc::checkExistItem(int code,char name[])
{
	
	int itemcode=0,itemname=0;	  
	char getitemcode;
	char getitemname[15];
	ifstream file;
	file.open("Itemlist.txt",ios::in);
	while(!file.eof()){
	file>>getitemcode>>getitemname;
	
	stringstream ss;
	ss<<getitemcode;
	ss>>itemcode;

	itemname=stringcmp(getitemname,name);
	if(itemcode==code&&itemname==1)
	{
	return 3;
	}else if(itemcode==code)
	return 1;
	else if (itemname==1)
	return 2;
	}
	file.close();
	
}

int HelpFunc::stringcmp(char st1[],char st2[])
{
	toUpper(st2);
	toUpper(st1);
	
	int size=(strlen(st1)>strlen(st2))?strlen(st1):strlen(st2);
	int val=0;
	for(int i=0;i<size;i++)
	{
		if(st1[i]==st2[i])
		{
			val=1;
		}else
		{
		val=0;
		break;
		}	 
	}	 
	return val;
}

void HelpFunc::toUpper(char *str)
{
	char *i;
	for(i=str;*i!='\0';i++)
	{
	*i=(char) toupper(*i);
	}
	
}

