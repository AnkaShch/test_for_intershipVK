#include <unordered_set>
#include "AlgorithmHashTable.h"

int AlgorithmHashTable::countNumberOfEqualElements(Array &list1, Array &list2) {
    if (list1.size() > list2.size()) {
        list1.swap(list2);
    }

    int ans = 0;
    std::unordered_set <int> numbsInFirstList;
    numbsInFirstList.reserve(10*list1.size());
    for (size_t i = 0; i < list1.size(); ++i) {
        numbsInFirstList.insert(list1[i]);
    }
    for (size_t i = 0; i < list2.size(); ++i) {
        if (numbsInFirstList.find(list2[i]) != numbsInFirstList.end())
            ans++;
    }

    return ans;
}
