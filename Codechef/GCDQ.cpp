/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	int testcases;cin>>testcases;
	while(testcases--){
	    int n,q;
	    cin>>n>>q;
	    vi v(n+1);
	    for(int i=1;i<=n;i++) cin>>v[i];
	    vi pre(n+2);
	    for (int i=1;i<=n;i++){
	        pre[i]=__gcd(pre[i-1],v[i]);
	    }
	    vi suf(n+2);
	    for(int i=n;i>-1;i--){
	        suf[i]=__gcd(suf[i+1],v[i]);
	    }
	    for(int i=0;i<q;i++){
	        int l,r;
	        cin>>l>>r;
	        int g=__gcd(pre[l-1],suf[r+1]);
	        cout<<g<<endl;
	    }
	}
}