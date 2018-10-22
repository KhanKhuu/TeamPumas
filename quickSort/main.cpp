#include <iostream>
#include "QuickSort.h"
#include <random>
using namespace std;

const int SIZE = 10;

    template <typename T>
    void createRandomArray(T* items, int size) {
        random_device rd;
        default_random_engine generator (rd());
        uniform_int_distribution<T> distribution (0, 9);
        for (int i = 0; i < SIZE; i++) {
            *(items + i) = distribution(generator);
        }
    }
    
    template <typename T>
    void displayArray(T* items, int size) {
        for (int i = 0; i < size; i++) {
            cout << *(items + i) << " ";
        }
        cout << endl;
    }
    
int main() {
    /*
    int ints[SIZE];
    createRandomArray(ints, SIZE);
    displayArray(ints, SIZE);
    quickSort(ints, SIZE);
    displayArray(ints, SIZE);*/
    cout << median(9, 5, 9) << endl;
}

