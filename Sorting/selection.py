def selection_sort(a):
    n = len(a)
    for i in range(n):
        least = a[i]
        pos = i

        for j in range(i+1, n):
            if least > a[j]:
                least = a[j]
                pos = j;

        if not pos == i:
            a[i], a[pos] = a[pos], a[i]

a = [5, 27, 10, 3, 0, 1, -15, 99, 8, 2]
print(a)
selection_sort(a)
print(a)