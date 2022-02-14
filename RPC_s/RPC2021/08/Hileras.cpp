/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const ll mod=1e9+7;

const int N=2005;

bool isPrime(int n){
    if(n == 1) return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

ll fexp(ll a, ll b){
    ll ans=1;
    for(;b;a=(a*a)%mod,b>>=1){
        if(b&1){
            ans=(ans*a)%mod;
        }
    }
    return ans;
}

ll inv(ll n){
    return fexp(n, mod-2);
}

ll fact[N];



ll comb(ll n, ll k){
    if(k > n) return 0;
    
    ll ans=fact[n];
    ans=(ans * inv(fact[n - k])) % mod;
    ans=ans * inv(fact[k]) % mod;
    return ans;
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int q;
    cin>>q;
    
    fact[0]=1;
    for(ll i=1;i<N;i++){
        fact[i]=(fact[i - 1] * i) % mod;
    }
    
    vl values(N);
    
    for(int i=4;i<N;i++){
        for(int j=2;j<i;j++){
            if(isPrime(j) && isPrime(i-j)){
                values[i]=(values[i] + comb(i, j)) % mod;
            }
        }
    }
    
    //cout<<comb(10,3)<<el;
    
    while(q--){
        int l,r;
        cin>>l>>r;
        ll ans=0;
        for(int i=l;i<=r;i++){
            ans=(ans + values[i]) % mod;
        }
        
        cout<<ans<<el;  
        
    }
    
}

/*

*/