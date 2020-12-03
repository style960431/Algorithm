//
//  main.cpp
//  Xor Swap
//
//  Created by 王宗祥 on 2020/11/27.
//

#include <iostream>
using namespace std;

void xorSwap(int* x, int* y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

int main() {
    int a = 2, b = 1;
    cout << a << " " << b << endl;
    xorSwap(&a, &b);
    cout << a << " " << b << endl;

    return 0;
}
