#pragma once
#include "IAlgorithm.h"

class AlgorithmCountNumbers : public IAlgorithm {
public:
    int countNumberOfEqualElements(Array &list1, Array &list2) override;
};