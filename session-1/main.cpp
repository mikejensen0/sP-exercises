#include <iostream>
#include <chrono>
#include <vector>
#include <utility>
#include <cstring>
#include <string.h>
#include "1.3.h"

using namespace std::chrono;
using namespace std;

constexpr int arr_size = 10'000'000;
int c_arr[arr_size];
vector<int> vec(arr_size);

void swap_ends(int arr[], int size) {
    for (int i = size/2 - 1, j = size - 1; i >= 0; --i, --j)
        swap(arr[i], arr[j]);
}

void swap_ends(vector<int>& arr) { // overloading the same fn-name
    for (int i = arr.size()/2 - 1, j = arr.size() - 1; i >= 0; --i, --j)
        swap(arr[i], arr[j]);
}

void swap_ends_memcpy_static(char dest[], char src[]) {
    cout << "Src: " << src << endl;
    cout << "Dest: " << dest << endl;

    memcpy(dest, src, 5*sizeof(int)/2); // first half
    memcpy(dest + 5*sizeof(int)/2, src + 5*sizeof(int)/2, 5*sizeof(int)/2); // second half
    // swap and combine
    memcpy(dest + 5*sizeof(int)/2, src, 5*sizeof(int)/2);

    cout << "Src: " << src << endl;
    cout << "Dest: " << dest << endl;
}

void swap_ends_memcpy_dynamic() {

}
int main(){
    // 1.2
    // The cache needs to be "warmed up" before use
    swap_ends(c_arr, arr_size);
    swap_ends(c_arr, arr_size);
    swap_ends(c_arr, arr_size);
    swap_ends(c_arr, arr_size);

    auto t0 = high_resolution_clock::now();
    swap_ends(c_arr, arr_size);
    auto t1 = high_resolution_clock::now();
    std::cout << duration<double, std::milli>(t1-t0).count() << "ms\n";

    // Warmup 2
    swap_ends(vec);
    swap_ends(vec);
    swap_ends(vec);
    swap_ends(vec);

    auto t2 = high_resolution_clock::now();
    swap_ends(vec);
    auto t3 = high_resolution_clock::now();
    std::cout << duration<double, std::milli>(t3-t2).count() << "ms\n";

    // Both are just about equally fast

    // Moving the vec to stack changes nothing, as only the pointer is moved to the stack, which changes nothing
    // On the other hand, moving the c_arr to the stack is not possible, as it is too large

    // Static
    char buffer[1000];
    char testarr[] = "testing";
    auto t4 = high_resolution_clock::now();
    swap_ends_memcpy_static(buffer, testarr);
    auto t5 = high_resolution_clock::now();
    std::cout << duration<double, std::milli>(t5-t4).count() << "ms\n";
    cout << "Static Memcpy Result: " << buffer << endl;


    // Dynamic

}


