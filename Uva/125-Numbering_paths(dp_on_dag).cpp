/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int N = 32;

bitset<N> visited;
bitset<N> is_cycle;


int main(){
fast_io;
/*
  freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    int e;
    while(cin>>e){
        cout<<"matrix for city "<<tc<<endl;
        tc++;
       
        vector<vi> g(N);
       
        vector<vi> rg(N);
       
        vi topo;
       
        vector<vi> cc;
        visited.reset();
        is_cycle.reset();
       
        int mx = 0;
       
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            rg[b].pb(a);
            ckmax(mx, a + 1);
            ckmax(mx, b + 1);
        }
       
        function<void(int)> dfs1 = [&](int u){
            visited[u]=1;
            for(int v:g[u]){
                if(!visited[v]){
                    dfs1(v);
                }
            }
            topo.pb(u);
        };
       
        function<void(int)> dfs2 = [&](int u){
            visited[u]=1;
            for(int v:rg[u]){
                if(!visited[v]){
                    dfs2(v);
                }
            }
            cc.back().pb(u);
        };
       
        for(int i=0;i<N;i++){
            if(!visited[i]) dfs1(i);
        }
       
        visited.reset();
       
        for(int i=N-1;i>=0;i--){
            if(!visited[topo[i]]){
                cc.pb(vi());
                dfs2(topo[i]);
            }
        }
       
        vector<vi> ans(mx, vi(mx));
       
       
        function<void(int)> mark = [&] (int u){
            vi vis(mx);
            queue<int> q;
            vis[u] = 1;
            q.push(u);
            ans[u][u] = -1;
            vi alcanzables;
            while(q.size()){
                int node = q.front();
                alcanzables.pb(node);
                q.pop();
               
                for(int v:g[node]){
                    if(!vis[v]){
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
           
            fill(all(vis), 0);
            vis[u] = 1;
            q.push(u);
           
            vi me_alcanzan;
            while(q.size()){
                int node = q.front();
                q.pop();
                me_alcanzan.pb(node);
               
                for(int v:rg[node]){
                    if(!vis[v]){
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            //cout<<alcanzables;
            for(int from:me_alcanzan){
        //        cout<<"source "<<u<<esp<<from<<el;
                for(int to:alcanzables){
                    ans[from][to] = -1;
                }
            }
        };
       
        for(int i = 0;i<cc.size();i++){
            if(cc[i].size() > 1) {  
                for(auto u:cc[i]){
                    // cout<<"soy ciclo "<<u<<esp;
                    is_cycle[u] = 1;
                }
                mark(cc[i][0]);
            }
        }
       
        // cout<<is_cycle.to_string()<<el;
       
        vi cur(mx, -1);
       
        function<int(int, int)> get_ans = [&](int u, int t){
            if(is_cycle[u]) return 0;
            if(u == t) return 1;
           
            int &res = cur[u];
           
            if(res == -1){
                res = 0;
                for(int v:g[u]){
                    res = res + get_ans(v, t);
                }
            }
            return res;
        };
       
        for(int i = 0;i<mx;i++){
            if(is_cycle[i]) continue;
            for(int j = 0;j<mx;j++){
                if(is_cycle[j]) continue;  
                if(i == j) continue;
                ans[i][j] = get_ans(i,j);
                replace(all(cur), -1, 0);
                fill(all(cur), -1);
            }
        }
       
        for(int i = 0;i<cc.size();i++){
            if(cc[i].size() > 1) {
                mark(cc[i][0]);
            }
        }
       
        for(int i=0;i<mx;i++){
            for(int j = 0;j<mx;j++){
                if(j) cout<<esp;
                cout<<ans[i][j];
            }
            cout<<el;
        }
       
    }

}

/*

125 | uDebug

125.pdf (onlinejudge.org)

Online Judge
*/