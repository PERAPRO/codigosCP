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
int n;
bool find(int k, vi &v){
    int lo=1,hi=n,m;
    while(lo<=hi){
        int m=(lo+hi)/2;
        if(v[m]==k) return 1;
        if(v[m]>k) hi=m-1;
        else lo=m+1;
    }
    //if((lo+hi)/2==k) return 1;
    //else 
        return 0;
}

int main(){
	fast_io;
	//int n;
	cin>>n;
	ll m,a,c,x0;
	cin>>m>>a>>c>>x0;
	vi v;
	v.pb(x0);
	for(int i=1;i<=n;i++){
	    v.pb((a*v[i-1]+c)%m);
	}
	//cout<<v;
	int ans=0;
    for(int i=1;i<=n;i++){
        if(find(v[i],v)) ans++;
    }
    cout<<ans<<el;
}