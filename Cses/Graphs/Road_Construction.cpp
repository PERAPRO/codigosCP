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

vi parent;

int find(int u){
    if(parent[u] < 0) return u;
    return parent[u]=find(parent[u]);
}

int cc, mx=-1000000;
void Union(int a, int b){
    a=find(a), b=find(b);
    if(a == b) return;
    if(-parent[b] > -parent[a]) swap(a,b);
    parent[a]+=parent[b];
    parent[b]=a;
    mx=max(mx,-parent[a]);
    cc--;
}

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b,w;
    cin>>n>>m;
    cc=n;
    parent.assign(n+1,-1);
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        Union(a,b);
        cout<<cc<<esp<<mx<<el;
    }
    
}

/*

*/