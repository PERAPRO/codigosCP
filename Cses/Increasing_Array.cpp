#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;



int main(){
	fast_io;
	ll pasos=0;
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++){
	    ll k;
	    cin>>k;
	    v.pb(k);
	}
	for(ll i=0;i<n-1;i++){
	    if(v[i]>v[i+1]){
	        pasos+=(v[i]-v[i+1]);
	        v[i+1]+=(v[i]-v[i+1]);
	    }
	}
	cout<<pasos<<endl;
}