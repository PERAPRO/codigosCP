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
string yes="YES";
string no="NO";

int n,m;

int tru(char c, int top){
    top--;
    if(c == '+')
        return top;
    return top + m;
}

int fals(char c, int top){
    top--;
    if(c == '+')
        return top + m;
    return top;
}

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int topping, topping1;
    cin>>n>>m;
    //n : numero de clausulas, m numero de variables o nodos de mi grafo :D
    //2 SAT - Nodo i, i + n, negativo
    //(a v b)  = (~a -> b) ^ (~b -> a)

    vector<vi> g(m + m);
    vector<vi> gt(m + m);

    char take, take1;

    for(int i=0;i<n;i++){
        cin>>take>>topping>>take1>>topping1;

        g[fals(take, topping)].pb(tru(take1, topping1));
        g[fals(take1, topping1)].pb(tru(take, topping));

        gt[tru(take1, topping1)].pb(fals(take, topping));
        gt[tru(take, topping)].pb(fals(take1, topping1));
    }

    vi visited(m + m);

    stack<int> order;

    function<void (int)> dfs1 = [&] (int u){
        visited[u] = 1;
        for(int v:g[u]){
            if(!visited[v])
                dfs1(v);
        }

        order.push(u);
    };

    for(int i=0;i<2 * m;i++){
        if(!visited[i])
            dfs1(i);
    }

    vi comp(m + m, -1);

    function<void(int, int)> dfs2 = [&] (int u, int cl){
        comp[u] = cl;
        for(int v:gt[u]){
            if(comp[v] == -1)
                dfs2(v,cl);
        }
    };


    for(int i=0, j = 0;i<2 * m;i++){
        int u = order.top();
        order.pop();
        if(comp[u] == -1){
            dfs2(u, j++);
        }
    }

    bool flag=1;

    vi asignacion(m,0);

    for(int i=0;i<m;i++){
        if(comp[i] == comp[i + m])
            flag = 0;
        asignacion[i] = comp[i] > comp[i + m];
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<el;
        return 0;
    }
    for(int i:asignacion) cout<<(i ? '+' : '-')<<esp;
}

/*

*/