n,b=map(int,input().split())
def f(a):
    a-=b
    if a<=0:return 1
    return 1+f((a+b)//(b+1))
print(f(n))