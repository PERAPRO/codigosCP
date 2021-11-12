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
using pii=pair<ll,ll>;
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
const ll oo=1e15+7;
const int N=1e5+5;
const int M=2e5+5;

struct edge{
    ll a,b,w;
    edge(){}
    edge(ll a, ll b, ll w): a(a), b(b), w(w){}
};

vector<pii> g[N];
vector<pii> rg[N];
edge edges[M];

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        a--, b--;
        g[a].pb({b,w});
        rg[b].pb({a,w});
        edges[i] = {a,b,w};
    }
    
    vl distances(n,oo);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    distances[0]=0;
    q.push({0,0});
    while(q.size()){
        int u=q.top().ss;
        ll d=q.top().ff;
        q.pop();
        if(d != distances[u]) continue;
        for(pii child:g[u]){
            int v=child.ff;
            ll nd = child.ss + d;
            if(nd < distances[v]){
                distances[v] = nd;
                q.push({nd,v});
            }
        }
    }
    
    vl distances_2(n, oo);
    distances_2[n-1] = 0;
    q.push({0,n - 1});
    
    while(q.size()){
        int u=q.top().ss;
        ll d=q.top().ff;
        q.pop();
        if(d != distances_2[u]) continue;
        for(pii child:rg[u]){
            int v=child.ff;
            ll nd = child.ss + d;
            if(nd < distances_2[v]){
                distances_2[v] = nd;
                q.push({nd,v});
            }
        }
    }
    
    ll ans=oo;
    
    for(int i=0;i<m;i++){
        int from=edges[i].a, to = edges[i].b;
        ll w=edges[i].w/2;
        ckmin(ans, distances[from] + distances_2[to] + w);
    }
    
    cout<<ans<<el;
}

/*

*/