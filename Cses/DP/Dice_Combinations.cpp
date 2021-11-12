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
char esp = ' ';

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";
const int N=1e6+5;
const int oo=1e9;
const int mod=1e9+7;

int n;
int dp[N];

int go(int i){
    if(i > n) return 0;
    if(i == n) return 1;
    int &ans=dp[i];
    if(ans == -1){
        ans=0;
        for(int j=1;j<=6;j++) ans=(ans+go(i+j))%mod;
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<go(0)<<el;
}

/*

*/