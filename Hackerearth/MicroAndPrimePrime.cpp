/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

const int N=1e6+9;

int pp=0;

bitset<N> primes;
vi pps(N);
vi sol(N);

bool isPrime(ll num){
    return primes[num];
}

void sieve(){
    primes.set();
    primes[1]=0;primes[0]=0;
    for(ll i=2;i<N;i++){
        pps[i]=pp;
        if(primes[i]){
            pp++;
            pps[i]=pp;
            for(ll j=i*i;j<N;j+=i){
                primes[j]=0;
            }
        }
    }
}

void PP(){
    for(int i=1;i<N;i++){
        if(isPrime(pps[i])){
            sol[i]=sol[i-1]+1;
        }
        else sol[i]=sol[i-1];
    }
}

int main(){
	fast_io;
    int testcases;
    cin>>testcases;
    sieve();
    PP();
    //for (auto x: sol) cout<<x<<" ";
    while(testcases--){
        int l,r;
        cin>>l>>r;
        cout<<sol[r]-sol[l-1]<<endl;
    }
}
