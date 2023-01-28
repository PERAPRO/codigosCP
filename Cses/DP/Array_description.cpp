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
int m;
const int N = 1e5+5;
const int M = 1e2+5;
const int mod = 1e9+7;
int dp[N][M];
vi v(N);

vi take(int n){
    vi ans;
    for(int i=n - 1;i<=n + 1;i++){
        if(i > 0 && i <= m){
            ans.pb(i);
        }
    }
    return ans;
}

int go(int i, int j){
    if(v[i] && j && abs(v[i] - j) > 1){return 0;}
    if(i == n) return 1;
    
    int &ans = dp[i][j];
    
    if(ans == -1){
        ans = 0;
        if(!v[i] && !j){
            for(int k = 1;k<=m;k++){
                ans = (ans + go(i + 1, k)) % mod;
            }
        }else if(!v[i]){
            for(int k=j - 1;k<=j + 1;k++){
                // cout<<value<<el;
                if(k > 0 && k <= m)
                    ans = (ans + go(i + 1, k)) % mod;
            }
        }else
            ans = go(i + 1, v[i]);
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    memset(dp, -1, sizeof dp);
    
    cout<<go(0, 0)<<el;
}

/*

*/