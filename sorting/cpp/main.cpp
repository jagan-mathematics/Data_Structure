#include <iostream>
#include <random>
#include <ctime>

#include "tim_sort.h"
#include "basicSorting.h"

using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}


template <typename Func, typename T>
static void measureTime(Func sortFunction, std::vector<T>& array, const std::string& sortName) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(array);
    auto stop = std::chrono::high_resolution_clock::now();


    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << sortName << " took " << duration.count() << " microseconds." << std::endl;
}


template<typename S>
void printArray(const std::vector<S>& array) {
    for (const S& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;  // Newline after printing the array
}


int main(){
    int array[] = {0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 40, 4 , 1, 40, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4};
    const int n = sizeof(array) / sizeof(array[0]);

    const clock_t begin_time = clock();
    timeSort<int, n>::sort(array);
    std::cout << "Time taken to complete sorting " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << std::endl;


//    Sorters<int, 4>::insertSort(array);
    printArray(array, n);



    size_t data_size = 10000;  // Size of the dataset (e.g., 1 million elements)
    int min_value = 1;
    int max_value = 100;
    std::vector<int> arr1 = generateRandomDataset(data_size, min_value, max_value);
    std::vector<int> arr2 = arr1;
    std::vector<int> arr3 = arr1;
    std::vector<int> arr4 = arr1;
    std::vector<int> arr5 = arr1;
    std::vector<int> arr6 = arr1;

    std::cout << "Original array size: " << arr1.size() << std::endl;


    measureTime(basicSorting<int>::selectSort, arr1, "Selection Sort");

    // Measure time for Bubble Sort (bubble sort will takes more time compared to all other because of its continuous swapping)
    measureTime(basicSorting<int>::bubbleSort, arr3, "Bubble Sort");

    measureTime(basicSorting<int>::insertSort, arr2, "Insertion Sort");

    measureTime(basicSorting<int>::mergeSort, arr4, "Merge Sort");

    measureTime(basicSorting<int>::quickSort, arr5, "Quick Sort");

    measureTime(basicSorting<int>::quickSortM, arr6, "Quick Sort (Optimized)");
}
