#include <iostream>
#include <random>
#include <chrono>

unsigned begin = 0;
unsigned end = 5000;
unsigned arr[1000000];
bool sorted = false;

void bubble_sort(unsigned arr[], unsigned const begin, unsigned const end) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (unsigned i = begin; i != end - 1; ++i)
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i + 1], arr[i]);
                sorted = false;
            }
    }
}

void forward_step(unsigned arr[], unsigned const begin, unsigned const end) {
    unsigned right = end - 1;
    unsigned left = 1;
    for (unsigned i = left; i <= right; i++) {
        if (arr[i - 1] > arr[i]) {
            std::swap(arr[i - 1], arr[i]);
            sorted = false;
        }
    }
    right--;
}

void backward_step(unsigned arr[], unsigned const begin, unsigned const end) {
    unsigned right = end - 1;
    unsigned left = 1;
    for (unsigned i = right; i >= left; i--) {
        if (arr[i] < arr[i - 1]) {
            std::swap(arr[i], arr[i - 1]);
            sorted = false;
        }
    }
    left++;
}

void shaker_sort(unsigned arr[], unsigned const begin, unsigned const end) {
    while (!sorted) {
        sorted = true;
        forward_step(arr, begin, end);
        backward_step(arr, begin, end);
    }
}

void test(int a, unsigned arr[], unsigned const begin, unsigned const end) {
    if (a == 1 || a == 2 || a == 3) {
        std::cout << "Unsorted array: " << std::endl;
        for (unsigned i = begin; i != end; i++)
            std::cout << arr[i] << ' ';
        std::cout << "\n\n";
        if (a == 1) {
            forward_step(arr, begin, end);
            std::cout << "Result of forward_step: " << std::endl;
            for (unsigned i = begin; i != end; i++)
                std::cout << arr[i] << ' ';
        }
        else if (a == 2) {
            backward_step(arr, begin, end);
            std::cout << "Result of backward_step: " << std::endl;
            for (unsigned i = begin; i != end; i++)
                std::cout << arr[i] << ' ';
        }
        else if (a == 3) {
            shaker_sort(arr, begin, end);
            std::cout << "Result of shaker_sort: " << std::endl;
            for (unsigned i = begin; i != end; i++)
                std::cout << arr[i] << ' ';
        }
    }
    else if (a == 4) {
        std::cout << "Time of bubble_sort: " << std::endl;
        auto begin1 = std::chrono::steady_clock::now();
        for (unsigned cnt = 0; cnt <= 10000; ++cnt)
            bubble_sort(arr, begin, end);
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
            std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
        std::cout << "\n\n";
        std::cout << time_span1.count() << std::endl;
    }
    else if (a == 5) {
        std::cout << "Time of shaker_sort: " << std::endl;
        auto begin1 = std::chrono::steady_clock::now();
        for (unsigned cnt = 0; cnt <= 10000; ++cnt)
            shaker_sort(arr, begin, end);
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
            std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
        std::cout << "\n\n";
        std::cout << time_span1.count() << std::endl;
    }
    else {
        std::cout << "The number is wrong\n";
    }
}

int main() {
    unsigned seed = 1002;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution <unsigned> dstr(begin, end);

    for (unsigned i = begin; i <= end; ++i)
        arr[i] = dstr(rng);
    int a;
    std::cout << "Print a number from 1 to 4 to test:\n 1 - forward_step\n 2 - backward_step\n 3 - shaker_sort\n 4 - time of bubble_sort\n 5 - time of shaker_sort\n To escape press the cross (X)\n";
    while (true) {
        std::cin >> a;
        test(a, arr, begin, end);
        for (unsigned i = begin; i <= end; ++i)
            arr[i] = dstr(rng);
    }
    return 0;
}
