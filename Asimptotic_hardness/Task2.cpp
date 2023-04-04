#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

int n = 200;
int key = 1250000;
int arr[1000000];

int find_pair(int arr[]) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == key) {
				//std::cout << "Your pair: " << arr[i] << '+' << arr[j] << std::endl;
				return 0;
			}
		}
	}
	//std::cout << "Not found any pairs" << std::endl;
	return 0;
}

int find_pair_quickly(int arr[]) {
	int l = 0;
	int r = n - 1;
	while (l != r)
	{
		int sum = arr[l] + arr[r];
		if (sum < key)
			l++;
		else if (sum > key)
			r--;
		else {
			//std::cout << "Your pair: " << arr[l] << '+' << arr[r] << std::endl;
			return 0;
		}
	}
	//std::cout << "Not found any pairs" << std::endl;
	return 0;
}

int main() {
	unsigned seed = 1005;
	std::default_random_engine rng(seed);
	std::uniform_int_distribution <unsigned> dstr(0, n);

	for (unsigned counter = n; counter != 0; --counter) {
		arr[counter] = dstr(rng);
	}
	std::sort(arr, arr + n);
	
	auto begin1 = std::chrono::steady_clock::now();
	for (unsigned cnt = 10000; cnt != 0; --cnt)
		find_pair(arr);
	auto end1 = std::chrono::steady_clock::now();
	auto time_span1 =
		std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
	std::cout << "\n\n";
	std::cout << time_span1.count() << std::endl;


	auto begin2 = std::chrono::steady_clock::now();
	for (unsigned cnt = 100000; cnt != 0; --cnt)
		find_pair_quickly(arr);
	auto end2 = std::chrono::steady_clock::now();
	auto time_span2 =
		std::chrono::duration_cast<std::chrono::milliseconds> (end2 - begin2);
	std::cout << "\n\n";
	std::cout << time_span2.count() << std::endl;
	
	/*
	for (unsigned i = 100; i <= 120; i++) {
		std::cout << arr[i] << ',';
	}
	*/
	return 0;
}