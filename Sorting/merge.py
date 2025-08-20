import math

temp = [0 for i in range(10)]

def merge(a, l, m, r):
    i, j, k = l, m, l
    while i < m and j <= r:
        if a[i] < a[j]:
            temp[k] = a[i]
            i += 1
        else:
            temp[k] = a[j]
            j += 1
        k += 1

    while i < m:
        temp[k] = a[i]
        i += 1
        k += 1
    while j <= r:
        temp[k] = a[j]
        j += 1
        k += 1

    for x in range(l, r+1):
        a[x] = temp[x]

def merge_sort(a, l, r):
    if l<r:
        mid = math.floor((r+l)/2)
        merge_sort(a, l, mid)
        merge_sort(a, mid + 1, r)
        merge(a, l, mid + 1, r)
        
a = [5, 27, 10, 3, 0, 1, -15, 99, 8, 2]
print(a)
merge_sort(a, 0, 9)
print(a)