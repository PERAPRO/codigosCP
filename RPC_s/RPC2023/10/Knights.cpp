/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<ll,ll>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int oo = 1e9+7, mod = 1e9+7;

const int N = 1e6+5;

ll fact[N];
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int n,h;
    cin>>n>>h;
    
    fact[0] = 1;
    
    for(int i = 1;i<N;i++){
        fact[i] = fact[i - 1] * i % mod;
    }
    
    vl houses(h);
    
    ll cnt = 0;
    
    for(int i = 0;i<h;i++){
        cin>>houses[i];
        cnt += houses[i];
    }
    
    if(!h){
        cout<<fact[n]<<el;
        return 0;
    }
    
    if(cnt == n){
        cout<<0<<el;
        return 0;
    }
    
    ll ans = fact[n];
    
    ll sum = 0;
    
    for(int i = 0;i<h;i++){
        sum += houses[i];
        ans-=fact[sum];
        ans+=mod;
        ans %= mod;
    }
    
    cout<<ans<<el;
    

}

/*
2
2
0 2
1 1
2
0 1
1 0
*/