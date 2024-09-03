def print_ascending(n):
    if n == 0:
        print(0, end=" ")
        return
    print_ascending(n-1)
    print(n, end=" ")


def print_descending(n):
    if n == 0:
        print(0, end=" ")
        return
    print(n, end=" ")
    print_descending(n-1)


print_ascending(10) # 0 1 2 3 4 5 6 7 8 9 10
print()
print_descending(10) # 10 9 8 7 6 5 4 3 2 1 0
