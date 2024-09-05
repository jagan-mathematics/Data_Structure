#include <iostream>
#include "tim_sort.h"

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



    // BasicSorting algo testing
    std::vector<int> arr1 = {64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11, 64, 25, 12, 22, 11};
    std::vector<int> arr2 = arr1;
    std::vector<int> arr3 = arr1;

    std::cout << "Original array: ";
    printArray<int>(arr1);


    measureTime(basicSorting<int>::selectSort, arr1, "Selection Sort");
    std::cout << "Sorted array (Selection Sort): ";
    printArray<int>(arr1);


    // Measure time for Bubble Sort (bubble sort will takes more time compared to all other because of its continuous swapping)
    measureTime(basicSorting<int>::bubbleSort, arr3, "Bubble Sort");
    std::cout << "Sorted array (Bubble Sort): ";
    printArray<int>(arr3);

    measureTime(basicSorting<int>::insertSort, arr2, "Insertion Sort");
    std::cout << "Sorted array (Insertion Sort): ";
    printArray<int>(arr2);
}
