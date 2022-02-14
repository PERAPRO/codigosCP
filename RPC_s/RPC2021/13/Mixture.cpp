/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
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

int fexp(int a, int b){
    int ans = 1;
    for(;b;a=a*a,b>>=1){
        if(b&1)
            ans = ans * a;
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    while(tc--){
        int n,m,a,b;
        cin>>n>>m;
        vector<vi> g(n);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            g[a].pb(b), g[b].pb(a);
        }
        
        vi visited(n);
        int cc = 0;
        
        auto bfs = [&] (int i){
            visited[i] = 1;
            queue<int> q;
            q.push(i);
            while(q.size()){
                int u = q.front();
                q.pop();
                for(int v:g[u]){
                    if(!visited[v]){
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
        };
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i);
                cc++;
            }
        }
        if(cc == 1)
            cout<<"Pure Compound!"<<el;
        else
            cout<<"Mixture: "<<cc<<el;
    }
}

/*

*/