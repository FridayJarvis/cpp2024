#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main2() // �� ������� ������������ �������� ����� ��������� �������� �� ������
{
	setlocale(LC_ALL, "Russian");
	int cat_base1; // �����_����
	int cat_base2; // �����_����
	int high_cat; // �������_�����
	cout << "������� ������ ��������� ��������" << endl;
	cin >> cat_base1;
	cout << "������� ������ ��������� ��������" << endl;
	cin >> cat_base2;
	cout << "������� ������" << endl;
	cin >> high_cat;
	cout << ((cat_base1 + cat_base2) / 2) * high_cat;
}