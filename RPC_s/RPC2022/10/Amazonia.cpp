/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
// #define mp make_pair
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

const int N = 22;

int dp[N][(1<<N)];

const int mod = 1e9+7;
const int oo = 1e9+7;
vector<vi> mx(N, vi(N, oo));

int target, n, x;

map<int,int> mp;

int go(int node, int visited){
    if(visited == target) return 0;
    
    int &ans = dp[node][visited];
    
    if(ans == -1){
        ans = oo;
        for(int i = 0;i<n;i++){
            if( mx[node][i] && !(visited & (1<<i)) ){
                ckmin( ans, go(i, visited | (1<<i) ) + mx[node][i] );
            }
        }
    }
    return ans;
}

struct edge{
   int a,b,c;
   edge(){}
   edge(int a, int b, int c):a(a), b(b), c(c){}
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int m;
    cin>>n>>m>>x;
    
    target = (1<<n) - 1;
    //cout<<target<<el;
    memset(dp, -1, sizeof dp);
    
    vector<edge> edges;
    // vector<int> nodes(n);
    
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        // a--,b--;
        edges.pb(edge(a,b,w));
        mp[a]++;
        mp[b]++;
    }
    
    int node = 0;
    
    for(auto &[key, value]:mp){
        value = node++;
    }
    
    for(edge e: edges){
        ckmin(mx[mp[e.a]][mp[e.b]], e.c);
        ckmin(mx[mp[e.b]][mp[e.a]], e.c);
    }
    
    cout<<(go(mp[x],1<<mp[x]) == oo ? -1 : go(mp[x],1<<mp[x]))<<el;
    
    
}

/*

*/