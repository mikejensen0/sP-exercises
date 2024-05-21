
#include <iostream>
#include <limits>
#include <bitset>

using namespace std;

void typeSizesAndLimits(){
    // C++ has the following fundamental types:
    cout << "The size of bool is (bytes):   " << sizeof(bool) << endl;
    cout << "The size of int is (bytes):    " << sizeof(int) << endl;
    cout << "The size of float is (bytes):  " << sizeof(float) << endl;
    cout << "The size of short is (bytes):  " << sizeof(short) << endl;
    cout << "The size of double is (bytes): " << sizeof(double) << endl;
    cout << "The size of long is (bytes):   " << sizeof(long) << endl;
    cout << "The size of long long is (bytes): " << sizeof(long long) << endl;
    cout << "The size of long double is (bytes): " << sizeof(long double) << endl;
    cout << "The size of char is (bytes):   " << sizeof(char) << endl;
    cout << "The size of string is (bytes): " << sizeof(string) << endl;

    // Of which the following are numerics:
    // char, short, int, long, long long, float, double, long double

    numeric_limits<char> char_limits;
    numeric_limits<short> short_limits;
    numeric_limits<int> int_limits;
    numeric_limits<long> long_limits;
    numeric_limits<long long> long_long_limits;
    numeric_limits<float> float_limits;
    numeric_limits<double> double_limits;
    numeric_limits<long double> long_double_limits;

    cout << "The char range is from " << char_limits.min() << " to " << char_limits.max() << endl;
    cout << "The short range is from " << short_limits.min() << " to " << short_limits.max() << endl;
    cout << "The int range is from " << int_limits.min() << " to " << int_limits.max() << endl;
    cout << "The long range is from " << long_limits.min() << " to " << long_limits.max() << endl;
    cout << "The long long range is from " << long_long_limits.min() << " to " << long_long_limits.max() << endl;
    cout << "The float range is from " << float_limits.min() << " to " << float_limits.max() << endl;
    cout << "The double range is from " << double_limits.min() << " to " << double_limits.max() << endl;
    cout << "The long double range is from " << long_double_limits.min() << " to " << long_double_limits.max() << endl;
}

void printBits(unsigned int value) {
    std::bitset<32> bits(value);
    std::cout << bits << std::endl;
}

void memoryLayout(){
    union u {
        float floatVal;
        unsigned int intVal;
        char c[4];
    };
    u u1{}; // initialize the union

    u1.intVal = 0x12345678;

    for (int i = 0; i < sizeof(u1.c); i++){
        cout << "Byte " << i << " is " << (int)u1.c[i] << endl;
    }
    // The endianess is little endian as the least significant byte is stored first

    // std bitset
    float values[] = {1.0f, 2.0f, 4.0f, 8.0f};

    for (float value : values) {
        u1.floatVal = value;
        cout << "Float: " << value << " -> Unsigned int: " << u1.intVal << endl;
        printBits(u1.intVal);
    }

}

int main(){
    //typeSizesAndLimits(); // 2.1
    memoryLayout(); // 2.2
    return 0;
}
