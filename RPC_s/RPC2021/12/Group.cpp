/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
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

const int N = 1e5+5;

vi g[N];

int visited[N], color[N];

int dfs(int u, int c){
    visited[u]=1;
    color[u]=c;
    for(int v:g[u]){
        if(!visited[v]){
            if(!dfs(v,!c)) return 0;
        }else{
            if(color[u] == color[v]) return 0;
        }
    }
    return 1;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        g[a].pb(b), g[b].pb(a);
    }
    
    dfs(0,0);
    
    vi teams(2);
    
    for(int i=0;i<n;i++){
        teams[color[i]]++;
    }
    if((teams[0] & 1) && (teams[1] & 1) && teams[0] * teams[1] == m){
        cout<<n / 2 - 1<<el;
    }else{
        cout<<n / 2<<el;
    }
}

/*

*/