#include <iostream>
int main() { // ����� ����� ��������
	setlocale(LC_ALL, "Russian");
	int N, a, b, c;
	std::cout << "������� ����������� ��� ����������� ����� ��������:";
	std::cin >> N;
	a = 0;
	b = 1;
	c = 0;
	std::cout << b << std::endl;
	for (int i = 1; i < N; i++) {
		c = a + b;
		std::cout << c << std::endl;
		a = b;
		b = c;
	}
	return 0;
}