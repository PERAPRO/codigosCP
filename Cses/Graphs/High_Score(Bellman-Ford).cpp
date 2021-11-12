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

ostream& operator<<(ostream& os, const vector<ll> &v){
    for(auto const &i: v){
        os<<i + 1<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int N=2505;
const ll oo=1e17;

struct edge{
    ll a,b,w;
    edge(){}
    edge(ll a,ll b, ll w): a(a), b(b), w(w){}
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b,w;
    cin>>n>>m;
    vector<edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
        edges[i].a--, edges[i].b--;
    }
    
    //vi parent(n,-1);
    vl distances(n,-oo);
    distances[0]=0;
    
    for(int i=0;i<n-1;i++){
        for(edge e:edges){
            if(distances[e.a] == -oo) continue;
            if(distances[e.a] + e.w > distances[e.b]){
                distances[e.b]= min(oo,distances[e.a] + e.w);
                //parent[e.b]=e.a;
            }
        }
    }
    
    //cout<<16<<endl;
    int bef=distances[n-1];
    int node=-1;
    
    //cout<<distances;
    
    for(int i=0;i<n-1;i++){
        for(edge e:edges){
            if(distances[e.a] == -oo) continue;
            if(distances[e.a] + e.w > distances[e.b]){
                distances[e.b]= min(oo,distances[e.a] + e.w);
                node=0;
                //parent[e.b]=e.a;
            }
        }
    }
    //cout<<distances;
    
    if(bef != distances[n-1] || !node){
        cout<<-1<<el;
        return 0;
    }
    cout<<distances[n-1]<<el;
}

/*

*/