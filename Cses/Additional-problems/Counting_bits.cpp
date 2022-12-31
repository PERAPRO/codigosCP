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
    ll n;
    cin>>n;
    
    ll nn = n + 1;
    
    ll ans = 0;
    
    for(int i=60;i>=0;i--){
        ll cnt1 = nn / (1LL << (i + 1));
        ll cnt2 = nn % (1LL << (i + 1));
        ll aporte = max(0LL, cnt2 - (1LL << (i)));
        ans += aporte + cnt1 * (1LL << (i));
        // cout<<cnt1<<esp<<cnt2<<esp<<aporte<<el;
    }
    
    cout<<ans<<el;
    // cout<<(1LL<<60)<<el;
}

/*
8
1 2
1 3
2 4
3 5
3 6
4 7
4 8

10
7 5
5 3
7 4
1 9
9 2
10 1
8 1
8 6
4 8

*/