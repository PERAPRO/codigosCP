mod = 1000000000

def fexp(a,b):
    ans=1
    while(b>0):
        if(b&1==1):
            ans=ans*a
        a=a*a
        b//=2
    return ans


t=int(input())
for T in range (t):
    l=list(map(int,input().split()))
    k=l[0]
    q=l[1]
    v=list(map(int,input().split()))
    for Q in range (q):
        a=int(input())
        if(a<k):
            print(v[a],end='\n',flush=False)
        else:
            num=v[a%k]
            exp=(a//k)+1
            print(fexp(num,exp)%mod,end='\n',flush=False)
