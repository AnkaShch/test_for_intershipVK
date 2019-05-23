#include <algorithm>
#include "AlgorithmBinSearch.h"

int AlgorithmBinSearch::countNumberOfEqualElements(Array &list1, Array &list2) {
    if (list1.size() == 0 || list2.size() == 0) {
        return std::max(list1.size(), list2.size());
    }
    
    if (list1.size() > list2.size()) {
        list1.swap(list2);
    }

    std::sort(list1.begin(), list1.end());

    int ans = 0;
    for (size_t i = 0; i < list2.size(); ++i) {
        if (std::binary_search(list1.begin(), list1.end(), list2[i]))
            ans++;
    }
    return ans;
}