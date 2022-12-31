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
 
const int N = 2e5+5;
 
vector<vi> g(N);
vector <ll> v(N);
vi in(N);
vi sub(N);
 
struct bit{
    int size;
    vector<ll> values;
    void init(int n){
        values.resize(n);
        size=n;
    }
    ll sum(int i){
        ll sum=0;
        while(i>0){
            sum+=values[i];
            i-=i&(-i);
        }
        return sum;
    }
    void update(int i, ll v){
        while(i<size){
            values[i]+=v;
            i+=i&(-i);
        }
    }
};
 
int timer = 1;
 
int dfs(int u, int p){
    
    sub[u] = 1;
    
    in[u] = timer++;
    
    for(int v:g[u]){
        if(v == p) continue;
        sub[u] += dfs(v,u);
    }
    
    return sub[u];
}
 
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        // a--,b--;
        g[a].pb(b), g[b].pb(a);
    }
    
    dfs(1, 0);
    
    bit fenwick;
    fenwick.init(N);
    
    for(int i=1;i<=n;i++){
        fenwick.update(in[i], v[i]);
        // fenwick.update(in[i] + 1, -v[i]);
    }
    
    // cout<<16<<endl;
    
    // for(int i=1;i<=n + 1;i++){
    //     cout<<fenwick.sum(in[i])<<el;
    // }
    
    for(int q = 0;q<m;q++){
        // cout<<"fenwick "<<el;
        // for(int i=1;i<=n + 1;i++){
        //     cout<<fenwick.sum(in[i])<<esp;
        // }
        // cout<<el;
        int type; cin>>type;
        if(type == 1){
            int s,x; cin>>s>>x;
            fenwick.update(in[s], x - v[s]);
            // fenwick.update(in[s] + 1, -(x - v[s]));
            v[s] = x;
        }else{
            int s; cin>>s;
            ll ans = fenwick.sum(in[s] + sub[s] - 1) + (s == 1 ? 0 : -fenwick.sum(in[s] - 1));
            cout<<ans<<el;
        }
    }
    
}
 
/*
 
*/