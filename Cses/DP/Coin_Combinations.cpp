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
const int oo=1e7;
const int mod=1e9+7;

int n;
int dp[N];
int coins[105];


int go(int cap){
    if(cap < 0) return 0;
    if(cap == 0) return 1;
    int &ans=dp[cap];
    if(ans == -1){
        ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+go(cap-coins[i]))%mod;
        }
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>coins[i];
    memset(dp,-1,sizeof dp);
    cout<<go(x)<<el;
}

/*

*/