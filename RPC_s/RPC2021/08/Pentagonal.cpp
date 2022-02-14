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

ll N=1e6;

ll f(ll n){
    return n*(3*n-1)/2;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    vl v;
    
    for(ll i=1;i<N;i++){
        v.pb(f(i));
    }
    //cout<<v.size();
    ///*
    while(tc--){
        ll n;
        cin>>n;
        int idx=lower_bound(v.begin(),v.end(),n) - v.begin();
        if(n == v[idx]){
            cout<<n<<el;
            continue;
        }
        int du=v[idx] - n;
        int dd=n - v[idx - 1];
        if(du == dd){
            cout<<v[idx - 1]<<el;
        }else if(dd < du){
            cout<<v[idx - 1]<<el;
        }else{
            cout<<v[idx]<<el;
        }
    }
}

/*

*/