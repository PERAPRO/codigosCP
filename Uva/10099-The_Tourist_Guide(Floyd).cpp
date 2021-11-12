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

const ll oo=1e15;

ll cd(ll a, ll b){
    return (a + b - 1) / b;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc=1;
    int n,m;
    while(cin>>n>>m){
        if(tc > 1) cout<<el;
        if(!n && !m) break;
        
        cout<<"Scenario #"<<tc<<el<<"Minimum Number of Trips = ";
        
        vector<vi> v(n);
        
        vector<vl> distances(n,vl(n,-oo));
        
        for(int i=0;i<m;i++){
            ll a,b,w;
            cin>>a>>b>>w;
            a--, b--, w--;
            distances[a][b] = distances[b][a] = max(distances[a][b], w);
            //g[a].pb({b,w}), g[b].pb({a,w});
            
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ll cur = distances[i][j];
                    ll candidate = min(distances[i][k], distances[k][j]);
                    distances[i][j] = max(cur, candidate);
                }
            }
        }
        
        int from, to, pass;
        cin>>from>>to>>pass;
        //cout<<distances[from - 1][to - 1]<<el;
        ll ans = cd(pass,distances[from - 1][to - 1]);
        cout<<ans<<el;
        
        tc++;
    }
}

/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
3 6 20
4 7 35
5 7 20
6 7 30
1 7 99
0 0

*/