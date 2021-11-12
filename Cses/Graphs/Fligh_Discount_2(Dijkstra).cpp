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
using pii=pair<ll,ll>;
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
const ll oo=1e15+7;
const int N=1e5+5;
const int M=2e5+5;

vector<pii> g[N];
ll distances [N][2];
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        a--, b--;
        g[a].pb({b,w});
    }
    for(int i=0;i<N;i++) for(int j=0;j<2;j++) distances[i][j] = oo;
    priority_queue<pair<pii,int>, vector<pair<pii,int>>, greater<pair<pii,int>>> q;
    
    distances[0][0] = distances[0][1] = 0;
    q.push({{0,0},1});  // 1 Means can use the discount
    
    while(q.size()){
        int u=q.top().ff.ss;
        ll d =q.top().ff.ff;
        int ds=q.top().ss;
        q.pop();
        if(d != distances[u][ds]) continue;
        for(pii v:g[u]){
            int child = v.ff;
            ll w=v.ss;
            if(d + w < distances[child][ds]){
                distances[child][ds] = d + w;
                q.push({{d + w, child}, ds});
            }
            if(ds){
                if(d + w/2 < distances[child][0]){
                    distances[child][0] = d + w/2;
                    q.push({{d + w/2, child}, 0});
                }
            }
        }
    }
    cout<<distances[n - 1][0]<<el;
}

/*

*/