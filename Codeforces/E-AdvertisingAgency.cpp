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

const int mod=1e9+7;

vi fact(1001);
int fexp(int a, int b){
    ll ans=1;
    for(;b;a=(a*1LL*a)%mod,b>>=1){
        if(b&1) ans=(ans*1LL*a)%mod;
    }
    return ans;
}

int inverse(int a){
    return fexp(a,mod-2);
}

int cb(int n,int r){
    int res=fact[n];
    res=(res*1LL*inverse(fact[n-r]))%mod;
    res=(res*1LL*inverse(fact[r]))%mod;
    return res;
}


int main(){
	fast_io;
	fact[0]=1;
	for(int i=1;i<1001;i++){
	    fact[i]=(fact[i-1]*1LL*i)%mod;
	}
	//cout<<fact[3]<<endl;
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>n>>k;
	    vi bloggers(n);
	    vi cnt(1000);
	    for(int i=0;i<n;i++){
	        cin>>bloggers[i];
	        cnt[bloggers[i]]++;
	    }
	    sort(bloggers.begin(),bloggers.end(),greater<int>());
	    int maxSum=0;
	    map<int,int> m;
	    for(int i=0;i<k;i++){
	        maxSum+=bloggers[i];
	        m[bloggers[i]]++;
	    }
	    ll ans=1;
	    for(auto [key,value]:m){
	        ans=(ans*cb(cnt[key],cnt[key]-value))%mod;
	    }
	    cout<<ans<<endl;
	}
}
