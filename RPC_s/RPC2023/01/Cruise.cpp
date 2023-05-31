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

const ll oo = 1e15;


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m;
    cin>>n>>m;
    
    vi vertices(n);
    
    for(int i=0;i<n;i++){
        cin>>vertices[i];
    }
    
    vector<vector<pii>> g(n);
    
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        // a--,b--;
        g[a].pb(mp(b,c)), g[b].pb(mp(a,c));
    }
    
    int l = n / 2, r = n;
    ll ans = oo;
    // cout<<yes<<endl;
    while(l && r - l){
        // cout<<l<<esp<<r<<endl;
        vl distances(r, oo);
        
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(int i = 0;i<l;i++){
            distances[i] = vertices[i];
            q.push(mp(vertices[i], i));
        }
        
        while(q.size()){
            ll ds = q.top().ff;
            int u = q.top().ss;
            q.pop();
            // cout<<"ds "<<ds<<esp<<"u :"<<u<<endl;
            if(ds != distances[u]) continue; 
            for(auto uu:g[u]){
                ll new_d = ds + uu.ss;
                if(distances[uu.ff] > new_d){
                    distances[uu.ff] = new_d;
                    q.push(mp(new_d, uu.ff));
                }
            }
        }
        
        for(int i = l;i<r;i++){
            ckmin(ans, distances[i] + vertices[i]);
        }
        
        r = l, l = l / 2;
    }
    cout<<ans<<el;
}

/*

*/