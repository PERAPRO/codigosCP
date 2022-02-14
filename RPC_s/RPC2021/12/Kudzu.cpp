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
string no="NO";

const ll mod = 1e9+7;

vl pot(33);

ll fexp(ll a, ll b){
    ll ans = 1;
    for(;b;a = a * a % mod, b >>= 1){
        if(b&1){
            ans = ans * a % mod;
        }
    }
    return ans;
}

map<ll,ll> upds;

void upd(ll node, ll size){
    if(node < 0) return;
    ll iter = upper_bound(all(pot), node) - pot.begin();
    upds[node] = (upds[node] + size) % mod;
    if(node) upd(node - pot[iter - 1],size);
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    ll age, q;
    cin>>age>>q;
    
    pot[0] = 1;
    
    for(int i=1;i<33;i++){
        pot[i] = pot[i - 1] * 2;
    }
    
    while(q--){
        ll node;
        cin>>node;
        ll iter = upper_bound(all(pot), node) - pot.begin();
        ll size = fexp(2,age - iter);
        ll ans = (size - upds[node] + mod) % mod;
        cout<<ans<<el;
        upd(node - pot[iter - 1], ans);
    }
}

/*

*/