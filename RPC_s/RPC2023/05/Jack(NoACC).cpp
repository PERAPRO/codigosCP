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

const int N = 305;
const int S = 1e3+5;
int dp[N*S][N][2];
int v[N];

int go(int sum, int idx, int use){
    if(!sum) return 1;
    if(sum < 0) return 0;
    if(idx >= n && sum) return 0;
    
    int &ans = dp[sum][idx][use];
    if(ans == -1){
        ans = 0;
        if(use) {
            ans |= go(sum - v[idx], idx + 1, 1);
            ans |= go(sum - v[idx], idx + 1, 0);
        }
        else{
            ans |= go(sum, idx + 1, 1);
            ans |= go(sum, idx + 1, 0);
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
    // int n;
    cin>>n;
    
    int total = 0;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
        total += v[i];
    }
    
    vi candidates;
    
    memset(dp, -1, sizeof dp);
    
    for(int i=0;i<n;i++){
        int sum = total - v[i];
        if(sum & 1) continue;
        go(sum / 2, 0, 0);
        go(sum / 2, 0, 1);
        cout<<sum<<el;
        cout<<dp[sum / 2][i][0]<<el;
        if(dp[sum / 2][i][0]) candidates.pb(v[i]);
    }
    
    sort(all(candidates));
    
    cout<<candidates;
    
}

/*

*/