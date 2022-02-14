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

int fexp(int a, int b){
    int ans = 1;
    for(;b;a=a*a,b>>=1){
        if(b&1)
            ans = ans * a;
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    ll ca,cb;
    cin>>ca>>cb;
    ll mn = min(ca,cb);
    ll mx = max(ca,cb);
    ll ans = 2;
    ans += (mx / mn) * 2;
    //cout<<ans<<el;
    ans += (mx % mn != 0 ? 2 : 0);
    ans += (mx % mn != 0 ? (mx / mn) * 2 + 1 : 0);
    cout<<ans<<el;
}

/*

*/