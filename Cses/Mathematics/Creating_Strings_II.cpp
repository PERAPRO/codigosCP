/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
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
string no="NO SOLUTION";

const ll mod = 1e9+7;
const int N = 1e6+5;
ll fact[N];
ll inv[N];

ll fexp(ll a,ll b){
    ll ans = 1;
    for(;b;a = a * a % mod, b >>= 1){
        if(b & 1){
            ans = ans * a % mod;
        }
    }
    return ans;
}

ll bin(ll c, ll k){
    return fact[c] * inv[k] % mod * inv[c - k] % mod;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    fact[0] = inv[0] = 1;
    for(ll i=1;i<N;i++){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = fexp(fact[i], mod - 2);
    }
    string s;
    cin>>s;
    ll n = s.size();
    map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    ll ans = 1;
    for(auto[key,value]:m){
        //cout<<n<<esp<<value<<el;
        ans = ans * bin(n, value) % mod;
        n-=value;
        //cout<<ans<<el;
    }
    cout<<ans<<el;
}

/*

*/