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

const int N = 2e5+5;

vector<vi> g(N);

vl val(N);
vl cs(N);
vl ans(N);

ll dfs(int u, int p){
    ll ans = 1;

    for(int v:g[u]){
        if(v == p) continue;
        ans += dfs(v, u);
    }

    return cs[u] = ans;
}

ll dfs1(int u, int p){
    ll ans = 0;

    for(int v:g[u]){
        if(v == p) continue;

        ans += dfs1(v, u) + cs[v] + 1;
    }

    return val[u] = ans;
}


void dfs2(int u, int p){
    ans[u] = val[u];

    for(int v:g[u]){
        if(v == p) continue;

        cs[u] -= cs[v] + 1;
        val[u] -= val[v] + cs[v] + 1;

        cs[v] += cs[u] + 1;
        val[v] += val[u] + cs[u] + 1;

        dfs2(v, u);

        val[v] -= val[u] + cs[u] + 1;
        cs[v] -= cs[u] + 1;
        
        val[u] += val[v] + cs[v] + 1;
        cs[u] += cs[v] + 1;

    }
}

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;

        g[a].pb(b), g[b].pb(a);
    }

    dfs(0, 0);
    for(ll &e:cs) e--;
    dfs1(0, 0);
    // for(int i=0;i<n;i++) cout<<val[i]<<el; cout<<el;
    dfs2(0, 0);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<esp;
    }
}

/*
8
1 2
1 3
2 4
3 5
3 6
4 7
4 8

10
7 5
5 3
7 4
1 9
9 2
10 1
8 1
8 6
4 8

*/