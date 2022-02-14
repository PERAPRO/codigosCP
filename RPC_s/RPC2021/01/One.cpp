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

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	    int p,e; cin>>p>>e;
	    if(p-e>9) cout<<"YES\n";
	    else cout<<"NO\n";
	}
}