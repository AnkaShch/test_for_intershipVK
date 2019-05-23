#include <cstddef>
#include "AlgorithmCountNumbers.h"

int AlgorithmCountNumbers::countNumberOfEqualElements(Array &list1, Array &list2) {
    int min1 = list1[0], max1 = list1[0];
    int min2 = list2[0], max2 = list2[0];
    for (size_t i = 0; i < list1.size(); ++i) {
        min1 = std::min(min1, list1[i]);
        max1 = std::max(max1, list1[i]);
    }

    for (size_t i = 0; i < list2.size(); ++i) {
        min2 = std::min(min2, list2[i]);
        max2 = std::max(max2, list2[i]);
    }

    int minimum, diff;
    if (max2 - min2 < max1 - min1) {
        minimum = min2;
        diff = max2 - min2;
        list1.swap(list2);
    } else {
        minimum = min1;
        diff = max1 - min1;
    }

    std::vector<bool> isNumb(diff + 1, false);
    for (size_t i = 0; i < list1.size(); ++i) {
        isNumb[list1[i] - minimum] = true;
    }

    int ans = 0;
    for (size_t i = 0; i < list2.size(); ++i) {
        if (list2[i] - minimum >= 0 && list2[i] - minimum < diff + 1 
                && isNumb.at(list2[i] - minimum))
            ans++;
    }
    return ans;
}
