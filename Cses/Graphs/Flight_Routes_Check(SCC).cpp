/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
using pii=pair<long long ,long long>;
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

ll oo=1e17+7;
const int N=1e5+5;

vector<vi> g;
vector<vi> rg;
vi topo;
bitset<N> visited;

void dfs1(int u){
    visited[u]=1;
    for(int v:g[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    topo.pb(u);
}
vector<vi> cc;
void dfs2(int u){
    visited[u]=1;
    for(int v:rg[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }
    cc.back().pb(u);
}

void dfs3(int u){
    visited[u]=1;
    for(int v:g[u]){
        if(!visited[v]) dfs3(v);
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
    
    g.resize(n+1),rg.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].pb(b);
        rg[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs1(i);
    }
    
    visited.reset();
    
    for(int i=n-1;i>=0;i--){
        if(!visited[topo[i]]){
            cc.pb(vi());
            dfs2(topo[i]);
        }
    }
    //cout<<topo<<el;
    //for(auto vv:cc) cout<<vv;
    
    if(cc[0].size() == n){
        cout<<yes<<el;
    }else{
        cout<<no<<el;
        visited.reset();
        dfs3(cc[0][0]);
        if(visited[cc[1][0]]) cout<<cc[1][0]<<esp<<cc[0][0]<<el;
        else cout<<cc[0][0]<<esp<<cc[1][0]<<el;
    }
}

/*

*/