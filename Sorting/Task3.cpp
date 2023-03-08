#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

unsigned const begin = 0;
unsigned const end = 100;
unsigned arr[10000000];
unsigned swap_count = 0;


void insert_sort(unsigned arr[], unsigned const begin, unsigned const end) {
    for (unsigned j = end - 1; j != begin; --j)
        for (unsigned i = j - 1; i != end - 1; ++i) {
            if (arr[i] <= arr[i + 1])
                break;
            std::swap(arr[i], arr[i + 1]);
            swap_count++;
        }
}

void shell_sort_1(unsigned arr[], unsigned const begin, unsigned const end) {
    unsigned i, j, step = end, tmp;
    while (step != 1) {
        for (i = begin + step; i < end; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step]) {
                    arr[j] = arr[j - step];
                    swap_count++;
                }
                else
                    break;
            }
            arr[j] = tmp;
        }
        step /= 2;
    }
    insert_sort(arr, begin, end);
}

unsigned inc, step;
void shell_sort_2(unsigned arr[], unsigned const begin, unsigned const end) {
    unsigned i, j, tmp;
    //inc = (unsigned)std::log2(end + 1);
    //step = (unsigned)std::pow(2, inc) - 1;
    while (step != 1) {
        for (i = begin + step; i < end; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step]) {
                    arr[j] = arr[j - step];
                    swap_count++;
                }
                else
                    break;
            }
            arr[j] = tmp;
        }
        step /= 2;
    }
    insert_sort(arr, begin, end);
}

unsigned fibonacci(unsigned k) {
    if (k == 0) return 0;
    if (k == 1 || k == 2) return 1;
    return fibonacci(k - 1) + fibonacci(k - 2);
}

unsigned k = 0;
void shell_sort_3(unsigned arr[], unsigned const begin, unsigned const end) {
    unsigned i, j, tmp;
    //while (fibonacci(k) <= end)
    //    k++;
    //step = fibonacci(k);
    while (step != 1) {
        for (i = begin + step; i < end; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step]) {
                    arr[j] = arr[j - step];
                    swap_count++;
                }
                else
                    break;
            }
            arr[j] = tmp;
        }
        k--;
        step = fibonacci(k);
    }
    insert_sort(arr, begin, end);
}

void test(int a, unsigned arr[], unsigned const begin, unsigned const end) {
    if (a == 0 || a == 1 || a == 2 || a == 3) {
        std::cout << "Unsorted array: " << std::endl;
        for (unsigned i = begin; i != end; i++)
            std::cout << arr[i] << ' ';
        std::cout << "\n\n";
        if (a == 0) {
            insert_sort(arr, begin, end);
            std::cout << "Result of insert_sort: " << std::endl;
            for (unsigned i = begin; i != end; i++)
                std::cout << arr[i] << ' ';
        }
        else if (a == 1) {
            shell_sort_1(arr, begin, end);
            std::cout << "Result of shell_sort_1: " << std::endl;
            for (unsigned i = begin; i != end; i++)
                std::cout << arr[i] << ' ';
        }
        else if (a == 2) {
            inc = (unsigned)std::log2(end + 1);
            step = (unsigned)std::pow(2, inc) - 1;
            shell_sort_2(arr, begin, end);
            std::cout << "Result of shell_sort_2: " << std::endl;
            for (unsigned i = begin; i != end; i++)
                std::cout << arr[i] << ' ';
        }
        else if (a == 3) {
            while (fibonacci(k) <= end)
                k++;
            step = fibonacci(k);
            shell_sort_3(arr, begin, end);
            std::cout << "Result of shell_sort_3: " << std::endl;
            for (unsigned i = begin; i != end; i++)
                std::cout << arr[i] << ' ';
        }
        std::cout << "\nNumber of swaps: " << swap_count << std::endl;
    }
    else if (a == 4) {
        std::cout << "Time of insert_sort: " << std::endl;
        auto begin1 = std::chrono::steady_clock::now();
        for (unsigned cnt = 0; cnt <= 1000; ++cnt)
            insert_sort(arr, begin, end);
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
            std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
        std::cout << "\n\n";
        std::cout << time_span1.count() << std::endl;
    }
    else if (a == 5) {
        std::cout << "Time of shell_sort_1: " << std::endl;
        auto begin1 = std::chrono::steady_clock::now();
        for (unsigned cnt = 0; cnt <= 1000; ++cnt)
            shell_sort_1(arr, begin, end);
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
            std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
        std::cout << "\n\n";
        std::cout << time_span1.count() << std::endl;
    }
    else if (a == 6) {
        inc = (unsigned)std::log2(end + 1);
        step = (unsigned)std::pow(2, inc) - 1;
        std::cout << "Time of shell_sort_2: " << std::endl;
        auto begin1 = std::chrono::steady_clock::now();
        for (unsigned cnt = 0; cnt <= 1000; ++cnt)
            shell_sort_2(arr, begin, end);
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
            std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
        std::cout << "\n\n";
        std::cout << time_span1.count() << std::endl;
    }
    else if (a == 7) {
        while (fibonacci(k) <= end)
            k++;
        step = fibonacci(k);
        std::cout << "Time of shell_sort_3: " << std::endl;
        auto begin1 = std::chrono::steady_clock::now();
        for (unsigned cnt = 0; cnt <= 1000; ++cnt)
            shell_sort_3(arr, begin, end);
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
            std::chrono::duration_cast<std::chrono::milliseconds> (end1 - begin1);
        std::cout << "\n\n";
        std::cout << time_span1.count() << std::endl;
    }
    else if (a == 8) {
        insert_sort(arr, begin, end);
        std::cout << "\nNumber of swaps in bubble_sort: " << swap_count << std::endl;
    }
    else if (a == 9) {
        shell_sort_1(arr, begin, end);
        std::cout << "\nNumber of swaps in shell_sort_1: " << swap_count << std::endl;
    }
    else if (a == 10) {
        inc = (unsigned)std::log2(end + 1);
        step = (unsigned)std::pow(2, inc) - 1;
        shell_sort_2(arr, begin, end);
        std::cout << "\nNumber of swaps in shell_sort_2: " << swap_count << std::endl;
    }
    else if (a == 11) {
        while (fibonacci(k) <= end)
            k++;
        step = fibonacci(k);
        shell_sort_3(arr, begin, end);
        std::cout << "\nNumber of swaps in shell_sort_3: " << swap_count << std::endl;
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
    std::cout << "Print a number from 0 to 11 to test:\n 0 - insert_sort\n 1 - shell_sort_1\n 2 - shell_sort_2\n 3 - shell_sort_3\n 4 - time of insert_sort\n 5 - time of shell_sort_1\n 6 - time of shell_sort_2\n 7 - time of shell_sort_3\n 8 - number of swaps in insert_sort\n 9 - number of swaps in shell_sort_1\n 10 - number of swaps in shell_sort_2\n 11 - number of swaps in shell_sort_3\n To escape press the cross (X)\n";
    while (true) {
        std::cin >> a;
        test(a, arr, begin, end);
        swap_count = 0;
        for (unsigned i = begin; i <= end; ++i)
            arr[i] = dstr(rng);
    }
    return 0;
}