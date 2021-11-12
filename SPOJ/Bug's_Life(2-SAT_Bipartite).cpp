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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="No suspicious bugs found!";
string no="Suspicious bugs found!";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    for(int t = 1;t<=tc;t++){
        cout<<"Scenario #"<<t<<":"<<el;
        int bugs, interactions,a,b;
        cin>>bugs>>interactions;
        vector<vi> g(2 * bugs);
        vector<vi> gt(2 * bugs);
        for(int i=0;i<interactions;i++){
            cin>>a>>b;
            a--, b--;
            g[a + bugs].pb(b), g[b + bugs].pb(a), g[a].pb(b + bugs), g[b].pb(a + bugs);
        }
        
        vi visited(2 * bugs);
        stack<int> order;
        
        function<void(int)> dfs1 = [&] (int u){
            visited[u] = 1;
            for(int v:g[u]){
                if(!visited[v])
                    dfs1(v);
            }
            order.push(u);
        };
        
        for(int i=0;i<2 * bugs;i++){
            if(!visited[i])
                dfs1(i);
        }
        
        vi comp(2 * bugs, -1);
        
        function<void(int, int)> dfs2 = [&] (int u, int cl){
            comp[u] = cl;
            for(int v:g[u])
                if(comp[v] == -1)
                    dfs2(v,cl);
        };
        
        for(int i=0,j=0;i<2 * bugs;i++){
            int u = order.top();
            order.pop();
            if(comp[u] == -1)
                dfs2(u, j++);
        }
        
        bool flag = 1;
        
        for(int i = 0;i<bugs;i++){
            if(comp[i] == comp[i + bugs])
                flag = 0;
        }
        
        if(!flag)
            cout<<no<<el;
        else 
            cout<<yes<<el;
    }
}

/*

*/