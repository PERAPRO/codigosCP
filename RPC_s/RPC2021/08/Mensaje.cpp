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

const int N=1e5+5;

vi parent(N,-1);

int find(int a){
    while(parent[a] > 0)
        a=parent[a];
    return a;
}

void Union(int a, int b){
    if(-parent[b] > -parent[a]) swap(a,b);
    parent[a]+=parent[b];
    parent[b]=a;
}


struct edge{
    int u,v,t;
    edge(){}
    edge(int u, int v, int t): u(u), v(v), t(t){}
};

bool cmp(edge a, edge b){
    return a.t < b.t;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b,t;
    cin>>n>>m;
    vector<edge> v(m);
    for(int i=0;i<m;i++){
        cin>>a>>b>>t;
        v[i]={a,b,t};
        
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int ans=0;
    
    for(edge e:v){
        int a=find(e.u);
        int b=find(e.v);
        if(a == b)
            continue;
        else{
            ans+=e.t;
            Union(a,b);
        }
    }
    cout<<ans<<el;
}

/*

*/