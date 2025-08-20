def insertion_sort(a):
    n = len(a)
    for i in range(n):
        j = i-1
        temp = a[i]

        while j>=0 and temp < a[j]:
            a[j+1] = a[j]
            j-=1
        
        a[j+1] = temp
        
a = [5, 27, 10, 3, 0, 1, -15, 99, 8, 2]
print(a)
insertion_sort(a)
print(a)