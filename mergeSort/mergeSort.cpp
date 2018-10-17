#include <iostream>
#include <cstring>
using namespace std;

void merge(int *items, int low, int endOfFirstHalf, int beginningOfSecondHalf, int high) {
    int totalSize = high - low + 1;
    int sortedArray[totalSize];
    int lowCopy = low;
    int beginningOfSecondHalfCopy = beginningOfSecondHalf;
    for (int i = 0; i < totalSize; i++) {
        if ((lowCopy <= endOfFirstHalf && items[lowCopy] < items[beginningOfSecondHalfCopy]) || beginningOfSecondHalfCopy == high) {
            sortedArray[i] = items[lowCopy];
            lowCopy++;
        }
        else {
            sortedArray[i] = items[beginningOfSecondHalfCopy];
            beginningOfSecondHalfCopy++;
        }
    }
/*    for (int i = 0; i < totalSize; i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl;
    cout << "Low: " << low << " Number of Bytes: " << totalSize * sizeof(int) << endl;*/
    memcpy(items + low, sortedArray, totalSize * sizeof(int));
}

void mergeSort(int *items, int low, int high) {
  /*  for (int i = 0; i < 15; i++) {
        cout << items[i] << " ";
    }*/
    cout << endl;
    if(high - low >= 1) { //if not base case
        int endOfFirstHalf = (low + high) / 2; //calculate middle of array (i.e. end of array1)
        int beginningOfSecondHalf = endOfFirstHalf + 1; //calculate next element over (i.e. first element of array2
        
        //split array in half; sort each half
        mergeSort(items, low, endOfFirstHalf); //first half of array
       /* for (int i = 0; i < 15; i++) {
            cout << items[i] << " ";
        }
        cout << endl;*/
        mergeSort(items , beginningOfSecondHalf, high);
      /*  for (int i = 0; i < 15; i++) {
            cout << items[i] << " ";
        }
        cout << endl;*/
        merge(items, low, endOfFirstHalf, beginningOfSecondHalf, high);
    } //end if
}

int main() {
    int intArray[15] = {1, 7, 8, 4, 6, 1, 1, 9, 0, 6, 3, 7, 8, 7, 7};
    for (int i = 0; i < 15; i ++) {
        cout << *(intArray + i) << " ";
    }
    cout << endl;
    
    
    mergeSort(intArray, 0, 14);
    
    
    for (int i = 0; i < 15; i ++) {
        cout << *(intArray + i) << " ";
    }
    cout << endl;
}
