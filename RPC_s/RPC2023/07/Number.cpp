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

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */

    ll n,k;
    cin>>n>>k;
    
    vl primes(k);
    for(int i = 0;i<k;i++){
        cin>>primes[i];
    }
    
    ll c = (1<<k);
    
    function<ll(ll)> check = [&] (ll m){
        // cout<<m<<el<<el;
        ll ans = m;
        
        for(int i = 1;i<c;i++){
            int cnt = 0;
            ll prod = 1;
            for(int j = 0;j<k;j++){
                if(i&(1<<j)){
                    prod *= primes[j];
                    cnt++;
                }
            }
            if(cnt & 1) ans -= (m / prod);
            else ans += (m / prod);
            // cout<<ans<<esp<<prod<<el;
        }
        
        return ans;
    };
    
    ll lo = 1, hi = 5e18;
    
    // cout<<check(23)<<el;
    
    while(lo < hi){
        ll m = lo + (hi - lo) / 2;
        if(check(m) >= n){
            hi = m;
        }else{
            lo = m + 1;
        }
    }
    
    cout<<lo<<el;
}

/*

*/