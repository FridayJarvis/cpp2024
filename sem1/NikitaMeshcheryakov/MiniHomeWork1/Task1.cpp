#include <iostream>

double SquareArea(double squareSide);

int main()
{
	setlocale(LC_ALL, "RU");
	double squareSide;
	std::cout << "������� ������ ������� ��������: ";
	std::cin >> squareSide;
	double squareArea = SquareArea(squareSide);
	std::cout << "������� �������� �����: " << squareArea;
	return 0;
}

double SquareArea(double squareSide)
{
	return squareSide * squareSide;
}