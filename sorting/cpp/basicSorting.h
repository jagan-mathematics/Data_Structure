//
// Created by jagan-12127 on 05/09/24.
//

#ifndef UNTITLED_BASICSORTING_H
#define UNTITLED_BASICSORTING_H

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class basicSorting {
public:
    static void selectSort(std::vector<T> &array) {
        int n = array.size();
        for (int i = 0; i < n; ++i) {
            int min_point = i;
            for (int j = i + 1; j < n; ++j) {
                if (array[j] < array[min_point]) {
                    min_point = j;
                }
            }
            if (i != min_point) {
                std::swap(array[min_point], array[i]);
            }
        }
    }


    static void bubbleSort(std::vector<T> &array){
        int n = array.size();

        for (int i=0; i < n - 1; i++){
            bool is_swapping = false;
            for(int j=0; j<n-i-1; ++j){
                if (array[j]>array[j+1]){
                    swap(array[j], array[j+1]);
                    is_swapping = true;
                }
            }
            if (!is_swapping){ break;}
        }
    }


    static void insertSort(std::vector<T> &array) {
        int n = array.size();

        for (int i = 1; i < n; ++i) {
            T current_val = array[i];
            int j = i - 1;


            while (j >= 0 && array[j] > current_val) {
                array[j + 1] = array[j];
                --j;
            }

            array[j + 1] = current_val;
        }
    }
};

#endif //UNTITLED_BASICSORTING_H
