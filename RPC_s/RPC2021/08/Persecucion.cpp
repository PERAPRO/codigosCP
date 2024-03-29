/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
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

bool visited[20];

vector<vi> g(20);

int cc=0;

void dfs(int u){
    visited[u]=1;
    for(int v:g[u]){
        if(!visited[v])
            dfs(v);
    }
    cc++;
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
        g[a].pb(b), g[b].pb(a);
    }
    
    int mx=0;
    
    for(int i=1;i<=n;i++){
        if(!visited[i])
            dfs(i);
        ckmax(mx,cc);
        cc=0;
    }
    
    cout<<mx<<el;
    
}

/*

*/