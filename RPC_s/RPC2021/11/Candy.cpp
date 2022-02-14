/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
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

ostream& operator<<(ostream& os, const vector<ld> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const long double eps = 1e-7;
const ld oo = 1e9+7;

ll cdiv(ll a, ll b){
    return (a + b - 1) / b;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m;
    cin>>n>>m;
    ll s,t,c,a,b,w;
    cin>>s>>t>>c;
    
    vector<vector<pair<int,int>>> g(n + 1);
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].pb({b,w}), g[b].pb({a,w});
    }
    
    vector<long double> distances(n + 1, oo);
    vector<pair<int,int>> parent(n + 1 , make_pair(-1,0));
    
    distances[t] = 0;
    priority_queue<pair<long double, int>, vector<pair<ld,int>>, greater<pair<ld,int>>> q;
    q.push({0,t});
    
    while(q.size()){
        int u = q.top().ss;
        ld d = q.top().ff;
        q.pop();
        if(abs(distances[u] - d) > esp) continue;

        for(auto child:g[u]){
            int v = child.ff;
            ld w = child.ss;
            ld nd = ((100 - d) * w / 100) + d;
            if(nd + eps < distances[v]){
                distances[v] = nd;
                parent[v] = {u, child.ss};
                q.push({nd,v});
            }
        }
    }
    
    vector<int> path;
    
    int cur = s;
    while(cur != t){
        path.pb(parent[cur].ss);
        cur = parent[cur].ff;
    }
    
    ll cur_c = c;
    
    //for(auto val:path) cout<<val<<esp;
    reverse(all(path));
    
    for(auto p:path){
        cur_c -= cdiv(p * cur_c,100);
    }
    //cout<<fixed<<setprecision(10)<<eps;
    //cout<<distances<<el;
    cout<<cur_c<<el;
    
}

/*

*/