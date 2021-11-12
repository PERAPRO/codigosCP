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
    ll n,m,q,a,b,w;
    cin>>n>>m>>q;
    vector<vector<ll>> distances(n+1,vector<ll>(n+1,oo));
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        distances[a][b]=distances[b][a]=w;
    }
    for(int i=1;i<=n;i++) distances[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);
    for(int Q=0;Q<q;Q++){
        cin>>a>>b;
        cout<<(distances[a][b] == oo ? -1 : distances[a][b])<<el;
    }
}

/*

*/