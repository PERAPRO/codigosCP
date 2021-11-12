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
const int N=1e5+5;
const int oo=1e9;

vector<vi> g;
stack<int> topo;
bitset<N> visited;

void dfs(int u){
    visited[u]=1;
    for(int v:g[u]){
        if(!visited[v]) dfs(v);
    }
    topo.push(u);
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
        g[a].pb(b);
    }
    
    vi distances (n+1,-oo);
    vi parent(n+1);
    
    distances[1]=0;
    dfs(1);
    while(topo.size()){
        int u=topo.top(); topo.pop();
        int d=distances[u];
        for(int v:g[u]){
            if(distances[v] < d+1)
                distances[v]=d+1, parent[v]=u;
        }
    }
    if(distances[n] == -oo){
        cout<<"IMPOSSIBLE"<<el;
    }else{
        vi ans;
        a=n;
        while(a != 1){
            ans.pb(a);
            a=parent[a];
        }
        ans.pb(1);
        cout<<ans.size()<<el;
        for(int i=ans.size()-1;i>-1;i--) cout<<ans[i]<<esp;
        cout<<el;
    }
}

/*

*/