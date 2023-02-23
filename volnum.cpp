#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int SIZE = 10;
    int nums[SIZE];

    // Leer los 10 números enteros
    cout << "Ingrese 10 numeros enteros:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> nums[i];
    }

    // Ordenar los números de mayor a menor
    sort(nums, nums + SIZE, greater<int>());

    // Encontrar los tres mayores números pares
    int count = 0;
    cout << "Los tres mayores numeros pares son:" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (nums[i] % 2 == 0 && count < 3) {
            cout << nums[i] << endl;
            count++;
        }
    }

    return 0;
}

