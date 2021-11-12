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

const int oo=1e8;

struct edge{
    int a,b,w,t;
    edge(){}
    edge(int a, int b, int w, int t): a(a), b(b), w(w), t(t){}
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc=1;
    int n,m,q;
    while(cin>>n>>m>>q){
        //cout<<16<<endl;
        if(tc > 1) cout<<'.'<<el;
        map<string,int> mp;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            mp[s]=i;
        }
        vector<edge> g;
        for(int i=0;i<m;i++){
            string a,b;
            cin>>a>>b;
            int w,t;
            cin>>w>>t;
            g.pb({mp[a], mp[b], w, t});
        }
        
        cin>>s;
        int source = mp[s];
        
        // cost, time, stops;
        int nn=n + 3;
        vector<vi> distances(nn, vi(nn, oo));
        vector<vi> times(nn,vi(nn, oo));
        
        for(int i=0;i<nn;i++){
            distances[source][i] = 0;
            times[source][i]=0;
        }
        
        for(int i=0;i<nn - 1;i++){
            for(edge e:g){
                int from=e.a, to=e.b, w=e.w, t=e.t;
                if(distances[from][i] + w < distances[to][i + 1]){
                    distances[to][i + 1] = distances[from][i] + w;
                    times[to][i + 1] = times[from][i] + t;
                }
                if(distances[from][i] + w == distances[to][i + 1] && times[to][i + 1] > times[from][i] + t){
                    times[to][i + 1] = times[from][i] + t;
                }
            }
        }
        
        //int querys;
        //cin>>querys;
        while(q--){
            cin>>s;
            int to=mp[s];
            int stops;
            cin>>stops;
            
            if(distances[to][stops + 1] == oo){
                cout<<"* *"<<el;
            }else{
                cout<<distances[to][stops + 1]<<esp<<times[to][stops + 1]<<el;
            }
        }
        
        tc++;
    }
}

/*

*/