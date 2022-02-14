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
    os<<endl;
    return os;
}
string yes="y";
string no="n";

const int N=1e3+5;
const int N2=1e6+5;
const int alpha = 130;

vector<int> final[N2];
int nxt[N2][alpha];
int fail[N2];
int dict[N2];
bitset<N> ans;
int nodes=1;

void add(string &s,int idx){
    int cur=0;
    for(int c:s){
        int u=nxt[cur][c];
        if(!u){
            nxt[cur][c]=nodes++;
        }
        cur=nxt[cur][c];
    }
    final[cur].pb(idx);
}

void build(){
    queue<int> q;
    q.push(0);
    while(q.size()){
        int u=q.front(); q.pop();
        for(int i=0;i<alpha;i++){
            int v=nxt[u][i];
            if(v==0) nxt[u][i]=nxt[fail[u]][i]; //No tendo hijo con la letra i, construir automata
            else q.push(v);
            if(u==0 || v==0) continue;     //No les tengo que calcular nada mas
            fail[v]=nxt[fail[u]][i];
            //En mi fail termina una palabra? la marco si no tomo el dict de mi fail
            bool f=final[fail[v]].size();
            dict[v]= f ? fail[v] : dict[fail[v]];
        }
    }
}


int main(){
	fast_io;
	int tc;
	cin>>tc;
	while(tc--){
	    for(auto v:final) v.clear();
	    memset(nxt,0,sizeof nxt); memset(fail,0,sizeof fail); memset(dict,0,sizeof dict);
	    ans.reset();
	    string s;
	    cin>>s;
	    int querys;
	    cin>>querys;
	    for(int Q=0;Q<querys;Q++){
	        string q;
	        cin>>q;
	        add(q,Q);
	    }
	    build();
	    int cur=0;
	    for(int c:s){
	        cur=nxt[cur][c];
	        int temp=cur;
	        while(temp){
	            if(final[temp].size()){
	                for(int i=0;i<final[temp].size();i++){
	                    ans[final[temp][i]]=1;
	                }
	            }
	            temp=dict[temp];
	        }
	    }
	    for(int i=0;i<querys;i++){
	        if(ans[i]) cout<<yes<<el;
	        else cout<<no<<el;
	    }
	}
}