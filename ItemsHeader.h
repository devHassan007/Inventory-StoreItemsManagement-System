#ifndef ITEMSINFO_H 
#define ITEMSINFO_H 
namespace ItemsInfo
{
class Items
	{	 
	private:
	int itemCode;
	char itemName[15];
	
	public:
	void addItem();
	void listItem();
	
	};
	
class HelpFunc
{
	public:
	int checkExistItem(int code,char name[]);
	int stringcmp(char st1[],char st2[]);
	void toUpper(char *str);
};
}
#endif 

