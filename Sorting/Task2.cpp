#include <iostream>
#include <random>
#include <chrono>

unsigned const begin = 0;
unsigned const end = 100;
unsigned arr[1000000];
unsigned swap_count = 0;
bool sorted = false;

void bubble_sort(unsigned arr[], unsigned const begin, unsigned const end) {
    while (!sorted) {
        sorted = true;
        for (unsigned i = begin; i != end - 1; ++i)
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swap_count++;
                sorted = false;
            }
    }
}

void check_with_step(unsigned arr[], unsigned const begin, unsigned const end, unsigned step) {
    for (unsigned i = begin; i < end - step; ++i) {
        if (arr[i] > arr[i + step]) {
            std::swap(arr[i], arr[i + step]);
            swap_count++;
            sorted = false;
        }
    }
}

void comb_sort(unsigned arr[], unsigned const begin, unsigned const end)
{
    unsigned step = end;
    while (step != 1 && !sorted) {
        sorted = true;
        step /= 2;
        check_with_step(arr, begin, end, step);
    }
    sorted = false;
    bubble_sort(arr, begin, end);
}

void test(int a, unsigned arr[], unsigned const begin, unsigned const end) {
    if (a == 1) {
        std::cout << "Unsorted array: " << std::endl;
        for (unsigned i = begin; i != end; i++)
            std::cout << arr[i] << ' ';
        std::cout << "\n\n";
        bubble_sort(arr, begin, end);
        std::cout << "Result of bubble_sort: " << std::endl;
        for (unsigned i = begin; i != end; i++)
            std::cout << arr[i] << ' ';
    }
    else if (a == 2) {
        std::cout << "Unsorted array: " << std::endl;
        for (unsigned i = begin; i != end; i++)
            std::cout << arr[i] << ' ';
        std::cout << "\n\n";
        comb_sort(arr, begin, end);
        std::cout << "Result of comb_sort: " << std::endl;
        for (unsigned i = begin; i != end; i++)
            std::cout << arr[i] << ' ';
    }
    else if (a == 3) {
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
    else if (a == 4) {
        std::cout << "Time of comb_sort: " << std::endl;
        auto begin1 = std::chrono::steady_clock::now();
        for (unsigned cnt = 0; cnt <= 10000; ++cnt)
            comb_sort(arr, begin, end);
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
            std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
        std::cout << "\n\n";
        std::cout << time_span1.count() << std::endl;
    }
    else if (a == 5) {
        bubble_sort(arr, begin, end);
        std::cout << "\nNumber of swaps in bubble_sort: " << swap_count << std::endl;
    }
    else if (a == 6) {
        comb_sort(arr, begin, end);
        std::cout << "\nNumber of swaps in comb_sort: " << swap_count << std::endl;
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
    std::cout << "Print a number from 1 to 6 to test:\n 1 - bubble_sort\n 2 - comb_sort\n 3 - time of bubble_sort\n 4 - time of comb_sort\n 5 - number of swaps in bubble_sort\n 6 - number of swaps in comb_sort\n To escape press the cross (X)\n";
    while (true) {
        std::cin >> a;
        test(a, arr, begin, end);
        swap_count = 0;
        for (unsigned i = begin; i <= end; ++i)
            arr[i] = dstr(rng);
    }
    return 0;
}