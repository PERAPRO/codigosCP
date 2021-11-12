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
const int N=1e3+5;
vi dr={1,-1,0,0};
vi dc={0,0,1,-1};
bitset<N> visited[N];
int n,m;
vector<string> grid;
pii start;
pii final;
vector<vector<pii>> padres(N,vector<pii>(N,{0,0}));
bool isvalid(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]=='#') return 0;
    else return 1;
}

char dir(pii child, pii parent){
    //voy para arriba
    char ans;
    if(parent.ff==child.ff-1) return ans='D';
    if(parent.ff==child.ff+1) return ans='U';
    if(parent.ss==child.ss+1) return ans='L';
    if(parent.ss==child.ss-1) return ans='R';
    return ans;
}

void dfs(int i, int j, pii parent){
    visited[i][j]=1;
    padres[i][j]=parent;
    //cout<<i<<" "<<j<<endl;
    if(make_pair(i,j)==final) return;
    for(int k=0;k<4;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        //if(nuevas==final) return;
        if(isvalid(nr,nc))
            dfs(nr,nc,{i,j});
    }
}

int main(){
	fast_io;
	//int n,m;
	cin>>n>>m;
	//vector<string> grid(n);
	grid.resize(n);
	for(auto &s:grid) cin>>s;
	//for (auto s:grid) cout<<s<<endl;
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(grid[i][j]=='A')
	            start={i,j};
	        if(grid[i][j]=='B')
	            final={i,j};
	    }
	}
	//cout<<start.ff<<" "<<start.ss<<endl;
	//dfs(start.ff,start.ss,{-1,-1});
	queue<int> rq;
	queue<int> cq;
	rq.push(start.ff);
	cq.push(start.ss);
	int r,c,nr,nc;
	visited[start.ff][start.ss]=1;
	while(rq.size()){
	    r=rq.front();
	    c=cq.front();
	    rq.pop(); cq.pop();
	    //cout<<r<<" "<<c<<el;
	    if(make_pair(r,c)==final) break;
	    for(int i=0;i<4;i++){
	        nr=r+dr[i];
	        nc=c+dc[i];
	        if(isvalid(nr,nc)){
	            visited[nr][nc]=1;
	            rq.push(nr);
	            cq.push(nc);
	            padres[nr][nc]={r,c};
	        }
	    }
	}
	//cout<<-2<<endl;
	if(visited[final.ff][final.ss]){
	    cout<<yes<<el;
	    string ans;
	    pii cur=final;
	    while(cur!= start){
	        ans+=dir(cur,padres[cur.ff][cur.ss]);
	        cur=padres[cur.ff][cur.ss];
	    }
	    reverse(ans.begin(),ans.end());
	    cout<<ans.size()<<el;
	    cout<<ans<<el;
	}else{
	    cout<<no<<el;
	}
}