#include <algorithm>
using namespace std;

int getMedianIndex(int *list, int first, int middle, int last) {
    int median, medianIndex;
    median = std::min(std::min(std::max(first, middle), std::max(middle, last)), std::max(first, last));
    if (list[first] == median) {
        medianIndex = first;
    } else if (list[middle] == median) {
        medianIndex = middle;
    } else {
        medianIndex = last;
    }
    return medianIndex;
}

int partition(int *list, int first, int last) {
    int middle = (first + last) / 2;
    int pivotIndex = getMedianIndex(list, first, middle, last);
    int pivot = list[pivotIndex];
    int j, k;
    for (j = first, k = last; j < k; j += 1 * (j < pivotIndex), k -= 1 * (k > pivotIndex)) {
        if ((list[j] > pivot && pivotIndex < j) || (list[j] > pivot && pivotIndex > j)) {
            int temp = list[j];
            list[j] = pivot;
            list[pivotIndex] = temp;
            pivotIndex = j;
        }
        if ((list[k] < pivot && k > pivotIndex) || (list[k] > pivot && k < pivotIndex)) {
            int temp = list[k];
            list[k] = pivot;
            list[pivotIndex] = temp;
            pivotIndex = k;
        }
    }
    return j;
}


void quickSort(int list[], int first, int last)
{
    if (last > first)
    {
        int pivotIndex = partition(list, first, last);
        quickSort(list, first, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, last);
    }
}

//==== entry point ===
void quickSort(int list[], int arraySize)
{
    quickSort(list, 0, arraySize - 1);
}

