#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() // �� ��������������
{
    setlocale(LC_ALL, "Russian");
    cout << "������� ����� ������� ������ �����������" << endl;
    int cat;
    int dog = 0;
    cin >> cat;
    while (cat > 0) { // ���� ������� ���� ���� �����
        dog *= 10; // �������� �� 10
        dog += cat % 10; // ��������� ������� �� ������� ����
        cat /= 10; // ����� ����
    }
    cout << dog; // ��� � ������ 
}
