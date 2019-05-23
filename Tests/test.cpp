#include <vector>
#include <climits>
#include <unordered_set>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IAlgorithm.h"
#include "AlgorithmTwoPointers.h"
#include "AlgorithmBinSearch.h"
#include "AlgorithmCountNumbers.h"
#include "AlgorithmHashTable.h"

typedef std::vector<int> Array;
#define chrono_getTime std::chrono::steady_clock::now();
#define getLeadTime(s, f)(std::chrono::duration_cast<std::chrono::nanoseconds>(f - s));

Array generateArray(int len, int left = 0, int right = INT_MAX) {
    std::vector<bool> isUsed(right - left, false);
    Array v;
    int randNumb;
    for (int i = 0; i < len; ++i) {
        randNumb = std::rand()%(right - left);
        while (randNumb < isUsed.size() && isUsed[randNumb]) {
            randNumb++;
        }
        if (randNumb < isUsed.size()) {
            v.push_back(left + randNumb);
        } else {
            randNumb = 0;
            while (isUsed[randNumb]) {
                randNumb++;
            }
            v.push_back(left + randNumb);
        }
        isUsed[randNumb] = true;
    }
    return v;
}

void print(const Array &v) {
    for (auto e : v) {
        std::cout << e << ' ';
    }
 
}

int countSampleAns(const Array &v1, const Array &v2) {
	if (v1.size() == 0 || v2.size() == 0) {
		return std::max(v1.size(), v2.size());
	}
	
    std::unordered_set<int> numbs;
    for (int i = 0; i < v1.size(); ++i) {
        numbs.insert(v1[i]);
    }
    int ans = 0;
    for (int i = 0; i < v2.size(); ++i) {
        if (numbs.find(v2[i]) != numbs.end()) {
            ans++;
        }
    }
    return ans;
}

int countAnsAndTime (IAlgorithm &algo, Array &v1, Array &v2, const char *nameOfAlgo) {
	auto s1 = chrono_getTime;
	int ans = algo.countNumberOfEqualElements(v1, v2);
	auto f1 = chrono_getTime;
	auto time1 = getLeadTime(s1, f1);
	std::cout << "Lead time of " << nameOfAlgo << ":\t\t" << time1.count() << " nanosec\n";
	return ans;
}

void tested(Array &v1, Array &v2) {
	int sampleAns = countSampleAns(v1, v2);

	AlgorithmTwoPointers    algo1;
	AlgorithmBinSearch      algo2;
	AlgorithmHashTable      algo3;
	AlgorithmCountNumbers   algo4;
	int ans1, ans2, ans3, ans4;

	ans1 = countAnsAndTime(algo1, v1, v2, "AlgorithmTwoPointers");
	ans2 = countAnsAndTime(algo2, v1, v2, "AlgorithmBinSearch");
	ans3 = countAnsAndTime(algo3, v1, v2, "AlgorithmHashTable");
	ans4 = countAnsAndTime(algo4, v1, v2, "AlgorithmCountNumbers");

	EXPECT_EQ(sampleAns, ans1);
	EXPECT_EQ(sampleAns, ans2);
	EXPECT_EQ(sampleAns, ans3);
	EXPECT_EQ(sampleAns, ans4);
}

TEST (testDiffSize, littleArrays) {
	Array v1 = generateArray(10, -10, 10);
	Array v2 = generateArray(10, -10, 10);
	
	tested(v1, v2);
}

TEST (testDiffSize, bigArrays) {
	Array v1 = generateArray(100000);
	Array v2 = generateArray(100000);
	
	tested(v1, v2);
}

TEST (testDiffSize, veryBigArrays) {
	Array v1 = generateArray(1000000);
	Array v2 = generateArray(1000000);
	
	tested(v1, v2);
}

TEST (testOtherThings, disjointArrays) {
	Array v1 = generateArray(10000, -INT_MAX, -100);
	Array v2 = generateArray(10000, 100, INT_MAX);
	
	tested(v1, v2);
}

TEST (testOtherThings, diffLens) {
	Array v1 = generateArray(1000000);
	Array v2 = generateArray(10000);
	
	tested(v1, v2);
}

TEST (testOtherThings, bigDiffLens) {
	Array v1 = generateArray(1000000);
	Array v2 = generateArray(10);
	
	tested(v1, v2);
}

TEST (testOtherThings, sameArrays) {
	Array v1 = generateArray(1000);
	Array v2 = v1;
	
	tested(v1, v2);
}

TEST (testOtherThings, arraySize0) {
	Array v1 = generateArray(1000000);
	Array v2 = generateArray(0);
	
	tested(v1, v2);
}

TEST (testOtherThings, arraySize1) {
	Array v1 = generateArray(1);
	Array v2 = generateArray(100000);
	
	tested(v1, v2);
}

TEST (testDiffRange, smallRange) {
	Array v1 = generateArray(100, -100, 100);
	Array v2 = generateArray(50, 20, 100);
	
	tested(v1, v2);
}

TEST (testDiffRange, bigRange) {
	Array v1 = generateArray(100, -10000, 10000);
	Array v2 = generateArray(50, 0, INT_MAX);
	
	tested(v1, v2);
}

TEST (testDiffRange, diffRange1) {
	Array v1 = generateArray(100, 0, INT_MAX);
	Array v2 = generateArray(50, 20, 100);
	
	tested(v1, v2);
}

TEST (testDiffRange, smallRang2) {
	Array v1 = generateArray(10000, 0, 10005);
	Array v2 = generateArray(50, -100000, 100000);
	
	tested(v1, v2);
}

TEST (testIncorrectInput, test1) {
	Array v1 = {1, 2, 3, 4};
	Array v2 = {1, 1, 1, 2, 2, 4, 5};
	int sampleAns = 3;

	AlgorithmTwoPointers    algo1;
	AlgorithmBinSearch 	    algo2;
	AlgorithmHashTable	    algo3;
	AlgorithmCountNumbers   algo4;
	int ans1, ans2, ans3, ans4;

	ans1 = countAnsAndTime(algo1, v1, v2, "AlgorithmTwoPointers");
	ans2 = countAnsAndTime(algo2, v1, v2, "AlgorithmBinSearch");
	ans3 = countAnsAndTime(algo3, v1, v2, "AlgorithmHashTable");
	ans4 = countAnsAndTime(algo4, v1, v2, "AlgorithmCountNumbers");

	EXPECT_NE(sampleAns, ans1);
	EXPECT_NE(sampleAns, ans2);
	EXPECT_NE(sampleAns, ans3);
	EXPECT_NE(sampleAns, ans4);
}

TEST (testIncorrectInput, test2) {
	Array v1 = {1, 1, 1, 1, 1, 1};
	Array v2 = {1, 1};
	int sampleAns = 1;

	AlgorithmTwoPointers    algo1;
	AlgorithmBinSearch 	    algo2;
	AlgorithmHashTable	    algo3;
	AlgorithmCountNumbers   algo4;
	int ans1, ans2, ans3, ans4;

	ans1 = countAnsAndTime(algo1, v1, v2, "AlgorithmTwoPointers");
	ans2 = countAnsAndTime(algo2, v1, v2, "AlgorithmBinSearch");
	ans3 = countAnsAndTime(algo3, v1, v2, "AlgorithmHashTable");
	ans4 = countAnsAndTime(algo4, v1, v2, "AlgorithmCountNumbers");

	EXPECT_NE(sampleAns, ans1);
	EXPECT_NE(sampleAns, ans2);
	EXPECT_NE(sampleAns, ans3);
	EXPECT_NE(sampleAns, ans4);
}
