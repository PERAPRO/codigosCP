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

bool f=0;

void dfs(int u, int p){
    visited[u]=1;
    for(int v:g[u]){
        if(!visited[v]){
            dfs(v,u);
        }else{
            if(v != p) f= 1;
        }
    }
}

bool fnd=0;

void build(int u, int p, int t){
    visited[u]=1;
    cout<<u<<esp;
    for(int v:g[u]){
        if(!visited[v] && !fnd){
            build(v,u,t);
        }else {
            if(v == t && v != p){
                fnd=1;
                cout<<v<<esp;
            }
        }
    }
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
    for(int i=1;i<=n;i++){
        dfs(i,0);
        if(f){
            visited.reset();
            build(i,0,i);
            return 0;
        }
    }
}

/*

*/