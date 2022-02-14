/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
using pii=pair<int,int>;
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll mod=((1LL<<31)-1);

long long mult(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

ll fexp(ll base, ll expo, ll mod){
    ll ans = 1;
    for(;expo;base=mult(base,base,mod),expo>>=1){
        if(expo&1)
            ans=mult(ans,base,mod);
    }
    return ans%mod;
}

ull tetran(ull n){
    ull i=((n%mod)*((n+1)%mod))%mod;
    ull j=(i*(n+2)%mod)%mod;
    ull ans=(j*fexp(6,mod-2,mod))%mod;
    return ans;
}


int main(){
	fast_io;
	int t; cin>>t;
	while(t--){
	    ull n; cin>>n;
	    cout<<tetran(n)<<endl;
	    //cout<<mod<<endl;
	}
}