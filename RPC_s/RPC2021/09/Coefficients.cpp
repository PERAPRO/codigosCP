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

ll cl(ll a, ll b){
    return (a + b - 1)/b;
}

map<ll,ll> dp;

ll func(ll n){
    if(n == 1) return 1;
    
    ll &flor = dp[n / 2];
    ll &seil = dp[cl(n , 2)];
    
    ll &ans = dp[n];
    
    if(dp[n]) return ans;
    
    if(flor == 0) flor = func(n / 2);
    if(seil == 0) seil = func(cl(n , 2));
    
    return ans = 2 * flor + seil;
    
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    ll n;
    cin>>n;
    cout<<func(n)<<el;
}

/*

*/