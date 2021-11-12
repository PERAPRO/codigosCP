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

const int INF=1e9+7;

int bfs(int s, int t, vector<int>& parent, vector<vi> &adj, vector<vi> &capacity) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int max_flow(int s, int t, vector<vi> &adj, vector<vi> &capacity) {
    int flow = 0;
    vector<int> parent(adj.size());
    int new_flow;

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
    int n,m,k,a,b;
    cin>>n>>m>>k;
    int nn=n+m;
    
    vector<vi> g(nn+2);
    vector<vi> capacity(nn+2, vi(nn+2));
    
    int ss=0, st=nn+1;
    
    for(int i=1;i<=n;i++){
        g[0].pb(i), g[i].pb(0);
        capacity[0][i]=1;
    }
    
    for(int i=1;i<=m;i++){
        g[st].pb(i+n), g[i+n].pb(st);
        capacity[i+n][st]=1;
    }
    
    for(int i=0;i<k;i++){
        cin>>a>>b;
        bool check=0;
        for(int node:g[a])
            if(node == n+b) check=1;
        if(check) continue;
        g[a].pb(n+b), g[n+b].pb(a);
        capacity[a][n+b]=1;
    }
    //for(auto vv:capacity) cout<<vv;
    //for(auto vv:g) cout<<vv;
    int maxf=max_flow(ss, st, g, capacity);
    //cout<<el;
    //for(auto vv:capacity) cout<<vv;
    
    cout<<maxf<<el;
    queue<int> q;
    q.push(ss);
    while(q.size()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(u > 0){
                if(capacity[v][u] && v)
                    cout<<u<<esp<<v-n<<el;
            }else{
                q.push(v);
            }
        }
    }
}

/*

*/