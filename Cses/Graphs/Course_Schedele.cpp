/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
using pii=pair<long long ,long long>;
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
string no="IMPOSSIBLE";

ll oo=1e17+7;
const int N=1e5+5;

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b;
    cin>>n>>m;
    vector<vi> g(n+1);
    vi ingree(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].pb(b);
        ingree[b]++;
    }
    vi sol;
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(!ingree[i]) q.push(i), sol.pb(i);
    }
    while(q.size()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            ingree[v]--;
            if(!ingree[v]) q.push(v), sol.pb(v);
        }
    }
    //cout<<sol<<el;
    if(sol.size()==n){
        cout<<sol;
    }else{
        cout<<no<<el;
    }
}

/*

*/