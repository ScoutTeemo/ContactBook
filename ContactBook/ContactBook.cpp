#include "ContactBook.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

static int CompareFun(CONTACT c1, CONTACT c2);
static int ShowContact(CONTACT contact);

int ContactBookInit()
{
	return 0;
}

int ContactBookDestory(vector<CONTACT> &p)
{
	vector<CONTACT> EmptyContactBook;
	vector<CONTACT>(EmptyContactBook).swap(p);
	return 0;
}

static int CompareFun(CONTACT c1, CONTACT c2)
{
	if (c1.name < c2.name)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

int AddContact(vector<CONTACT> &p, CONTACT contact)
{
	p.insert(p.end(), contact);
	sort(p.begin(), p.end(), CompareFun);
	return 0;
}

int DeleteContact(vector<CONTACT> &p, CONTACT contact)
{
	vector<CONTACT>::iterator it = find(p.begin(), p.end(), contact);
	if (it != p.end())
		p.erase(find(p.begin(), p.end(), contact));
	else
		return 1;				//can't find that contact
	return 0;
}

static int ShowContact(CONTACT contact)
{
	printf("%-10s\t%s\n", contact.name.c_str(), contact.number.c_str());
	return 0;
}

int Show(vector<CONTACT> &ContactBook)
{
	vector<CONTACT>::iterator p;
	for ( p = ContactBook.begin(); p != ContactBook.end(); p++)
	{
		ShowContact(*p);
	}
	return 0;
}

int SearchName(vector<CONTACT> &contact, string name)
{
	vector<CONTACT>::iterator p;
	int flag = 0;
	for (p = contact.begin(); p != contact.end(); p++)
	{
		if ( (p->name).find(name) != -1) 
		{
			flag = 1;
			ShowContact(*p);
		}
	}
	return flag;
}

int SearchNum(vector<CONTACT> &contact, string num)
{
	vector<CONTACT>::iterator p;
	int flag = 0;
	for (p = contact.begin(); p != contact.end(); p++)
	{
		if (p->number.find(num) != -1)
		{
			flag = 1;
			ShowContact(*p);
		}
	}
	return flag;
}

int SaveFile(vector<CONTACT> &contact)
{
	FILE *fp;
	vector<CONTACT>::iterator p;
	if (fopen_s(&fp,"contactbook.dat","r" ) != NULL)
	{
		fopen_s(&fp,"contactbook.dat", "w+");
		fclose(fp);
	}
	else
	{
		fclose(fp);
	}

	fopen_s(&fp, "contactbook.dat", "w+");
	for (p = contact.begin(); p != contact.end(); p++)
	{
		fprintf(fp, "#%s#%s#\n", p->name.c_str(), p->number.c_str());
	}
	fprintf(fp, "!!#OVER#!!\n");
	fclose(fp);
	return 0;

}

int ReadFile(vector<CONTACT> &contact)
{
	FILE *fp;
	char ch;
	string str;
	CONTACT con;
	vector<CONTACT>::iterator p;
	if (fopen_s(&fp, "contactbook.dat", "r") != NULL)
	{
		return 1;				//don't exist file
	}
	else
	{
		while (true)
		{
			if ( (ch = fgetc(fp)) == '!')
				break;
			str.clear();
			while ( (ch = fgetc(fp)) != '#' )
				str.push_back(ch);
			str.push_back('\0');
			con.name = str;
			
			str.clear();
			while ( (ch = fgetc(fp)) != '#' )
				str.push_back(ch);
			str.push_back('\0');
			con.number = str;
			fgetc(fp);

			AddContact(contact, con);
		}
		fclose(fp);
	}

	return 0;
}



