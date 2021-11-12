/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;


vi primes;
bitset<100001> a;

void sieve(int max){
    a.set();
    a[0]=a[1]=0;
    for(int i=2;i<=max;i++){
        if(a[i]){
            primes.pb(i);
            for(ll j=i*1LL*i;j<=max;j+=i){
                a[j]=0;
            }
        }
    }
}

void init(int L, int R){
    if(L == 1) L++;
    int max=R-L+1;
    vi ar(max);
    for(ll p:primes){
        if(p*p<=R){
            int i=(L/p)*p;
            if(i<L) i+=p;
            
            for(;i<=R;i+=p){
                if( i!=p){
                    ar[i-L]=1;
                }
            }
        }
    }
    for(int i=0;i<max;i++){
        if(ar[i]==0){
            cout<<L+i<<endl;
        }
    }
}




int main(){
	fast_io;
	sieve(100000);
	int t;
	cin>>t;
	//cout<<a[7]<<endl;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    init(m,n);
	    cout<<endl;
	}
}