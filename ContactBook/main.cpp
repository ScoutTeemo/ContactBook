#include <stdio.h>
#include "ContactBook.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{

	vector<CONTACT> ContactBook;

	//CONTACT contact0 = {
	//	"abd","18274914885"
	//};
	//CONTACT contact1 = {
	//	"abb","18274914885"
	//};
	//CONTACT contact3 = {
	//	"hsg","18200001111"
	//};
	//AddContact(ContactBook, contact0);
	//Show(ContactBook);
	//printf("\n");
	//AddContact(ContactBook, contact1);
	//Show(ContactBook);
	//printf("\n");
	//AddContact(ContactBook, contact3);
	//Show(ContactBook);
	//printf("\n");
	//SaveFile(ContactBook);
//	ContactBookDestory(ContactBook);
	ReadFile(ContactBook);
	printf("\n");
	SearchNum(ContactBook,"488");
	Show(ContactBook);
	return 0;
}