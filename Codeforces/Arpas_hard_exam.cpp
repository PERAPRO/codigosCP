/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

ll fexp(ll base, int expo){
    ll ans=1;
    for(;expo;base=(base*base)%10,expo>>=1){
        if(expo&1){
            ans=(ans*base)%10;
        }
    }
    return ans;
}


int main(){
	fast_io;
	ll n;
	cin>>n;
	ll ans=fexp(8,n);
	cout<<ans%10<<endl;
}