/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;
//typedef unsigned long long ull;

ll mult(ll a, ll b, ll mod){
    ll ans=0;
    a%=mod;
    for(;b;b>>=1,a=(a%mod)*(2LL)%mod){
        if(b&1)
            ans=(ans%mod)+(a%mod)%mod;
    }
    return ans%mod;
}

ll fexp(ll base, ll expo, ll mod){
    ll ans = 1;
    for(;expo;base=mult(base,base,mod),expo>>=1){
        if(expo&1)
            ans=mult(ans,base,mod);
    }
    return ans%mod;
}

bool isPrime(ll n, int iter=8){
    if(n<4)
        return n==2 || n==3;
    for(int i=0;i<iter;i++){
        ll a = 2 + rand() % (n-3);
        if(fexp(a,n-1,n)!=1)
            return false;
    }
    return true;
}

int main(){
	fast_io;
	int t;
	cin>>t;
	//cout<<mult(5,5,30)<<endl;
	while(t--){
	    ll n;
	    cin>>n;
	    if(isPrime(n))
	    cout<<"YES\n";
	    else cout<<"NO\n";
	}
}