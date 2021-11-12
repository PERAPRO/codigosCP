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

const int N=2e6+5;
const int alpha = 130;
const int oo=1e9+7;

int final[N];
int nxt[N][alpha];
int fail[N];
int dict[N];

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
    ckmin(final[cur], idx);
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
            bool f=final[fail[v]] != oo;
            dict[v]= f ? fail[v] : dict[fail[v]];
        }
    }
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int q,type;
    cin>>q;
    string s;
    for(int i=0;i<N;i++) final[i] = oo;
    
    vector<pair<int,string>> v;
    
    for(int i=0;i<q;i++){
        cin>>type>>s;
        if(!type) add(s,i);
        else v.pb({i,s});
    }
    
    build();
    
    for(auto query:v){
        int f=0;
        int cur=0;
	    for(int c:query.ss){
	        cur=nxt[cur][c];
	        int temp=cur;
	        while(temp){
	            if(final[temp] != oo){
	                if(final[temp] < query.ff)
	                    f=1;
	            }
	            temp=dict[temp];
	        }
	    }
	    if(f)
	        cout<<yes<<el;
	    else 
	        cout<<no<<el;
    }
    
}

/*

*/