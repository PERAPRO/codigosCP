/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>
 
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
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
 
const int N = 1e+5+5;
int n,m;
 
vi out(N), in(N);
vector<vi> g(N);
 
vi findEulerianPath(int u){
    
    vector<int> stack, curr_edge(N), res;
    stack.push_back(u);
    while (!stack.empty())
    {
        u = stack.back();
        stack.pop_back();
        while (curr_edge[u] < (int)g[u].size())
        {
            stack.push_back(u);
            u = g[u][curr_edge[u]++];
        }
        res.push_back(u);
    }
    reverse(res.begin(), res.end());
    return res;
    
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        g[a].pb(b);
        out[a]++;
        in[b]++;
    }    
    bool f = out[0] - in[0] == 1 && in[n - 1] - out[n - 1] == 1;
    //cout<<out[0]<<esp<<in[0]<<el<<in[n - 1]<<esp<<out[n - 1]  <<endl;
    for (int i = 1; i < n - 1; ++i)
        if (in[i] != out[i]) { f = 0; break; }
    
    if(!f)
        cout<<"IMPOSSIBLE"<<el;
    else{
        vi EP = findEulerianPath(0);
        if(EP.size() != m + 1){
            cout<<"IMPOSSIBLE"<<el;
            return 0;
        }
        for(int x:EP)
            cout<<x + 1<<esp;
        cout<<el;
    }
}