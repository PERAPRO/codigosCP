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

const int N = 2e5+5;

vector<vi> g(N);
vector<vi> dp(N, vi(2, -1));

// if f, mi padre y yo usamos la arista

int solve(int u, int p, int f){
    if(dp[u][f] != -1){
        return dp[u][f];
    }
    
    int ans1 = 0;
    
    for(int v:g[u]){
        if(v == p) continue;
        ans1 += solve(v, u, 1);
    }
    
    int ans = 0;
    
    for(int v:g[u]){
        if(v == p) continue;
        if (f)
            ckmax(ans, solve(v, u, 0) + 1 + ans1 - solve(v, u, 1));
    }
    
    return dp[u][f] = max(ans, ans1);
    
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n; cin>>n;
        
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b), g[b].pb(a);
    }
    
    
    cout<<solve(0, -1, 1)<<el;
    
}

/*
8
1 2
1 3
2 4
3 5
3 6
4 7
4 8

10
7 5
5 3
7 4
1 9
9 2
10 1
8 1
8 6
4 8

*/