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
char el = '\n';

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}

ll div_ceil(ll a,ll b){
    return a+b-1/b;
}
ll maxl=1e9+7;
ull k,s,g;

ull suma(ll n){
    ull enesimo=(n-1)*k+s;
    ull suma=(n*(s+enesimo))/2;
    return suma;
}
ll ans(){
    ull lo=1, hi=maxl,m;
    while(lo<hi){
        m=(lo+hi)/2;
        if(suma(m)>g) hi=m;
        else lo=m+1;
    }
    if(suma(lo-1)>g)
        return lo-1;
    else return lo;
}

int main(){
	fast_io;
	int t;
	cin>>t;
    //ll k,s,g;
	while(t--){
	    cin>>k>>s>>g;
	    //ll aux=g-s;
	    cout<<ans()<<el;
	}
}
