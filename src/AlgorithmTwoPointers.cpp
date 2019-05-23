#include <algorithm>
#include "AlgorithmTwoPointers.h"

int AlgorithmTwoPointers::countNumberOfEqualElements(Array &list1, Array &list2) {
    if (list1.size() == 0 || list2.size() == 0) {
        return std::max(list1.size(), list2.size());
    }
    
    if (list1.size() > list2.size()) {
        list1.swap(list2);
    }

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int i = 0, j = 0;
    int ans = 0;
    while (i < list1.size() && j < list2.size()) {
        if (list1[i] == list2[j]) {
            ans++;
            j++;
        }
        if (list1[i] > list2[j]) {
            j++;
        }
        if (list1[i] < list2[j]) {
            i++;
        }
    }
    return ans;
}
