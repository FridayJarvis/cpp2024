﻿// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using std::cin;
using std::cout;

void TrapezoidArea() {
    int base1 = 0;
    int base2 = 0;
    int height = 0;
    cin >> base1;
    cout << "Enter the length of the second base of the trapezoid";
    cin >> base2;
    cout << "Enter the length of the trapezoid height";
    cin >> height;
    cout << "Trapezoid area:";
    cout << (((base1 + base2)/2) * height);
    return;

}
int main()
{
    cout << "Enter the length of the first base of the trapezoid";
    TrapezoidArea();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
