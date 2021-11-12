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

const ll INF=ll(1e16)+7;

ll bfs(int s, int t, vector<int>& parent, vector<vi> &adj, vector<vector<ll>> &capacity) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll max_flow(int s, int t, vector<vi> &adj, vector<vector<ll>> &capacity) {
    ll flow = 0;
    vector<int> parent(adj.size());
    ll new_flow;

    while (new_flow = bfs(s, t, parent, adj, capacity)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b;
    cin>>n>>m;
    ll c;
    
    vector<vi> g(n+2);
    vector<vector<ll>> capacity(n+2, vector<ll>(n+2));
    
    int ss=0, st=n+1;
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a == b || a == n) continue;
        bool check=0;
        for(int node:g[a])
            if(node == b) check=1;
        capacity[a][b]+=c;  
        //ckmax(capacity[a][b],c);
        if(check) continue;
        g[a].pb(b), g[b].pb(a);
    }
    
    g[0].pb(1), g[1].pb(0);
    capacity[0][1]=INF;
    
    g[n].pb(st), g[st].pb(n);
    capacity[n][st]=INF;
    
    //for(auto vv:capacity) cout<<vv;
    //for(auto vv:g) cout<<vv;
    ll maxf=max_flow(ss, st, g, capacity);
    //cout<<el;
    //for(auto vv:capacity) cout<<vv;
    
    cout<<maxf<<el;
}

/*

*/