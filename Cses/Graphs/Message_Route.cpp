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

int oo=1e9+7;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b;
    cin>>n>>m;
    vector<vi> g(n+1);
    vi distances(n+1,oo);
    vi parent(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].pb(b), g[b].pb(a);
    }
    
    distances[1]=0;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(distances[v]>distances[u]+1){
                parent[v]=u;
                distances[v]=distances[u]+1;
                q.push(v);
            }
        }
    }
    if(distances[n] == oo){
        cout<<"IMPOSSIBLE"<<el;
        return 0;
    }
    cout<<distances[n]+1<<el;
    a=n;
    vi ans;
    while(a != 1){
        ans.pb(a);
        a=parent[a];
    }
    ans.pb(1);
    for(int i=ans.size()-1;i>-1;i--){
        cout<<ans[i];
        if(i>0) cout<<esp;
    }
    cout<<el;
}

/*

*/