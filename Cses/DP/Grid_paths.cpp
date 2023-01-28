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

const int N = 1e3+5;
const int mod = 1e9+7;
int n;

vector<string> v(N);

int dp[N][N];

int solve(int i, int j){
    if(v[i][j] == '*') return 0;
    if(i >= n || j >= n) return 0;
    if(i == n - 1 && j == n - 1) return 1;
    
    int &ans = dp[i][j];
    if(ans == -1){
        ans = (solve(i + 1, j) + solve(i, j + 1)) % mod;
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
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    memset(dp, -1, sizeof dp);
    
    cout<<solve(0,0)<<el;
    
}

/*

*/