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

struct edge{
    ll a,b,w;
    edge(){}
    edge(int ai, int bi, int wi) : a(ai), b(bi), w(wi){}
};

bool cmp(edge a, edge b){
    return a.w<b.w;
}

vi parent;

int find(int a){
    if(parent[a]<0) return a;
    return parent[a]=find(parent[a]);
}

void Union(int a, int b){
    a=find(a), b=find(b);
    if(a==b) return;
    if(-parent[b]>-parent[a]) swap(a,b);   //A es el mas grande;
    parent[a]+=parent[b];
    parent[b]=a;
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,c,ci;
    cin>>n>>m;
    const int N=n+1;
    vector<edge> g;
    for(int i=0;i<m;i++){
        cin>>c>>ci;
        g.pb({0,c,ci});
    }
    for(int i=1;i<=n;i++){
        cin>>ci;
        if(i==n-1){
            g.pb({i,i+1,ci});
            continue;
        }
        g.pb({i,(i+1)%n,ci});
    }
    sort(g.begin(),g.end(),cmp);
    //for(auto e:g) cout<<e.a<<esp<<e.b<<esp<<e.w<<el;
    ll sum=0;
    parent.assign(n+1,-1);
    for(edge e:g){
        int a=find(e.a),b=find(e.b);
        if(a==b) continue;
        sum+=e.w;
        Union(a,b);
    }
    cout<<sum<<el;
}

/*

*/