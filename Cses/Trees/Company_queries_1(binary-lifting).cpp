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
const int LOG2 = 25;
const int oo = 1e9+7;

vector<vi> jump (N, vi(LOG2));
vi depth(N);

void dfs(int u, int p){
    jump[u][0] = p;
    
    for(int j = 0;j + 1< LOG2;j++){
        jump[u][j + 1] = jump[jump[u][j]][j];
    }
    
    for(int v:g[u]){
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca (int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    
    for(int j = LOG2 - 1; j>=0; j--){
        if(depth[jump[u][0]] >= depth[v]){
            u = jump[u][j];
        }
    }
    
    if(u == v) return u;
    
    for(int j = LOG2 - 1; j>=0; j--){
        if(jump[u][j] != jump[v][j]){
            u = jump[u][j];
            v = jump[v][j];
        }
    }
    
    return jump[u][0];
}

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q;
    cin>>n>>q;

    for(int i=1;i<n;i++){
        int p; cin>>p;
        p--;
        g[i].pb(p), g[p].pb(i);
    }
    
    dfs(0, 0);
    
    for(int qq = 0;qq<q;qq++){
        int node, k;
        cin>>node>>k;
        node--;
        
        if(k > depth[node]) {
            cout<<-1<<el;
            continue;
        }
        
        for(int j = LOG2 - 1; j>=0; j--){
            if(k & (1<<j)){
                node = jump[node][j];
            }
        }
        
        cout<<++node<<el;
    }
    
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