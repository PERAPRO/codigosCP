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
 
const int N = 1e5+5;
struct edge;
typedef list<edge>::iterator iter;
vi deg(N);
int n,m;

struct edge{
    int nextV;
    iter reverseEdge;
    edge(int nextV) : nextV(nextV){}
};

list<edge> g[N];
vi path;

void addEdge(int a, int b){
    g[a].push_front(edge(b));
    iter ita = g[a].begin();
    g[b].push_front(edge(a));
    iter itb = g[b].begin();
    ita->reverseEdge = itb;
    itb->reverseEdge = ita;
    deg[a]++, deg[b]++;
}

void solve(int u){
    while(g[u].size() > 0){
        int v = g[u].front().nextV;
        g[v].erase(g[u].front().reverseEdge);
        g[u].pop_front();
        solve(v);
    }
    path.pb(u);
}
 
bool findEulerianPath(int init) {
    for(int i=0;i<n;i++){
        if(deg[i] & 1) return 0;
    }
    solve(init);
    return path.size() == m + 1;
}
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        addEdge(a,b);
    }
    
    if(!findEulerianPath(0)){
        cout<<"IMPOSSIBLE"<<el;
    }else{
        for(int e:path){
            cout<<e + 1<<esp;
        }
        cout<<el;
    }
    
}
 
/*
 
*/