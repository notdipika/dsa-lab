def partition(a, l, r):
    x, y = l, r
    pivot = a[l]

    while x<y:
        while x<=r and a[x] <= pivot:
            x+=1
        while a[y] > pivot:
            y-=1
        
        if(x < y):
            a[x], a[y] = a[y], a[x]

    a[l], a[y] = a[y], a[l]  
    return y

def quick_sort(a, l, r):
    if l<r:
        p = partition(a, l, r)
        quick_sort(a, l, p-1)
        quick_sort(a, p+1, r)
        

a = [5, 27, 10, 3, 0, 1, -15, 99, 8, 2]
print(a)
quick_sort(a, 0, 9)
print(a)