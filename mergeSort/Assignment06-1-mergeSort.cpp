/********************************************************************
 Problem: Assignment 6 - Merge Sort
 Question: Implement the merge sort algorithm using built-in arrays,
 and the mergeSort code structure provided in lecture.
 Name: Team Pumas (Matthew Larkins and Michaela Vuklisevicova)
 ID: 1687673 & 1583978
 Date: 10/20/2018
 Status: complete
 *******************************************************************/

#include <cstring>
#include <iostream>
#include <random>
using namespace std;

const int SIZE = 20;

template <typename T>
void merge(T *items, const int low, const int endOfFirstHalf,
           const int beginningOfSecondHalf, const int high) {
    int totalSize = high - low + 1;
    T sortedArray[totalSize];
    int lowCopy = low; //make a copy of low that we can manipulate
    int beginningOfSecondHalfCopy = beginningOfSecondHalf; //create a
    //copy of beginningOfSecondHalf that we can manipulate
    for (int i = 0; i < totalSize; i++) {
        //the if condition ensures that each sub-array's values
        //are compared and assigned to sortedArray appropriately
        //until either sub-array reaches its end...remaining values
        //from the other sub-array are then appended to sortedArray
        if ((lowCopy <= endOfFirstHalf && items[lowCopy] <
             items[beginningOfSecondHalfCopy]) ||
            beginningOfSecondHalfCopy > high) {
            sortedArray[i] = items[lowCopy];
            lowCopy++;
        }
        else {
            sortedArray[i] = items[beginningOfSecondHalfCopy];
            beginningOfSecondHalfCopy++;
        }
    }
    memcpy(items + low, sortedArray, totalSize * sizeof(T));
}

template <typename T>
void mergeSort(T *items, int low, int high) {
    if (high - low > 0) { //if not the base case,
        //then split items in half and sort each half
        int endOfFirstHalf = (low + high) / 2; //calculate the middle
        int beginningOfSecondHalf = endOfFirstHalf +
        1; //calculate the next one over
        mergeSort(items, low, endOfFirstHalf); //sort the first half
        mergeSort(items , beginningOfSecondHalf, high); //second half
        merge(items, low, endOfFirstHalf, beginningOfSecondHalf,
              high);
    } //end if
}


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
    int ints[SIZE];
    createRandomArray(ints, SIZE);
    displayArray(ints, SIZE);
    mergeSort(ints, 0, SIZE - 1);
    displayArray(ints, SIZE);
}
