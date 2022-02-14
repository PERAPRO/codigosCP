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

const int N=1e5+5;

vi g[N];
int color[N];
int parent[N];
bitset<N> visited;
int cycle_start = -1, cycle_end;

bool dfs1 (int u){
    color[u]=1;
    for(int v:g[u]){
        if(!color[v]){
            parent[v]=u;
            if(dfs1(v))
                return 1;
        }else if(color[v] == 1){
            cycle_end=u;
            cycle_start=v;
            return 1;
        }
    }
    color[u] = 2;
    return 0;
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
        g[a].pb(b);
    }
    memset(parent,-1,sizeof parent);
    
    for(int i=1;i<=n;i++){
        if(!color[i] && dfs1(i))
            break;  
    }
    if(cycle_start == -1){
        cout<<"IMPOSSIBLE"<<el;
    }else{
        vi cycle;
        cycle.pb(cycle_start);
        for(int v=cycle_end; v != cycle_start; v=parent[v])
            cycle.pb(v);
        cycle.pb(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout<<cycle.size()<<el;
        cout<<cycle;
    }
}

/*

*/