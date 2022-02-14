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

int n,m;

const int N =1e5+5; 
const int sz = 700;

vector<vi> g(N);
vector<int> S(N), E(N), FT(2 * N), color(N), nodeF(N), colF(N), FF(N), bucket(N), ans(N);
int timer;

void dfs(int node, int p){
    S[node] = timer;
    FT[timer] = node;
    timer++;
    
    for(int v:g[node])
        if(v != p)
            dfs(v, node);
            
    E[node] = timer;
    FT[timer] = node;
    timer++;
}

struct query{
    int l, r, k, idx;
    query(){}
    query(int l, int r, int k, int idx): l(l), r(r), k(k), idx(idx){}
};

vector<query> querys;

bool cmp(query &a, query &b){
    if(a.l / sz != b.l / sz) return a.l / sz < b.l / sz;
    return ((a.l / sz) & 1 ? a.r > b.r : a.r < b.r);
}

void add(int idx){
    int node = FT[idx];
    int col = color[node];
    nodeF[node]++;
    
    if(nodeF[node] == 2){
        colF[col]++;
        FF[colF[col]]++;
        bucket[colF[col] / sz]++;
        
        FF[colF[col] - 1]--;
        bucket[(colF[col] - 1) / sz]--;
    }
}

void rm(int idx){
    int node = FT[idx];
    int col = color[node];
    nodeF[node]--;
    
    if(nodeF[node] == 1){
        colF[col]--;
        FF[colF[col]]++;
        bucket[colF[col] / sz]++;
        
        FF[colF[col] + 1]--;
        bucket[(colF[col] + 1) / sz]--;
    }
}

//Use sqrt descomposition to get the answer (updates in O(1))

int get_ans(int k){
    
    int ans = 0;
    
    for(int i=k;i<=n;){
        if(i % sz == 0 && i + sz - 1 <= n){
            ans += bucket[i / sz];
            i += sz;
        }else{
            ans += FF[i];
            i++;
        }
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int a,b,k;
    cin>>n>>m;
    //Flat tree + Mo's
    for(int i=1;i<=n;i++){
        cin>>color[i];
    }
    
    for(int i=1;i<n;i++){
        cin>>a>>b;
        g[a].pb(b), g[b].pb(a);
    }
    
    int timer = 0;
    dfs(1,-1);
    
    for(int j=0;j<m;j++){
        cin>>a>>k;
        querys.pb(query(S[a], E[a], k, j));
    }
    
    sort(all(querys), cmp);
    
    int l = 0, r = -1;
    
    

    for(int i=0;i<m;i++){
        query cur = querys[i];

        while(r < cur.r) add( ++r );
        while(l > cur.l) add( --l );
        while(l < cur.l) rm( l++ );
        while(r > cur.r) rm( r-- );

        ans[cur.idx] = get_ans(cur.k);
    }
    
    for(int i=0;i<m;i++){
        cout<<ans[i]<<el;
    }
}

/*

*/