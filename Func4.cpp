#include <iostream>
long long i = 0, j = 0, k = 0;

int three_cubes(int a) {
	int f = 0;
	for (i = 0; i <= a; i++) {
		if (f == 1) {
			i--;
			break;
		}
		else {
			for (j = 0; j <= a; j++) {
				if (f == 1) {
					j--;
					break;
				}
				else {
					for (k = 0; k <= a; k++) {
						if (a == i * i*i + j * j*j + k * k*k) {
							f = 1;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	int a;
	std::cout << "Enter a number" << std::endl;
	std::cin >> a;
	three_cubes(a);
	if (a != i * i * i + j * j * j + k * k * k) {
		std::cout << "False" << std::endl;
	}
	else {
		std::cout << "True" << std::endl << "Sum of three cubes: " << i * i * i << '+' << j * j * j << '+' << k * k * k << std::endl;
	}
	return 0;
}