import time

def fibo_loop(n):
    a = 0
    b = 1
    x=0

    for i in range(n):
        x = a
        a = b
        b = x+b
    
    return a

def fibo_rec(n):
    if n==0 or n==1:
        return n
    
    return fibo_rec(n-1) + fibo_rec(n-2)

print(f"{'i':<4} {'iterative':<30} {'recursive':<30}")
print('-'*60)

for i in range(0, 45, 5):
    #recursive time
    tr1 = time.time()
    fibo_rec(i)
    tr2 = time.time()
    exec_time_rec = tr2-tr1

    #iterative tiem c
    ti1 = time.time()
    fibo_loop(i)
    ti2 = time.time()
    exec_time_itr = ti2-ti1