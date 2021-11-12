#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;



int main(){
	fast_io;
	ll n;
	cin>>n;
	vector<ll> v;
	for(int i=0;i<n-1;i++){
	    ll k;
	    cin>>k;
	    v.pb(k);
	}
	sort(v.begin(),v.end());
	if(n==2){
	    if(v[0]==1){
	        cout<<2<<endl;
	    }else{
	        cout<<1<<endl;
	    }
	}else{
    	for(int i=0;i<n;i++){
    	    if(v[i]+1!=v[i+1]){
    	        cout<<v[i]+1<<endl;
    	        break;
    	    }
    	}
	}
}