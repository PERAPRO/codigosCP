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
//2*26+26*26+2
const int N=2*26+26*26+2;
const int INF=1e8+9;

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
    vector<int> parent(N);
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
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cout<<"Case #"<<t<<":"<<el;
        int n;
        cin>>n;
        
        vector<vi> g(N);
        vector<vi> capacity(N,vi(N));
        vector<vector<pair<string,int>>> names(26);
        
        int nodes=n;
        for(int nn=1;nn<=n;nn++){
            g[0].pb(nn), g[nn].pb(0);
            capacity[0][nn]=1;
            //cout<<nodes<<endl;
            int cantidad;
            cin>>cantidad;
            string name;
            for(int i=1;i<=cantidad;i++,nodes++){
                g[nn].pb(nodes+1), g[nodes+1].pb(nn);
                capacity[nn][nodes+1]=1;
                cin>>name;
                for(char &c:name) c = tolower(c);
                name[0] = toupper(name[0]);
                //cout<<nn<<esp<<i<<esp<<nodes+1<<esp<<name<<endl;
                names[name[0]-'A'].pb({name,nodes+1});
            }
        }
        //Otros 26 nodos? o solo n
        
        int ss=0;
        int st=nodes+n+1;
        for(int i=1;i<=n;i++){
            for(auto j:names[i-1]){
                string k=j.ff;
                int node=j.ss;
                g[node].pb(nodes+i),g[nodes+i].pb(node);
                capacity[node][nodes+i]=1;
            }
            g[nodes+i].pb(st), g[st].pb(nodes+i);
            capacity[nodes+i][st]=1;
        }
        //cout<<"graph"<<el;
        int flow=max_flow(0,st,g,capacity);
        //for(auto vv:capacity) if(vv.size())cout<<vv;
        //cout<<flow<<el;
        //Armar la solucion
        
        vector<string> ans(n);
        bitset<N> visited;
        queue<int> q;
        q.push(st);
        while(q.size()){
            int cur=q.front();
            q.pop();
            visited[cur]=1;
            for(int u:g[cur]){
                if(visited[u]) continue;
                if(cur != st && capacity[cur][u]){
                    int letra=cur-(st-n);
                    //cout<<letra<<el;
                    for(int i=0;i<names[letra].size();i++){
                        if(names[letra][i].ss==u){
                            ans[letra]=names[letra][i].ff;
                            break;
                        }
                    }
                    break;
                }
                if(cur>=st-n) q.push(u);
            }
        }
        for(string a:ans) cout<<a<<el;
    }
}

/*
4
3
2 Apples Oranges
1 Bananas
5 Apricots Blueberries Cranberries Zuccini Yams
1
1 ApPlEs
2
2 a b
1 axe
4
4 Aa Ba Ca Da
3 Ab Bb Cb
2 Ac Bc
1 Ad

*/