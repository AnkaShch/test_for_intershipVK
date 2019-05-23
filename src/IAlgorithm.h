#pragma once
#include <vector>
typedef std::vector<int> Array;

class IAlgorithm {
public:
    virtual int countNumberOfEqualElements(Array &list1, Array &list2) = 0;
};