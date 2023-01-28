/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

int n,x;
const int N = 1005;
const int X = 1e5+5;
int oo = 1e+9+7;
vi prices(N);
vi pages(N);

int dp[N][X];

int go(int i, int money){
    if(i > n) return -oo;
    if(money < 0) return -oo;
    // if(i == n - 1 && money) return -oo;
    if(i == n && money >= 0) return 0;
    
    int &ans = dp[i][money];
    
    if(ans == -1){
        // ans = 0;
        ans = max(go(i + 1, money), go(i + 1, money - prices[i]) + pages[i]);
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n>>x;
    
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    
    // memset(dp, -1, sizeof dp);
    // cout<<prices[0]<<el;
    
    for(int i=n - 1;i>=0;i--){
        for(int j = 0;j<=x;j++){
            dp[i][j] = dp[i + 1][j];
            if(j - prices[i] >= 0)
            dp[i][j] = max(dp[i][j], dp[i + 1][j - prices[i]] + pages[i]);
        }
    }
    
    int ans = 0;
    for(int j=0;j<=x;j++) ckmax(ans, dp[0][j]);
    cout<<ans<<el;
    // cout<<go(0,x)<<el;
    
}

/*

*/