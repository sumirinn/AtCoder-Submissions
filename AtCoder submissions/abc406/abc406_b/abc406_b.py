n,k=map(int, input().split())
a=list(map(int, input().split()))

x,y=1,10**k-1

for i in range(n):
    x*=a[i]
    if x>y:  
        x=1

print(x)