#include "MyString.h"

void MyString::Input() {
	MyString A;
	A.Str = new char[1024];
	cout << "Nhap chuoi : ";
	fgets(A.Str, 1024, stdin);

	n = A.Length();
	Str = new char[n];
	for (int i = 0; i < n; i++)
		Str[i] = A.Str[i];
	delete []A.Str;
}

void MyString::Output() {
	cout << Str;
}

int MyString::Length() {
	fflush(stdin);
	int count = 0;
	while (Str[count] != '\0') {
		count++;
	}
	return count - 1;
}

char* MyString::operator+(const MyString& S) {
	int size = S.n + n;
	char* Ans = new char[size];
	int j = 0;
	for (int i = 0; i < n; i++)
		Ans[j++] = Str[i];
	for (int i = 0; i < S.n; i++)
		Ans[j++] = S.Str[i];
	Ans[j] = '\0';
	return Ans;
}

char* MyString::SubString(int Start, int Num)
{
	char* Sub = new char[Num + 1];
	if (Start < 0 || Num + Start > n) {
		cout << "Du lieu truyen vao bi loi. Nhap lai.\n";
		return NULL;
	}
	int j = 0;
	for (int i = Start; i < Start + Num; i++)
		Sub[j++] = Str[i];
	Sub[j] = '\0';
	return Sub;
}

void MyString::Insert(int Pos, char* Add) {
	if (Pos < 0 || Pos > n) {
		cout << "Loi.\n";
		return;
	}

	int count = 0;
	while (Add[count] != '\0')
		count++;

	char* Ans = new char[n + count];
	
	int j = 0;
	for (int i = 0; i < Pos; i++)
		Ans[j++] = Str[i];
	for (int i = 0; i < count; i++)
		Ans[j++] = Add[i];
	for (int i = Pos; i < n; i++)
		Ans[j++] = Str[i];
	Ans[j] = '\0';
	cout << Ans;
	this->GetValue(Ans, j);
}

void MyString::GetValue(char* A, int count) {
	n = count;
	Str = new char[n];
	for (int i = 0; i < count; i++)
		Str[i] = A[i];
	Str[count] = '\0';
}

void MyString::Delete(int Pos, int Num) {
	if (Pos < 0 || Pos > n) {
		cout << "Loi.\n";
		return;
	}

	char* Ans = new char[n - Num];
	int j = 0;
	for (int i = 0; i < Pos; i++)
		Ans[j++] = Str[i];
	for (int i = Pos + Num; i < n; i++)
		Ans[j++] = Str[i];
	
	Ans[j] = '\0';
	cout << Ans;
	this->GetValue(Ans, j);
}

bool MyString::Find(char* Find) {
	for (int i = 0; i < n; i++) {
		if (Find[0] == Str[i]) {
			int Dif = 0;

			int k = 0;
			int j = i;
			
			while (Find[k] != '\0') {
				if (Find[k++] != Str[j++])
					Dif++;
			}
			if (Dif == 0) return true;
		}
	}
	return false;
}

bool MyString::Replace(int Pos, int Num, char* Rep) {
	if (Pos < 0 || Pos > n)
		return false;
	cout << "Hang sau khi xoa : ";
	this->Delete(Pos, Num);
	cout << endl;


	cout << "Hang sau khi them : ";
	this->Insert(Pos, Rep);
	cout << endl;
	return true;
}