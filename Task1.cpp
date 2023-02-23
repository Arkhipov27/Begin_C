#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

int n = 10000;
int key = 558000000;
int arr[1000000];

int linear_search(int arr[]) {
	for (unsigned i = 0; i <= n; ++i) {
		if (arr[i] == key) {
			//std::cout << "Index of the key: " << i << std::endl;
			return 0;
		}
	}
	//std::cout << "Not found the key" << std::endl;
	return 0;
}

int binary_search(int arr[]) {
	bool flag = false;
	int l = 0;
	int r = n;
	int mid;
	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2;
		if (arr[mid] == key) {
			//std::cout << "Index of the key: " << mid << std::endl;
			flag = true;
		}
		if (arr[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	//std::cout << "Not found the key" << std::endl;
	return 0;
}

int main() {
	unsigned seed = 1005;
	std::default_random_engine rng(seed);
	std::uniform_int_distribution <unsigned> dstr(0, n);

	for (unsigned i = 0; i <= n; ++i) {
		arr[i] = dstr(rng);
	}
	std::sort(arr, arr + n);
	
	auto begin1 = std::chrono::steady_clock::now();
	for (unsigned cnt = 0; cnt <= 10000; ++cnt)
		linear_search(arr);
	auto end1 = std::chrono::steady_clock::now();
	auto time_span1 =
		std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
	std::cout << "\n\n";
	std::cout << time_span1.count() << std::endl;

	
	auto begin2 = std::chrono::steady_clock::now();
	for (unsigned cnt = 0; cnt <= 10000000; ++cnt)
		binary_search(arr);
	auto end2 = std::chrono::steady_clock::now();
	auto time_span2 =
		std::chrono::duration_cast<std::chrono::milliseconds> (end2 - begin2);
	std::cout << "\n\n";
	std::cout << time_span2.count() << std::endl;

	return 0;
}