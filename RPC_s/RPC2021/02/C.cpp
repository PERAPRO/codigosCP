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
const int oo=1e8;
int n,m;
int queso[55];
int usos[55][55];

int memo[510][510];

int dp(int i,bool f,vi quesos){
    if(i==m) return 0;
    //int &ans=memo[i][];
    //if(ans!=-1) return ans;
    //vi aux=quesos;
    //cout<<i<<el<<quesos<<endl;
    if(f){
        for(int k=0;k<n;k++){
            quesos[k]-=usos[i][k];
            if(quesos[k]<0) return -oo;
        }
    }
    //cout<<i<<el<<quesos<<endl;
    return max(dp(i,1,quesos)+usos[i][n],dp(i+1,0,quesos));
}


int main(){
	fast_io;
	//int n,m;
	cin>>n>>m;
	vi quesos(55,0);
	for(int i=0;i<n;i++) {
	    cin>>quesos[i];
	    quesos[i]*=1000;
	    //cout<<quesos[i]<<el;
	}
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
	        double d;
	        cin>>d;
	        int c=d*10;
	        //cout<<c<<el;
	        usos[i][j]=c;
	    }
	    double t; cin>>t;
	    int g=t*10;
	    //cout<<g<<el;
	    usos[i][n]=g;
	}
	//memset(memo,-1,sizeof memo);
	int ans=dp(0,0,quesos);
	cout<<fixed<<setprecision(2)<<(ans)/10.0<<el;
}