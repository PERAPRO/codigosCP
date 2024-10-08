/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

const ll N = 100003;

bitset<N> primes;

void sieve(){
    primes.set();
    primes[0]=0; primes[1]=0;
    for(ll i=2;i<=N;i++){
        if(primes[i]==0){
            continue;
        }
        else{
            for(ll j=i*i;j<=N;j+=i){
                primes[j]=0;
            }
        }
    }
}

bool isPrime(ll num){
    return primes[num];
}


int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	sieve();
	while(testcases--){
	   ll k;
	   cin>>k;
	   if(isPrime(k)){
	       cout<<"yes\n";
	   }else{
	       cout<<"no\n";
	   }
	}
}
