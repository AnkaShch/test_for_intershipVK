#pragma once
#include "IAlgorithm.h"

class AlgorithmBinSearch : public IAlgorithm {
public:
    int countNumberOfEqualElements(Array &list1, Array &list2) override;
};
