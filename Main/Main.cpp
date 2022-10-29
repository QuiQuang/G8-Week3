#include "MyString.h"

int main() {
	MyString A, B;

	A.Input();
	B.Input();

	cout << "Ket hop 2 chuoi A va B : " << A + B << endl;
	cout << "Lay 3 gia tri tu vi tri so 2 : " << A.SubString(2, 3) << endl;

	/*char Add[] = "DU LUON";
	A.Insert(5, Add);
	cout << endl;

	A.Delete(2, 3);
	cout << endl;*/
	
	cout << "Kiem tra ton tai \"Hoang\" trong chuoi :\n";
	char FindSub[] = "Hoang";
	if (A.Find(FindSub)) cout << "Ton tai.\n";
	else cout << "Khong ton tai.\n";

	cout << "Kiem tra thay the 2 gia tri dau thanh chu \"Hoang\" trong chuoi : ";
	if (A.Replace(0,2,FindSub)) cout << "Thay the thanh cong.\n";
	else cout << "Khong ton tai.\n";
	return 0;
}