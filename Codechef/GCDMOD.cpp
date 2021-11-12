/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

const ll mod =1e9+7;

ll fexp(ll base, ll expo, ll m){
    ll ans=1;
    for(;expo;base=((base%m)*(base%m))%m,expo>>=1){
        if(expo&1){
            ans=((ans%m)*(base%m))%m;
        }
    }
    return ans;
}

ll gcd(ll a, ll b, ll n){
    if(a==b){
        return (fexp(a,n,mod)+fexp(b,n,mod))%mod;
    }
    ll candidate=1;
    ll num=a-b;
    for(ll i=1;i*i<=num;i++){
        if(num%i==0){
            ll aux=(fexp(a,n,i)+fexp(b,n,i))%i;
            if(aux%i==0) candidate=max(candidate,i);
            
            aux=(fexp(a,n,num/i)+fexp(b,n,num/i))%(num/i);
            if(aux%(num/i)==0) candidate=max(candidate,num/i);
        }
    }
    return candidate%mod;
}


int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	while(testcases--){
	    ll a,b,n;
	    cin>>a>>b>>n;
	    cout<<gcd(a,b,n)<<endl;
	}
}