#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");
	int chislo;
	cout << "�������� �������� �������. ������� ����� ����������� �����" << endl;	
	cin >> chislo;
	
	while (chislo != 1) {
		if (chislo % 2 == 0){
			chislo = chislo / 2;
		} else {
			chislo = (chislo * 3 + 1) / 2;
		}
	}
	cout << "��� ��� ��������" << endl;
	cout << chislo;
}