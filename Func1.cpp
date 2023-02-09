#include <iostream>

int gcd(int a, int b) {
	int f1 = std::min(a, b);
	a = std::max(a, b);
	b = f1;
	while (b != 0) {
		int f2 = b;
		b = a % b;
		a = f2;
	}
	return a;
}

int main() {
	int a, b;
	std::cout << "Enter two numbers" << std::endl;
	std::cin >> a >> b;
	int ans = gcd(a, b);
	std::cout << "The greatest common devisor: " << ans << std::endl;
	return 0;
}