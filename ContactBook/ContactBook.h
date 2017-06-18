#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;



typedef struct Contact
{
	string name;
	string number;

	bool operator== (const Contact &cn)
	{
		if ( (cn.name == this->name )&&(cn.number == this->number) )
		{
			return true;
		}
		return false;
	}

}CONTACT;

//typedef struct Contact CONTACT;



//vector<CONTACT>* ContactBookInit();
int ContactBookDestory(vector<CONTACT> &p);

int AddContact(vector<CONTACT> &p, CONTACT contact);
int DeleteContact(vector<CONTACT> &p, CONTACT contact);

int Show(vector<CONTACT> &p);
int SearchName(vector<CONTACT> &contact, string name);
int SearchNum(vector<CONTACT> &contact, string num);
int SaveFile(vector<CONTACT> &contact);
int ReadFile(vector<CONTACT> &contact);
