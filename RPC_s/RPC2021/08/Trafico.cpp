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

int oo=1e9+7;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    map<int,set<int>> m;
    
    int n,mm,k,a,b;
    cin>>n>>mm>>k;
    vector<vi> g(n);
    for(int i=0;i<mm;i++){
        cin>>a>>b;
        g[a].pb(b), g[b].pb(a);
    }
    
    vi distances(n,oo);
    
    queue<int> q;
    q.push(k);
    distances[k]=0;
    
    while(q.size()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(distances[u] + 1 < distances[v]){
                distances[v]= distances[u] + 1;
                m[distances[u] + 1].insert(v);
                q.push(v);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(distances[i] == oo){
            m[0].insert(i);
        }
    }
    
    for(auto &[key,value]:m){
        cout<<key<<":";
        for(int node:value){
            cout<<esp<<node;
        }
        cout<<el;
    }
    
}

/*

*/