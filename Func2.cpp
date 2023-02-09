#include <iostream>
int max = 0, k = 0;

int max_counter() {
	int a = 1;
	while (a != 0) {
		std::cin >> a;
		if (a > max) {
			max = a;
			k = 0;
		}
		if (a == max) {
			k++;
		}
	}
	return 0;
}

int main() {
	std::cout << "Enter the sequence of numbers" << std::endl;
	max_counter();
	std::cout << "The greatest number: " << max << std::endl << "Was found " << k << " times" << std::endl;
	return 0;
}