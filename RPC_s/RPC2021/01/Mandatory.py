t=int(input())
for i in range (t):
    n = int(input())
    x=(n*(n+1)*(n+2))%2147483647
    print((x*1789569706)%2147483647)
    