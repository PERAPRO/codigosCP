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
string yes="Yes";
string no="No";

int N, INF=1e8;

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
    //cout<<N<<esp<<parent.size()<<endl;
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
    int n,m,a,b,k,v,tc=1;
    while(cin>>n){
        if(!n) break;
        cin>>m;
        cout<<"Case "<<tc<<": ";
        
        priority_queue<int> sl; 
        vector<pair<int,pair<int,int>>> mk(n+1);
        int sum=0;
        
        for(int i=1;i<=n;i++){
            cin>>v>>a>>b;
            sum+=v;
            mk[i]={v,{a,b}};
            sl.push(-b);
            sl.push(-a);
        }
        
        set<pair<int,int>> intervalos;   //El intervalo de a a b consume unidades de [a,b), 
        
        int last=-sl.top(); sl.pop(); 
        
        while(sl.size()){
            int p= -sl.top();
            sl.pop();
                if(last == p) p++;
                if(p < last) {continue;}
                intervalos.insert({last,p});
                last=p;
        }
        
        int intsz=intervalos.size();
        int st=n+intsz+1, ss=0; N = n+intsz+2;
        
        vector<vi> g(N);
        vector<vi> capacity(N,vi(N));
        
        vector<pii> inv(intsz);
        int cnt=0;
        for(pii p:intervalos){
            inv[cnt].ff=p.ff, inv[cnt].ss=p.ss;
            assert(p.ff<p.ss);
            cnt++;
        }
        
        for(int i=1;i<=n;i++){
            g[ss].pb(i), g[i].pb(ss);
            capacity[ss][i]=mk[i].ff;
            for(int j=0;j<intsz;j++){
                if(mk[i].ss.ff<=inv[j].ff && mk[i].ss.ss>=inv[j].ss){
                    g[i].pb(n+j+1), g[n+j+1].pb(i);
                    capacity[i][n+j+1]=inv[j].ss-inv[j].ff;
                    
                    capacity[n+j+1][st]=(inv[j].ss-inv[j].ff)*m;
                } 
            }
        }
        
        for(int j=0;j<intsz;j++){
            g[n+j+1].pb(st), g[st].pb(n+j+1);
        }
        
        int flow=max_flow(ss,st,g,capacity);
        
        vector<vector<pii>> ans(n+1);
        vector<int> mark(50005,m);
        vector<int> idxs(intsz);
        vector<bool> visited(N);
        const int nn=n;
        bitset<50005> anss[nn];
        
        if(flow==sum){
            
            queue<int> q;
            q.push(0);
            while(q.size()){
                int cur=q.front(); q.pop();
                if(visited[cur]==1) continue;
                visited[cur]=1;
                for(int u:g[cur]){
                    if(cur>0){
                        if(capacity[u][cur] && u){
                            pii p=inv[u-(n+1)];
                            int uu=capacity[u][cur];
                            int &ii=idxs[u-(n+1)];
                            for(int i=p.ff;uu>0 && mk[cur].ff>0 && i<p.ss;i++,ii++){
                                
                                if(mark[p.ff+ii%(p.ss-p.ff)]){
                                    anss[cur-1][p.ff+ii%(p.ss-p.ff)]=1;
                                    mk[cur].ff--;
                                    mark[p.ff+ii%(p.ss-p.ff)]--,uu--;
                                }
                            }
                        }
                    }
                    if(u<=n) q.push(u);
                }
            }
            cout<<yes<<endl;
            
            for(int i=1;i<=n;i++){
                pii curinit={-1,-1};
                for(int j=0;j<50005;j++){
                    if(anss[i-1][j] && curinit.ss<0){//Primera ocurrencia
                        curinit={j,j};
                        continue;
                    }
                    if(j>0 && anss[i-1][j] && curinit.ss==j-1){
                        curinit.ss=j;//Crece mi pareja actual
                        continue;
                    }
                    if(j>0 && anss[i-1][j] && curinit.ss!=j-1){//Cambio de pareja
                        ans[i].pb(curinit);
                        curinit={j,j};
                        continue;
                    }
                }
                ans[i].pb(curinit);
                cout<<ans[i].size();
                for(pii p:ans[i]) cout<<esp<<'('<<p.ff<<','<<p.ss+1<<')';
                if(i!=n) cout<<endl;
            }
            cout<<el;
        }else{
            cout<<no<<el;
        }
        tc++;
    }
}

/*

*/