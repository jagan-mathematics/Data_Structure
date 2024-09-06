### Optimizing Pivot Selection in QuickSort

When selecting a pivot in QuickSort, certain improvements can significantly reduce the likelihood of hitting the worst-case time complexity, which is O(n²). The worst-case scenario often occurs when the input array is already sorted or nearly sorted, and you consistently choose a poor pivot, such as the first element.

A more robust approach to pivot selection is using **median-of-three pivoting** or **random pivot selection**. These methods improve partitioning and help avoid unbalanced splits, thereby improving overall performance.

- **Median-of-Three Pivoting:** This method picks the median of the first, middle, and last elements of the array as the pivot. It ensures that the pivot is closer to the median of the values, which helps avoid the poor performance that occurs with sorted or nearly sorted input.
  
- **Random Pivoting:** Instead of always choosing the first or last element as the pivot, randomly selecting a pivot from the array ensures that the likelihood of hitting the worst case is minimized, especially when the array follows a specific order.

### Tail Call Optimization

When recursively sorting two partitions in QuickSort, you can optimize recursion depth by always sorting the smaller partition first. This technique, known as **tail call optimization**, reduces the recursive overhead and lowers the risk of stack overflow for large inputs. After sorting the smaller partition, the algorithm can continue with the larger one without requiring additional recursive calls, allowing the larger partition to be processed iteratively.

### Choosing the Right Sorting Algorithm for Small Arrays

For small arrays, QuickSort and MergeSort tend to be inefficient due to recursion overhead. A better alternative for sorting small arrays is **Insertion Sort**, which has a lower constant factor and performs better on small datasets. While QuickSort and MergeSort shine on large datasets due to their divide-and-conquer strategies, for small arrays, the simplicity and efficiency of Insertion Sort make it the better choice.

- **Insertion Sort**: Best suited for small arrays due to its low overhead and simple operations.
- **Merge Sort**: Performs well on large datasets but incurs extra memory overhead.
- **QuickSort**: Generally fast for large datasets, but its performance can degrade if pivot selection is not optimized.

### Performance Comparison

When comparing the time taken by different sorting algorithms, it's clear that for small inputs, algorithms like Selection Sort and Bubble Sort are extremely inefficient. However, as the array size grows, algorithms like Merge Sort or optimized QuickSort perform far better due to their logarithmic time complexity.

### Run Results:
For an array size of 1,000,000:

- **Selection Sort:** 1,672,814,363 microseconds
- **Bubble Sort:** 10,232,495,667 microseconds
- **Insertion Sort:** 2,611,202,327 microseconds
- **Merge Sort:** 344,015 microseconds

For an array size of 10,000:
- **Selection Sort:** 1,38,535 microseconds
- **Bubble Sort:** 3,61,683 microseconds
- **Insertion Sort:** 86,180 microseconds
- **Merge Sort:** 1,691 microseconds
- **Quick Sort:** 7,793 microseconds
- **Quick Sort (Optimized):** took 3229 microseconds.


As shown, Merge Sort performs significantly better on large arrays compared to other simple sorting algorithms, demonstrating the importance of selecting the appropriate algorithm based on the input size and memory constraints.

