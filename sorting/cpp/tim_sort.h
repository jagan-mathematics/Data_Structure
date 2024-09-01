#ifndef TIM_SORT_H
#define TIM_SORT_H

#include <iostream>
#include <algorithm>
#include "sorting_algo.h"

const int RUN = 32;

template<typename T, size_t N>
class timeSort {

private:
    static int calculateRun(int n) {
        int r = 0;
        while (n >= RUN) {
            r |= n & 1;
            n >>= 1;  // Use >>= to halve n instead of doubling it
        }
        return n + r;
    }

    static void merge(T (&arr)[N], int start, int mid, int end){
        const int left_length = mid - start + 1;
        const int right_length = end - mid;

        std::vector<T> leftHolder(left_length);
        std::vector<T> rightHolder(right_length);

        std::copy(arr + start, arr + mid + 1, leftHolder.begin());
        std::copy(arr + mid + 1, arr + end + 1, rightHolder.begin());

        int i = 0, j = 0, k = start;

        while ( i < left_length && j < right_length){
            if (leftHolder[i] <= rightHolder[j]){
                arr[k++] = leftHolder[i];
                i++;
            }
            else{
                arr[k++] = rightHolder[j];
                j ++;
            }
        }

        while (i < left_length) {
            arr[k++] = leftHolder[i++];
        }

        while (j < right_length) {
            arr[k++] = rightHolder[j++];
        }
    }

public:
    void static sort(T (&arr)[N]) {
        const int n = sizeof(arr) / sizeof(arr[0]);
        int min_job = calculateRun(n);


        for (int start=0; start< n; start+=min_job){
            int end = std::min(n-1, start + min_job - 1);
            Sorters<int, n>::insertSort(arr, start, end);
        }

        int size = min_job;
        while (size < n){

            for (int start = 0; start< n; start += 2*size){
                int mid = std::min(n-1, start + size - 1);
                int end = std::min(n-1, (start + 2 * size - 1));

                if (mid < end) {
                    merge(arr, start, mid, end);
                }
            }
            size <<= 1;
        }
        std::cout << min_job << std::endl;
    }


};

#endif // TIM_SORT_H
