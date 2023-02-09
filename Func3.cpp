#include <iostream>
int i, j, k, l;

int four_squares(int a) {
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
						if (f == 1) {
							k--;
							break;
						}
						else {
							for (l = 0; l <= a; l++) {
								if (a == i * i + j * j + k * k + l * l) {
									f = 1;
									break;
								}
							}
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
	four_squares(a);
	std::cout << "Sum of four squares: " << i*i << '+' << j*j << '+' << k*k << '+' << l*l << std::endl;
	return 0;
}