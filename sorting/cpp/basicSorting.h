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

    static void mergeSort(std::vector<T> &array){
        std::vector<T> temp_array(array.size());
        basicSorting::tempMergeSort(array, 0, array.size() - 1, temp_array);
    }

    static void tempMergeSort(std::vector<T> &array, int left, int right, std::vector<T> &temp_array){
        if ( left >= right){
            return;
        }
        int mid = (left + right) / 2;
        tempMergeSort(array, left, mid, temp_array);
        tempMergeSort(array, mid + 1, right, temp_array);
        merge(array, left, mid, right, temp_array);
    }


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



    static void quickSort(std::vector<T> &array){
        tempQuickSort(array, 0, array.size() - 1);
    }

    static void quickSortM(std::vector<T> &array){
        tempQuickSortM(array, 0, array.size() - 1);
    }


    static void tempQuickSort(std::vector<T> &array, int low, int high){
        if (low >= high){
            return;
        }
        int pivot_index = getPivotIndex(array, low, high);
        tempQuickSort(array, low, pivot_index - 1);
        tempQuickSort(array, pivot_index + 1, high);
    }


    static void tempQuickSortM(std::vector<T> &array, int low, int high){
        if (low >= high){
            return;
        }

        if (high-low + 1 < 10)
        {
            tempInsertSort(array, low, high);
            return;
        }

        int pivot_index = getPartition(array, low, high);

        tempQuickSortM(array, low, pivot_index - 1);
        tempQuickSortM(array, pivot_index + 1, high);
    }

    static void tempInsertSort(std::vector<T> &array, int low, int high) {
        for (int i = low+1; i < high; ++i) {
            T current_val = array[i];
            int j = i - 1;


            while (j >= low && array[j] > current_val) {
                array[j + 1] = array[j];
                --j;
            }

            array[j + 1] = current_val;
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

private:
    static int getPartition(std::vector<T> &array, int low, int high){
        srand(3234);
        int random = low + rand() % (high - low);
        swap(array[random], array[high]);

        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++){
            if (array[j] <= pivot){
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[high]);
        return i + 1 ;
    }

    static int getPivotIndex(std::vector<T> &array, int low, int high){
        T pivot_value = array[low];
        int i = low;
        int j = high;

        while (i < j){
            while( array[low]  >= array[i] && i <= high - 1){
                i++;
                if (i < j){
                    break;
                }
            }
            while( array[low]  <= array[j] && j >= low + 1){
                j--;
                if (i < j){
                    break;
                }
            }
            if (i < j){
                swap(array[i], array[j]);
            }
        }
        swap(array[low], array[j]);
        return j;
    }

    static void merge(std::vector<T> &array, int left, int mid, int right, std::vector<T> &temp_array){
        int left_pointer = left;
        int right_pointer = mid + 1;
        int pointer = left;

        while (left_pointer <= mid && right_pointer <= right){
            if (array[left_pointer] < array[right_pointer]){
                temp_array[pointer++] = array[left_pointer++];
            }else{
                temp_array[pointer++] = array[right_pointer++];
            }
        }

        // Copy the remaining elements from the left half
        while (left_pointer <= mid) {
            temp_array[pointer++] = array[left_pointer++];
        }

        // Copy the remaining elements from the right half
        while (right_pointer <= right) {
            temp_array[pointer++] = array[right_pointer++];
        }

        for(int i=left; i<=right;i++){
            array[i] = temp_array[i];
        }
    }
};

#endif //UNTITLED_BASICSORTING_H
