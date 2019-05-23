cmake_minimum_required(VERSION 3.6)
project(intershipVK)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(src)

add_executable(intershipVK
        main.cpp
        src/IAlgorithm.h
        src/AlgorithmTwoPointers.h src/AlgorithmTwoPointers.cpp
        src/AlgorithmBinSearch.h src/AlgorithmBinSearch.cpp
        src/AlgorithmHashTable.h src/AlgorithmHashTable.cpp
        src/AlgorithmCountNumbers.h src/AlgorithmCountNumbers.cpp
        Tests/test.cpp
        )

target_link_libraries(intershipVK gtest gtest_main)