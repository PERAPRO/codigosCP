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
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int alpha=75;
const int N=4e6+10;

int nxt[N][alpha],cur_p[N],finished[N];
int node=1;
ll ans=0;

void add(string &s){
    int cur=0;
    for(char c:s){
        int u=c-'0';
        if(nxt[cur][u]==0){
            nxt[cur][u]=node++;
        }
        cur=nxt[cur][u];
        ans+=cur_p[cur]*2;
        cur_p[cur]++;
    }
    if(finished[cur]) ans+=finished[cur];
    finished[cur]++;
    
}

ll triangular(ll n){
    return (n*(n+1))/2;
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    int cnt=1;
    while(1){
        cin>>n;
        if(!n) break;
        cout<<"Case "<<cnt<<": ";
        
        //for(auto &v:nxt) fill(v,v+alpha,0); fill(cur_p,cur_p+N,0); fill(finished,finished+N,0);
        memset(nxt,0,sizeof nxt); memset(cur_p,0,sizeof cur_p); memset(finished,0,sizeof finished);
        node=1;
        ans=0;
        
        string s;
        //int total_size=0;
        for(int i=0;i<n;i++){
            cin>>s;
            add(s);
            //total_size+=s.size();
        }
        ans+=triangular(n-1);
        cout<<ans<<el;
        cnt++;
    }
}