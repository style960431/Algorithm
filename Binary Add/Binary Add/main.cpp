//
//  main.cpp
//  Binary Add
//
//  Created by 王宗祥 on 2020/11/27.
//

#include <iostream>
using namespace std;

int binary_add(int* A, int* B, int n) {
    int* sum = new int[n + 1];
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum[i + 1] = ((A[i] ^ B[i]) ^ carry);
        carry = ((A[i] & B[i]) | ((A[i] ^ B[i]) & carry));
    }
    sum[0] = carry;
    for (int i = 0; i <= n; i++) {
        cout << sum[i];
    }
    cout << endl;
    return 0;
}

int main() {
    int n;
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int* B = new int[n];
    for (int j = 0; j < n; j++) {
        cin >> B[j];
    }
    binary_add(A, B, n);
    return 0;
}

