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
string no="NO";

ll oo=1e17+7;
const int N=1e5+5;

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    ll n,m,a,b,w;
    cin>>n>>m;
    vector<vector<pii>> g;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].pb({b,w});
    }
    //q{distance,node};
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<ll> distances(n+1,oo);
    
    q.push({0,1});
    distances[1]=0;
    while(q.size()){
        ll dd=q.top().ff;
        ll u=q.top().ss;
        q.pop();
        if(distances[u] != dd) continue;
        //cout<<u<<esp<<dd<<endl;
        for(pii v:g[u]){
            ll nd=dd+v.ss;
            if(nd<distances[v.ff]){
                distances[v.ff]=nd;
                q.push({nd,v.ff});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<distances[i]<<" ";
    }
    cout<<el;
}

/*

*/