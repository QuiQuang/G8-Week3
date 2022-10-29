#pragma once
#include <iostream>
using namespace std;

class MyString
{
	char* Str;
	int n;
public:
	void Input();
	void Output();
	int Length();
	char* SubString(int, int);
	char* operator+(const MyString&);
	void Insert(int, char*);
	void GetValue(char*, int);
	void Delete(int, int);
	bool Replace(int, int, char*);
	bool Find(char*);
};
