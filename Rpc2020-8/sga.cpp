/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	int n;
	cin>>n;
	map<string,pair<string,int>> m;
	vector<int> rep(26);
	for(int i=0;i<n;i++){
	    string s;
	    cin>>s;
	    rep[s[0]-'a']++;
	    m[s].first=s;
	    m[s].second++;
	}
	//for(auto p:rep) cout<<p<<endl;
	ll ans=0;
	for(auto it = m.begin();it!=m.end();it++){
	  auto x=it->second;
    //cout<<x.first<<" "<<x.second<<endl;
    int pos=x.first[0]-'a';
    int uva=x.second;
    ans+=(rep[pos]-uva)*uva;
	}
//	for(auto x:m){
//	    int pos=x.first[0]-'a';
//	    int uva=x.second;
//	    ans+=(rep[pos]-uva)*;
//	}
	cout<<ans<<endl;
	//cout<<m["hola"].second<<endl;
}
