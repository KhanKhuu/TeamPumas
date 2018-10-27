#ifndef radix_sort_h
#define radix_sort_h
#include <vector>
using namespace std;

void radixSort(vector<int> &list) {
    bool allZeroes = true;
    vector<vector<int>> Bucket(10);
    for (int  i = 1; allZeroes && i < INT_MAX; i*=10) {
        allZeroes = 0;
        for (int j: list) {
            int value = j / i % 10 * (-1 + 2 * (j > 0)); //math ensures we make negative values positve (no negative indices, see next line)
            Bucket.at(value).push_back(j);
            allZeroes || (allZeroes += i / i*10); //this prevents the situation where integer overflow occurs and we get to a perfect balance of 0
            allZeroes +=  j / (i * 10);
        }
        list.clear();
        for (vector<int> &k: Bucket) {
            list.insert(list.end(), k.begin(), k.end());
            k.clear();
        }
        vector<int> negativeNumbers;
        for(vector<int>::iterator it = list.end(); it != list.begin(); it--) {
            if (*it < 0) {
                negativeNumbers.push_back(*it);
                list.erase(it);
            }
        }
        list.insert(list.begin(), negativeNumbers.begin(), negativeNumbers.end());
    }
}
#endif /* radix_sort_h */
