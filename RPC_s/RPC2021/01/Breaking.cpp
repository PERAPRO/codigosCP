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
int minf=-1e9;
int n,k;

int dp[10005][105];
int estudio[10005], diversion[10005];

ll f(int i, int est){
    if(i>=n){
        if(est>0)
            return minf;
        else return 0;
    }
    int  &ans=dp[i][est];
    if(ans!=-1)
        return ans;
    return ans=max(f(i+1,max(0,est-estudio[i])),f(i+1,est)+diversion[i]);
}

int main(){
	fast_io;
	int t;
	cin>>t;
	//int k;
	//cin>>k;
	int a,b,c;
	while(t--){
	    cin>>n>>k;
	    for(int i=0;i<n;i++){
	        cin>>a>>b>>c;
	        estudio[i]=a;
	        diversion[i]=max(b,c);
	    }
        memset(dp,-1,sizeof dp);
	    ll ans=f(0,k);
	    if(ans<0)
	        cout<<"NO SOLUTION\n";
	    else cout<<ans<<el;
	}
}