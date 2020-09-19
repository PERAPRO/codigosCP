a = list(map(int,input().split()))
n = a[0]
price = a[1]
if(n==1):
    print(price)
else:
    print(n*(price-2)+2)