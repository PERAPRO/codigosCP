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
string no="No solution.";

const int N = 26000;
const int oo = 1e9+7;

int main(){
    fast_io;
    /*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string s;
    bool read=1;
    while(getline(cin,s)){
        //cout<<s<<el;
        vector<vi> g(26000);
        
        int nodes=0;
        
        if(s == ""){
            read =0;
            //for(auto vv:g) cout<<vv;
            continue;
        }
        
        map<string,int> m;
        map<int,string> m2;
        
        if(read){
            
            for(int i=0;i<s.size();i++){
                string cur=s;
                for(char c='a';c<='z';c++){
                    cur[i]=c;
                    if(m.count(cur)){
                        g[m[cur]].pb(nodes), g[nodes].pb(m[cur]);
                    }
                }
            }
            
            m2[nodes]=s;
            m[s]=nodes++;
            
        }else{
            stringstream ss(s);
            string a,b;
            ss>>a>>b;
            vi distances(N, oo);
            vi parent(N,0);
            auto bfs = [&] (int b){
                queue<int> q;
                q.push(b);
                distances[b]=0;
                parent[b]=-1;
                while(q.size()){
                    int u=q.front(); q.pop();
                    for(int v:g[u]){
                        if(distances[u] + 1 < distances[v]){
                            distances[v]=distances[u] + 1;
                            parent[v] = u;
                        }
                    }
                }
            };
            
            bfs(m[a]);
            
            if(distances[m[b]] == oo){
                cout<<no<<el<<el;
            }else{
                
                vector<string> ans;
                int cur=m[b];
                while(cur != m[a]){
                    ans.pb(m2[cur]);
                    cur=parent[cur];
                }
                ans.pb(m2[cur]);
                
                reverse(ans.begin(), ans.end());
                
                for(string &as:ans){
                    cout<<as<<el;
                }
                cout<<el;
            }
            
        }
    }
}

/*

*/