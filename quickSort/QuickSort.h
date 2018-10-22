#include <algorithm>
/*******************************************************************
//Partition the array list[first..last]
int partition(int list[], int first, int last)
{
  int pivot = list[first]; // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low] <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high] > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      int temp = list[high];
      list[high] = list[low];
      list[low] = temp;
    }
  }

  while (high > first && list[high] >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high])
  {
    list[first] = list[high];
    list[high] = pivot;
    return high;
  }
  else
  {
    return first;
  }
} //From Prof: Implement partition in a better way
******************************************************************/




int median(int first, int middle, int last) {
    return std::min(std::min(std::max(first, middle), std::max(middle, last)), std::max(first, last));
}

int partition(int list[], int first, int last) {
    int middle = (first + last) / 2;
    int pivot = median(list[first], list[middle], list[last]);
    int j, k;
    for (j = first, k = last; j < k; j += 1 * (list[j] <= pivot), k -= 1 * (list[k] > pivot)) {
        if (j > pivot && k < pivot) {
            std::swap(j, k);
            //j++;
            //k--;
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

