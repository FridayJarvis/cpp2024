#include <iostream>

float area_trapeze(float first_side, float second_side, float hight) {
	return (first_side + second_side) / 2 * hight;
}

int main() { // ������� ��������
	setlocale(LC_ALL, "Russian");
	float first_side, second_side, hight;
	std::cout << "������� �������� ������� ���������:" << std::endl;
	std::cin >> first_side;
	std::cout << "������� �������� ������� ���������:" << std::endl;
	std::cin >> second_side;
	std::cout << "��������� ������ ������ ��������:" << std::endl;
	std::cin >> hight;
	
	std::cout << "���������:" << std::endl;
	std::cout << area_trapeze(first_side, second_side,hight) << std::endl;
	return 0;

}