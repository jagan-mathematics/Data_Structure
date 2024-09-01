#include <iostream>
#include "tim_sort.h"

using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}


int main(){
    int array[] = {0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 40, 4 , 1, 40, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4};
    const int n = sizeof(array) / sizeof(array[0]);

    const clock_t begin_time = clock();
    timeSort<int, n>::sort(array);
    std::cout << "Time taken to complete sorting " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << std::endl;


//    Sorters<int, 4>::insertSort(array);
    printArray(array, n);
}
