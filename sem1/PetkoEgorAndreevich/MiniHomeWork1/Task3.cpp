#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() // ������ ���������
{
    setlocale(LC_ALL, "Russian");
    int cata = 0; //���������
    int catb = 1; //�����_�_����_����
    int catc; //�����_�
    int catx; //�����_���
    cout << "������� ������������ ���������" << endl;
    cin >> catx;
    cout << 1 << " ";
    for (int i = 0; i < catx - 1; ++i) {
        catc = cata + catb; 
        cata = catb;
        catb = catc; 
        cout << catc << " ";
    }
}
 