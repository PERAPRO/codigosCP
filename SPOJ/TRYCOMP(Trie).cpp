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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
string yes="YES";
string no="NO";

const int N=5e6+10;
int nxt[N][26], mayor[N];
//bitset<N> finish;
int node=1;

void add(string &s, int idx){
    int cur=0;
    for(auto c:s){
        int v=c-'a';   //Nodo;
        if(nxt[cur][v]==0){ //No existe el nodo
            nxt[cur][v]=node;
            mayor[node]=idx;
            node++;
        }
        cur=nxt[cur][v];
    }
    //finish[cur]=1;
    return;
}

int find(string &s){
    int cur=0;
    for(auto c:s){
        int v=c-'a';   //Nodo;
        if(nxt[cur][v]==0){ //No existe el nodo
            return -1;
        }
        cur=nxt[cur][v];
    }
    return mayor[cur];
}

bool cmp(pair<int,string> a,pair<int,string> b){
    if(a.ff==b.ff)
        return a.ss<b.ss;
    return a.ff>b.ff;
}

int main(){
    fast_io;
    int n;
    cin>>n;
    map<string,int> m;
    string k;
    for(int i=0;i<n;i++){
        cin>>k;
        m[k]++;
    }
    vector<pair<int,string>> p;
    for(auto [key,value]:m){
        p.pb({value,key});
    }

    sort(p.begin(),p.end(),cmp);
    //for(auto l:p) cout<<l.ff<<" "<<l.ss<<el;
    for(int i=0;i<p.size();i++){
        add(p[i].ss,i);
    }

    int q;
    cin>>q;
    //assert(q>0);
    for(int Q=0;Q<q;Q++){
        cin>>k;
        int result=find(k);
        //assert(result>=p.size());
        if(result==-1){
            cout<<-1<<el;
        }else{
            cout<<p[result].ss<<" "<<p[result].ff<<el;
        }
    }
    return 0;
}