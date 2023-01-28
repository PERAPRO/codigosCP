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
const int N = 105;
const int X = 1e5+5;
const int mod = 1e9+7;
int dp[N][X];

vi values(N);

int go(int i, int x){
    if(i == n && !x) return 1;
    if(x < 0) return 0;
    if(i > n) return 0;
    
    int &ans = dp[i][x];
    if(ans == -1){
        ans = go(i + 1, x) || go(i + 1, x - values[i]);
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
        cin>>values[i];
    }
    memset(dp, -1, sizeof dp);
    vi ans;
    
    
    for(int i=1;i<X;i++){
        if(go(0,i))
            ans.pb(i);
            // cout<<i<<esp;
    }
    
    cout<<ans.size()<<el<<ans;
}

/*

*/