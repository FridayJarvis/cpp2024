#include <iostream>

int fibbRow() {
	int N;
	unsigned long long int nextn;  //nextn - ��������� �����
	unsigned long long int prev1 = 1; //prev1 - ���������� �����
	unsigned long long int prev2 = 0; //prev2 - ���������� �� 2 ����� ������� �� ��������
	std::cout << "Enter the length of Fibonacci row:" << std::endl;
	std::cin >> N;
	if (N >= 94) {
		std::cout << "The data type does not allow counting a row greater than 93 "; //�.�. ������������ �������� unsigned long long int - 2^64, ��� ������ 94-�� ����� ���������
		return 0;
	}
	for (int i = 1; i <= N; ++i) {
		nextn = prev1 + prev2;
		prev1 = prev2;
		prev2 = nextn;
		std::cout << nextn << " ";
	}
	return 0;
}

int main() {
	fibbRow();
}