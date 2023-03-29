#include <iostream>

struct DynamicArray {
    int* elements = nullptr;
    unsigned capacity = 0, size = 0;
};

DynamicArray new_array(unsigned size, int init_val = 0) {
    DynamicArray da;
    da.elements = new int[size];
    da.capacity = size;
    da.size = size;
    for (unsigned i = 0; i < size; ++i) {
        da.elements[i] = init_val;
    }
    return da;
}

void erase(DynamicArray& da) {
    delete[] da.elements;
    da.elements = nullptr;
    da.capacity = 0;
    da.size = 0;
}

DynamicArray& reserve(DynamicArray& da, unsigned capacity) {
    if (da.capacity < capacity) {
        int* new_elements = new int[capacity];
        for (unsigned i = 0; i < da.size; ++i) {
            new_elements[i] = da.elements[i];
        }
        delete[] da.elements;
        da.elements = new_elements;
        da.capacity = capacity;
    }
    return da;
}

DynamicArray clone(DynamicArray& da) {
    DynamicArray new_da;
    new_da.elements = new int[da.capacity];
    new_da.capacity = da.capacity;
    new_da.size = da.size;
    for (unsigned i = 0; i < da.size; ++i) {
        if (i < new_da.capacity) {
            new_da.elements[i] = da.elements[i];
        }
    }
    return new_da;
}

DynamicArray& assign(DynamicArray const& src, DynamicArray& dst) {
    if (&src == &dst) {
        return dst;
    }
    erase(dst);
    dst.elements = new int[src.capacity];
    dst.capacity = src.capacity;
    dst.size = src.size;
    for (unsigned i = 0; i < src.size; ++i) {
        if (i < dst.capacity) {
            dst.elements[i] = src.elements[i];
        }
    }
    return dst;
}

DynamicArray& push_back1(DynamicArray& da, int val) {
    if (da.size == da.capacity) {
        reserve(da, da.capacity == da.capacity + 1);
    }
    da.elements[da.size++] = val;
    return da;
}

DynamicArray& push_back2(DynamicArray& da, int val) {
    if (da.size == da.capacity) {
        reserve(da, da.capacity == da.capacity + 5);
    }
    da.elements[da.size++] = val;
    return da;
}

DynamicArray& push_back3(DynamicArray& da, int val) {
    if (da.size == da.capacity) {
        reserve(da, da.capacity == 0 ? 1 : da.capacity * 2);
    }
    da.elements[da.size++] = val;
    return da;
}

void print_arr(DynamicArray& da) {
    for (unsigned i = 0; i < da.size; ++i)
        std::cout << da.elements[i] << " ";
    std::cout << std::endl;
}

int main() {
    int a, init_val = 0, val = 0;
    unsigned capacity = 0, size = 0;
    std::cout << "Create an array. Enter size and init_val" << std::endl;
    std::cin >> size;
    if (size != 0)
        std::cin >> init_val;
    DynamicArray da = new_array(size, init_val);
    std::cout << "Elements of array:" << std::endl;
    print_arr(da);
    DynamicArray new_da = new_array(0);
    std::cout << "Enter a number from 1 to 7 to check:\n1 - erase\n2 - reserve\n3 - clone\n4 - assign\n5 - push_back1\n6 - push_back2\n7 - push_back3" << std::endl;
    std::cin >> a;
    if (a == 1) {
        erase(da);
    }
    if (a == 2) {
        std::cout << "Enter capacity" << std::endl;
        std::cin >> capacity;
        new_da = reserve(da, capacity);
    }
    if (a == 3) {
        new_da = clone(da);
    }
    if (a == 4) {
        new_da = assign(da, new_da);
    }
    if (a == 5) {
        std::cout << "Enter values until it will be -1" << std::endl;
        while (val != -1) {
            std::cin >> val;
            if (val != -1)
                new_da = push_back1(da, val);
        }
    }
    if (a == 6) {
        std::cout << "Enter values until it will be -1" << std::endl;
        while (val != -1) {
            std::cin >> val;
            if (val != -1)
                new_da = push_back2(da, val);
        }
    }
    if (a == 7) {
        std::cout << "Enter values until it will be -1" << std::endl;
        while (val != -1) {
            std::cin >> val;
            if (val != -1)
                new_da = push_back3(da, val);
        }
    }
    std::cout << "Elements of new array:" << std::endl;
    print_arr(new_da);

    return 0;
}