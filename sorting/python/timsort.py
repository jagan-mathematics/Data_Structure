def insert_sorting(array):
    n = len(array)
    insertsort(array, 0, n)


def binary_search(array, val, left, right):
    if left == right:
        return left if array[left] > val else left + 1

    if left > right:
        return left

    mid = (left + right) // 2

    if array[mid] < val:
        return binary_search(array, val, mid + 1, right)
    elif array[mid] > val:
        return binary_search(array, val, left, mid - 1)

    return mid


def insertsort(array, start, end):
    for i in range(start + 1, end + 1):
        key = array[i]
        next_high = binary_search(array, key, start, i - 1)
        j = i - 1
        while (j >= next_high):
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key


MAX_JOB = 32


def calcualte_min_job(n):
    r = 0
    while n >= MAX_JOB:
        r |= n & 1
        n >>= 1
    return n + r


def merge(array, left, mid, high):
    n1 = (mid - left) + 1
    n2 = (high - mid)

    left_holder = [None] * n1
    right_holder = [None] * n2

    for i in range(n1):
        left_holder[i] = array[left + i]

    for j in range(n2):
        right_holder[j] = array[mid + j + 1]


    i, j, k = 0, 0, left

    while i < n1 and j < n2:
        if left_holder[i] <= right_holder[j]:
            array[k] = left_holder[i]
            i += 1
        else:
            array[k] = right_holder[j]
            j += 1
        k += 1

    while i < n1:
        array[k] = left_holder[i]
        k += 1
        i += 1

        # Copy remaining element of right, if any
    while j < n2:
        array[k] = right_holder[j]
        k += 1
        j += 1



def tim_sort(array):
    n = len(array)

    min_job = calcualte_min_job(n)

    for start in range(0, n, MAX_JOB):
        end = min(start + min_job - 1, n - 1)
        insertsort(array, start, end)

    size = min_job
    while size < n:
        for left in range(0, n, 2 * size):
            mid = min(n - 1, left + size - 1)
            right = min((left + 2 * size - 1), (n - 1))

            if mid < right:
                merge(array, left, mid, right)

        size *= 2


import time

i_t = time.time()
a = [0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 40, 4 , 1, 40, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4]
tim_sort(a)
print(int(time.time() - i_t))


i_t = time.time()
a = [0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 40, 4 , 1, 40, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4, 0, 4 , 1, 4]
a = sorted(a)
# print(a)
print(time.time() - i_t)
