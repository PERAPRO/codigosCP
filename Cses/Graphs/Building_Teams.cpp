/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
using pii=pair<int,int>;
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
char el = '\n';
char esp = ' ';

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

int oo=1e9+7;
const int N=1e5+5;

bitset<N> color;
bitset<N> visited;
vector<vi> g;


int dfs(int u, int c){
    ///cout<<u<<esp<<c<<el;
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
    g.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].pb(b), g[b].pb(a);
    }
    bool f=1;
    for(int i=1;i<=n;i++){
        if(!visited[i]) f &= dfs(i,0);
    }
    if(f){
        for(int i=1;i<=n;i++){
            if(color[i]) cout<<1;
            else cout<<2;
            if(i>0) cout<<esp;
        }
    }else
        cout<<"IMPOSSIBLE"<<el;
    
}

/*

*/