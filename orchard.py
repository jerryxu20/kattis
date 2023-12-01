R,G,B,Y,S=map(int,input().split())
D={}
def f(a,b,c,d,s):
    X=(a,b,c,d,s)
    if X in D:return D[X] 
    if a+b+c+d==0:return 1
    if s==0:return 0
    A=0
    F=[a,b,c,d]
    M=max(F)
    K=len([x for x in F if x==M])
    T=len([x for x in F if x>0])+2
    def O(n):
        if n==0: return 0
        if n==M: return (1+1/K)*1/T
        return 1/T
    F+=[s]
    for i in range(4):
        F[i]-=1
        A+=O(F[i]+1)*f(*F)
        F[i]+=1
    F[-1]-=1
    A+=O(-1)*f(*F)
    D[X]=A
    return A
print(f(R,G,B,Y,S))