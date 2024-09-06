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

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

int n,k;
const int maxn = 1002;
int dp[maxn][12*maxn];
int v[maxn][13];
int sums[maxn][13];
const int oo = 1e9;

int go(int idx, int rest){
    if(idx > n || rest < 0) return -oo;
    if(rest == 0) return 0;
    
    int &ans = dp[idx][rest];
    if(ans == -1){
        ans = -oo;
        ckmax(ans, go(idx + 1, rest));
        for(int i = 0;i<12;i++){
            ckmax(ans, go(idx + 1, rest - (i + 1)) + sums[idx][i]);
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
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<12;j++){
            cin>>v[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<12;j++){
            sums[i][j] = (j ? sums[i][j - 1] + v[i][j] : v[i][j]);
        }
    }
    
    // cout<<sums[0][1]<<el;
    
    memset(dp, -1, sizeof dp);
    
    cout<<go(0, k)<<el;
    
}

/*

*/