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

ll mod=1e9;

ll mul(ll a, ll b){
    return(__int128)a*b%mod;
}

ll ans;
ll fexp(ll a, ll b){
    for(;b;a=mul(a,a),b>>=1){
        if(b&1)
            ans=mul(ans,a);
    }
    return ans;
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	    ll k,q;
	    cin>>k>>q;
	    vi v(k);
	    for(int i=0;i<k;i++) cin>>v[i];
	    //cout<<v;
	    while(q--){
	        ll a;cin>>a;
	        if(a<k) cout<<v[a]<<el;
	        else{
	            ll num=v[a%k];
	            ll ep=a/k+1;
	            if(num<0 && (ep&1)){
	                while(num<0)num+=mod;
	                ans=num;
	                cout<<fexp(abs(v[a%k]),ep-1)<<el;
	            }else{
	                ans=1;
	                cout<<fexp(abs(num),ep)<<el;
	            }
	        }
	    }
	}
}
