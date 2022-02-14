/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

const int sz=1050000;

bitset<sz> prime;
vector<int> primes;

void sieve(){
    prime.set();
    prime[0]=prime[1]=0;
    for(long long i=2;i<=sz;i++){
        if(prime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<=sz;j+=i){
                prime[j]=0;
            }
        }
        
    }
}

ll suma(ll N){
    ll aux=N;
    ll ans=1;
    ll cur=0, pf=primes[cur];
    while(pf*pf<=N){
        int cnt=0;
        while(N%pf==0){
            N/=pf;
            cnt++;
        }
        ans*=(pow(pf,++cnt)-1)/(pf-1);
        pf=primes[++cur];
    }
    if(N!=1){
        ans*=(pow(N,2)-1)/(N-1);
    }
    return ans-aux;
}

int main(){
	fast_io;
	sieve();
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll d=suma(n);
	    if(d==n){
	        cout<<"perfect\n";
	    }else if(d>n){
	        cout<<"abundant\n";
	    }else{
	        cout<<"deficient\n";
	    }
	}
}