#include <iostream>
#include <chrono>
#include <random>

int n = 100000; //количество элементов в исходном массиве arr и в массиве счетчиков count
int m = 10000; //количество элементов в массиве ключей key
int key[1000000];
int arr[1000000];
int count[1000000];

int linear_search(int arr[], int key[], unsigned cnt) {
	for (unsigned i = 0; i <= n; ++i) {
		if (arr[i] == key[cnt]) {
			//std::cout << "Index of the key: " << i << std::endl;
			return 0;
		}
	}
	//std::cout << "Not found the key" << std::endl;
	return 0;
}

int linear_search_a(int arr[], int key[], unsigned cnt) {
	for (unsigned i = 0; i <= n; ++i) {
		if (arr[i] == key[cnt] && i != 0) {
			int a = arr[1];
			arr[1] = arr[i];
			arr[i] = a;
			//std::cout << "Index of the key: " << i << std::endl;
			return 0;
		}
	}
	//std::cout << "Not found the key" << std::endl;
	return 0;
}

int linear_search_b(int arr[], int key[], unsigned cnt) {
	for (unsigned i = 0; i <= n; ++i) {
		if (arr[i] == key[cnt] && i != 0) {
			int a = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = a;
			//std::cout << "Index of the key: " << i << std::endl;
			return 0;
		}
	}
	//std::cout << "Not found the key" << std::endl;
	return 0;
}

int linear_search_c(int arr[],int key[], int count[], unsigned cnt) {
	for (unsigned i = 0; i <= n; ++i) {
		if (arr[i] == key[cnt]) {
			//std::cout << "Index of the key: " << i << std::endl;
			if (i != 0 && count[i] > count[i - 1]) {
				int a = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = a;
				++count[i - 1];
			}
			else
				++count[i];
			return 0;
		}
	}
	//std::cout << "Not found the key" << std::endl;
	return 0;
}

int main() {
	// заполнение исходного массива рандомными числами
	unsigned seed = 1005;
	std::default_random_engine rng(seed);
	std::uniform_int_distribution <unsigned> dstr(0, n);

	for (unsigned i = 0; i <= n; ++i) {
		arr[i] = dstr(rng);
	}
	
	//заполнение массива значений рандомными числами
	//(с равномерным и неравномерным распределением)
	unsigned seed_key = 105;
	std::default_random_engine rng2(seed_key);
	std::uniform_int_distribution <unsigned> dstr2(0, n);

	for (unsigned i = 0; i <= m/4; ++i) {
		key[i] = dstr2(rng2);
	}
	for (unsigned i = m / 4 + 1; i <= m / 2; ++i) {
		key[i] = dstr2(rng2);
	}
	for (unsigned i = m/2 + 1; i <= 3*m / 4; ++i) {
		key[i] = 56843;
	}
	for (unsigned i = 3*m / 4 + 1; i <= m; ++i) {
		key[i] = 61739;
	}

	// заполнение массива счетчиков нулями
	for (unsigned i = 0; i <= n; ++i) {
		count[i] = 0;
	}
	
	auto begin = std::chrono::steady_clock::now();
	for (unsigned cnt = 0; cnt <= m; ++cnt)
		linear_search(arr, key, cnt);
	auto end = std::chrono::steady_clock::now();
	auto time_span =
		std::chrono::duration_cast<std::chrono::milliseconds> (end - begin);
	std::cout << "\n\n";
	std::cout << time_span.count() << std::endl;


	auto begin1 = std::chrono::steady_clock::now();
	for (unsigned cnt = 0; cnt <= m; ++cnt)
		linear_search_a(arr, key, cnt);
	auto end1 = std::chrono::steady_clock::now();
	auto time_span1 =
		std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
	std::cout << "\n\n";
	std::cout << time_span1.count() << std::endl;


	auto begin2 = std::chrono::steady_clock::now();
	for (unsigned cnt = 0; cnt <= m; ++cnt)
		linear_search_b(arr, key, cnt);
	auto end2 = std::chrono::steady_clock::now();
	auto time_span2 =
		std::chrono::duration_cast<std::chrono::milliseconds> (end2 - begin2);
	std::cout << "\n\n";
	std::cout << time_span2.count() << std::endl;


	auto begin3 = std::chrono::steady_clock::now();
	for (unsigned cnt = 0; cnt <= m; ++cnt)
		linear_search_c(arr, key, count, cnt);
	auto end3 = std::chrono::steady_clock::now();
	auto time_span3 =
		std::chrono::duration_cast<std::chrono::milliseconds> (end3 - begin3);
	std::cout << "\n\n";
	std::cout << time_span3.count() << std::endl;
	
	/*
	for (unsigned i = 10000; i <= 10020; ++i) {
		std::cout << arr[i] << ',';
	}
	*/
	return 0;
}