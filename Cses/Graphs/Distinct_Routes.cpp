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

const int INF = 1e9+7;

multiset<pii> edgesu;
set<pii> edges;

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
            if(edges.count({prev,cur})){
                edgesu.insert({prev,cur});
            }else{
                if(edgesu.count({cur,prev})) edgesu.erase(edgesu.find({cur,prev}));
            }
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
    vector<vi> g(n+2);
    vector<vi> capacity(n+2, vi(n+2));
    //set<pii> edges;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        capacity[a][b]++;
        edges.insert({a,b});
        if(count(g[a].begin(), g[a].end(), b)) continue;
        g[a].pb(b), g[b].pb(a);
    }
    int ss=0, st=n+1;

    g[0].pb(1), g[1].pb(0);
    capacity[0][1]=INF;

    g[n].pb(st), g[st].pb(n);
    capacity[n][st]=INF;
    //cout<<16<<endl;
    int flow=max_flow(ss, st, g, capacity);
    //cout<<16<<endl;
    cout<<flow<<el;

    for(int i=0;i<flow;i++){
        vi ans;
        int cur=1;
        ans.pb(1);
        int u=edgesu.begin()->ff, v=edgesu.begin()->ss;
        edgesu.erase(edgesu.begin());
        while(v != n){
            pii next = *edgesu.lower_bound({v,0});
            u=next.ff, v=next.ss;
            edgesu.erase(edgesu.find({u,v}));
            ans.pb(u);
        }
        ans.pb(v);
        cout<<ans.size()<<el<<ans;
    }

}

/*
11 12
1 2
2 3
3 4
4 5
5 11
3 9
6 7
7 8
8 9
9 10
10 11
1 6


7 9
1 2
1 3
2 7|
3 4
3 5
4 7
5 7
1 6
6 3
*/