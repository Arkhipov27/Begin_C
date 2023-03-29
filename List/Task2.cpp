#include <iostream>
#include <chrono>

struct LinkedList {
	int data;
	LinkedList* next;
};

LinkedList* RingList(int n) {
	if (n == 0)
		return nullptr;
	LinkedList* t = new LinkedList{ 1, nullptr };
	t->next = t;
	LinkedList* x = t;
	for (int i = 2; i <= n; i++)
		x = (x->next = new LinkedList{ i, t });
	return t;
}

int FlavList(int n, int m) {
	LinkedList* x = RingList(n);
	int i;
	for (i = 1; i < m - 1; i++)
		x = x->next;
	x->next = x->next->next;
	while (x != x->next) {
		for (i = 1; i < m; i++)
			x = x->next;
		x->next = x->next->next;
	}
	return x->data;
}

int FlavArr(int n, int m) {
	int* arr = new int[n];
	int i, cnt = 0, a = (m - 1) % n;
	for (i = 0; i < n; i++)
		arr[i] = i + 1;
	while (cnt < n - 1) {
		for (i = a; i < n - 1 - cnt; i++)
			arr[i] = arr[i + 1];
		cnt++;
		a += m - 1;
		a = a % (n - cnt);
	}
	return arr[0];
}

void print_ring(LinkedList* ring) {
	if (nullptr == ring)
		return;
	std::cout << ring->data << ' ';
	LinkedList* curr = ring->next;
	while (ring != curr) {
		std::cout << curr->data << ' ';
		curr = curr->next;
	}
}

void test(int n, int m, int a) {
	int res;
	if (a == 1) {
		res = FlavList(n, m);
		std::cout << "The solution of the Flavius' problem: " << res << std::endl;
	}
	else if (a == 2) {
		res = FlavArr(n, m);
		std::cout << "The solution of the Flavius' problem: " << res << std::endl;
	}
	else if (a == 3) {
		std::cout << "Time of FlavList: " << std::endl;
		auto begin1 = std::chrono::steady_clock::now();
		for (unsigned cnt = 0; cnt <= 1000; ++cnt)
			FlavList(n, m);
		auto end1 = std::chrono::steady_clock::now();
		auto time_span1 =
			std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
		std::cout << "\n\n";
		std::cout << time_span1.count() << std::endl;
	}
	else if (a == 4) {
		std::cout << "Time of FlavArr: " << std::endl;
		auto begin1 = std::chrono::steady_clock::now();
		for (unsigned cnt = 0; cnt <= 1000; ++cnt)
			FlavArr(n, m);
		auto end1 = std::chrono::steady_clock::now();
		auto time_span1 =
			std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
		std::cout << "\n\n";
		std::cout << time_span1.count() << std::endl;
	}
	else
		std::cout << "The number must be from 1 to 4" << std::endl;
}

int main() {
	int n, m, a;
	std::cout << "Enter two numbers: number of people in the circle (n > 0) and the step (m > 0)" << std::endl;
	std::cin >> n >> m;
	if (n < 1 || m < 1) {
		std::cout << "Inavlid values of n or m" << std::endl;
		return 0;
	}
	std::cout << "Enter the number from 1 to 4 to check:\n1 - FlavList\n2 - FlavArr\n3 - time of FlavList\n4 - time of FlavArr" << std::endl;
	std::cin >> a;
	test(n, m, a);
	return 0;
}