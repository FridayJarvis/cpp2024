#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ���� ����� � �������� ������������� �������:";
	int N, N_reversed, memory;
	N_reversed = 0;
	std::cin >> N;
	while (N != 0) {
		memory = N % 10;
		N_reversed = N_reversed * 10 + memory;
		N = N / 10;
	}
	std::cout << "������������� ����� :" << N_reversed << std::endl;
	return 0;

}