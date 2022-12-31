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

vector<set<int>> g(N);
vi par(N);
vi sub(N);
vi centroids;

int dfs1(int node, int p){
    sub[node] = 1;
    
    for(int v:g[node]){
        if(v == p) continue;
        sub[node] += dfs1(v, node);
    }
    
    return sub[node];
}

int dfs(int node, int p, int n){
    
    for(int v:g[node]){
        if(v != p && sub[v] > n/2){
            return dfs(v, node, n);
        }
    }
    return node;
}

void decompose(int node, int p){
    int subsize = dfs1(node, -1);
    
    int centroid = dfs(node, p, subsize);
    
    par[centroid] = p;
    
    centroids.pb(centroid);
    
    for(int v:g[centroid]){
        g[v].erase(centroid), decompose(v, centroid);
    }
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].insert(b), g[b].insert(a);
    }
    
    decompose(0,-1);
    
    cout<<centroids[0] + 1<<el;
}

/*

*/