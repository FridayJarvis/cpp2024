#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::oct;
using std::hex;
using std::dec;


int main()
{
	setlocale(LC_ALL, "Russian");
	int chislo;
	cout << "������� ����� � 10-������ ������� ����������" << endl;
	cin >> chislo;
	cout << "8-������ � 16-������ �������������" << endl;
	cout << oct << chislo << dec << hex  << " " << chislo;
}