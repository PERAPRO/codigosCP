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

int n;
const int N = 505;
const int mod = 1e9+7;

int dp[N][N*N];

int go(int i, int sum){
    if(i == n + 1 && sum == (n * (n + 1)) / 2 - sum) return 1;
    if(i == n + 1) return 0;
    
    int &ans = dp[i][sum];
    if(ans == -1){
        ans = (go(i + 1, sum + i) + go(i + 1, sum)) % mod;
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    // int n;
    cin>>n;
    
    memset(dp, -1, sizeof dp);
    
    cout<<(go(1, 0) * 1LL * 500000004) % mod<<el;

}

/*

*/