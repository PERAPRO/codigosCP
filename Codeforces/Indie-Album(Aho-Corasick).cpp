/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
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

const int N=4e5+5;
const int alpha=130;

vector<pair<int,char>> g[N];
vector<int> m[N];

int final[N];
int nxt[N][alpha];
int fail[N];
int dict[N];
int idxs[N]; 
int ans[N];

int nodes=1;

int add(string &s){
    int cur=0;
    for(int c:s){
        //c=c-'a';
        int u=nxt[cur][c];
        if(!u){
            nxt[cur][c]=nodes++;
        }
        cur=nxt[cur][c];
    }
    
    final[cur] = 0;
    return cur;
}

void build(){
    queue<int> q;
    q.push(0);
    while(q.size()){
        int u=q.front(); q.pop();
        for(int i=0;i<alpha;i++){
            int v=nxt[u][i];
            if(v==0) nxt[u][i]=nxt[fail[u]][i]; //No tendo hijo con la letra i, construir automata
            else q.push(v);
            if(u==0 || v==0) continue;     //No les tengo que calcular nada mas
            fail[v]=nxt[fail[u]][i];
            //En mi fail termina una palabra? la marco si no tomo el dict de mi fail
            bool f=final[fail[v]] != -1;
            dict[v]= f ? fail[v] : dict[fail[v]];
        }
    }
}

void solve(int cur, int val){
    while(cur){
        if(final[cur] != -1){
            final[cur] += val;
        }
        cur=dict[cur];
    }
}


void dfs(int ch, int u, int word){
    int cur=nxt[u][ch];
    solve(cur, 1);
    for(int q:m[word]){
        ans[q] = final[idxs[q]];
    }
    for(auto v:g[word]){
        dfs(v.ss, cur, v.ff);
    }
    solve(cur, -1);
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    
    vector<pii> singles;
    
    for(int i=1;i<=n;i++){
        int type, prev;
        char c;
        cin>>type;
        if(type == 1){
            cin>>c;
            singles.pb({i,c});
        }else{
            cin>>prev>>c;
            g[prev].pb({i,c});
        }
    }
    
    int querys;
    cin>>querys;
    
    memset(final, -1, sizeof final);
    
    for(int i=0;i<querys;i++){
        int word;
        string q;
        cin>>word>>q;
        m[word].pb(i);
        idxs[i] = add(q);
    }
    
    build();
    
    for(int i=0;i<singles.size();i++){
        dfs(singles[i].ss, 0, singles[i].ff);
    }
    
    for(int i=0;i<querys;i++){
        cout<<ans[i]<<el;
    }
    
}

/*

*/