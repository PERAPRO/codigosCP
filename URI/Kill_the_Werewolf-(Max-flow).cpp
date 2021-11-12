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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";
int INF=1e9+7;

int n;

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

int max_flow(int s, int t,vector<vi> &adj, vector<vi> &capacity) {
    int flow = 0;
    vector<int> parent(n+n+2);
    int new_flow;

    while (new_flow = bfs(s, t, parent, adj, capacity)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            //cout<<cur<<esp<<new_flow<<esp<<esp;
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
        //cout<<el;
    }

    return flow;
}




int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n;
    vector<pii> v(n+1);
    vector<vi> g(n+n+2);
    vi cs(n+1);
    vector<vi> capacity(n+n+2,vector<int>(n+n+2));
    
    for(int i=1;i<=n;i++){
        cin>>v[i].ff>>v[i].ss;
        cs[v[i].ff]++,cs[v[i].ss]++;
        v[i].ff+=n, v[i].ss+=n;
        g[i].pb(v[i].ff),g[v[i].ff].pb(i);
        g[i].pb(v[i].ss),g[v[i].ss].pb(i);
        g[0].pb(i),g[i].pb(0);
        g[i+n].pb(n+n+1),g[n+n+1].pb(i+n);
    }
    
    int ans=0;
    
    //for(auto vv:g) cout<<vv;
    //cout<<el;
    
    for(int i=1;i<=n;i++){
        //Yo soy el lobo
        //Super source->0 super sink -> n+n+1
        for(auto &vv:capacity) fill(vv.begin(),vv.end(),0);
        for(int j=1;j<=n;j++){
            capacity[0][j]=1;
            capacity[j][v[j].ff]=INF;
            capacity[j][v[j].ss]=INF;
            capacity[v[j].ff][n+n+1]=max(0,cs[i]-1);
            capacity[v[j].ss][n+n+1]=max(0,cs[i]-1);
        }
        capacity[0][i]=0;
        capacity[v[i].ff][n+n+1]=max(0,cs[i]-2);
        capacity[v[i].ss][n+n+1]=max(0,cs[i]-2);
        capacity[i+n][n+n+1]=cs[i];
        
        //for(auto vv:capacity) cout<<vv;
        int flow=max_flow(0,n+n+1,g,capacity);
        //cout<<cs[i]<<esp<<flow<<el;
        if(flow<n-1) ans++;
    }
    
    cout<<ans<<el;
}

/*
5
3 4
1 3
2 4
1 3
2 3

4

4
3 4
1 4
4 1
3 1

2
*/