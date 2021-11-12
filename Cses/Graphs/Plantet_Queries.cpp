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

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q,x,k;
    cin>>n>>q;
    vector<vi> g(n+1);
    for(int i=1;i<=n;i++){
        cin>>x;
        g[i].pb(x);
    }

    vector<vi> distances(n+1);
    vector<int> distances2(n+1);
    vector<bool> visited(n+1);
    vector<pii> maxs(n+1);
    vector<int> parents(n+1);
    vi topo;

    function<void(int)> dfs = [&] (int u){
        if(visited[u]) return;
        visited[u]=1;
        for(int v:g[u]){
            dfs(v);
        }
        topo.pb(u);
    };
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }

    reverse(topo.begin(),topo.end());

    fill(visited.begin(),visited.end(),0);
    //cout<<topo;

    for(int i=1;i<=n;i++) maxs[i]={i,i};

    function<void(int)> bfs = [&] (int u){
        queue<int> q;
        q.push(u);
        distances[u].pb(u);
        distances2[u]=0;
        parents[u]=u;
        while(q.size()){
            int v=q.front(); q.pop();
            //if(visited[v]) break;
            visited[v]=1;
            for(int c:g[v]){
                if(!visited[c]) {
                    parents[c] = u;
                    distances2[c] = distances[u].size();
                    distances[u].pb(c);
                    q.push(c);
                }else{
                    maxs[u]={c,v}; //Marco donde comienza el ciclo y quien lo marco
                }
            }
        }
    };

    //for(pii p: distances) cout<<p.ff<<esp<<p.ss<<el;
    for(int i=0;i<n;i++){
        if(!visited[topo[i]])bfs(topo[i]);
    }

    for(int Q=0;Q<q;Q++){
        cin>>x>>k;
        int parent=parents[x];
        int from_x_to_fin=distances[parent].size()-distances2[x];
        if(from_x_to_fin<=k){
            //Tengo que calcular la longitud del ciclo
            int l=distances[parent].size()-distances2[maxs[parent].ff];
            int dif=k-from_x_to_fin;
            int nodo_final=dif%l;
            cout<<distances[parent][distances2[maxs[parent].ff]+nodo_final]<<el;
        }else{
            //Lo hago normi
            cout<<distances[parent][distances2[x]+k]<<el;
        }

    }
}

/*

*/