#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
const lli mod=((1LL<<31)-1);
const int N = 1e4+1;
const int INF = 1000000000;

vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
int main(){
    fast_io;
    int n,l,q;cin>>n>>l>>q;
    adj.resize(n);
    REP(o,l){
        int i,j,t;
        cin>>i>>j>>t;
        i--;j--;
        adj[i].pb({j,t});
        adj[j].pb({i,t});
    }
    REP(o,q){
        int i,j,t;
        cin>>i>>j;
        //void dijkstra(int s, vector<int> & d, vector<int> & p) {
        i--;j--;
        vi d;
        vi p;
        dijkstra(i,d,p);
        cout<<d[j]<<endl;
    }
    return 0;
}