def bubble_sort(a):
    n = len(a)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]

a = [5, 27, 10, 3, 0, 1, -15, 99, 8, 2]
print(a)
bubble_sort(a)
print(a)