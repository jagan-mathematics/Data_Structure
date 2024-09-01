//
// Created by jagan-12127 on 01/09/24.
//

#ifndef UNTITLED_SORTING_ALGO_H
#define UNTITLED_SORTING_ALGO_H

#include <iostream>

template<typename T, size_t N>

class Sorters{

public:
    static void insertSort(T (&array)[N]){
        insertSort(array, 0, N - 1);
    }


    static void insertSort(T (&array) [N], int start, int end){
        for (int i=start+1; i <= end; i++){
            T key = array[i];

            int pos = binarySearchPeak(array, key, start, i - 1);

            for (int j = i - 1; j >= pos; --j) {
                array[j + 1] = array[j];
            }
            array[pos] = key;
        }
    }


private:
    static int binarySearchPeak(T (&array) [N], T val, int start, int end){
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (array[mid] < val) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};

#endif //UNTITLED_SORTING_ALGO_H
