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
const int N=1e3+5;
vi dr={1,-1,0,0};
vi dc={0,0,1,-1};
bitset<N> visited[N];
int n,m;
vector<string> grid;
bool isvalid(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]=='#') return 0;
    else return 1;
}

void dfs(int i, int j){
    visited[i][j]=1;
    //cout<<i<<" "<<j<<el;
    for(int k=0;k<4;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(isvalid(nr,nc))
            dfs(nr,nc);
    }
}

int main(){
	fast_io;
	//int n,m;
	cin>>n>>m;
	//vector<string> grid(n);
	grid.resize(n);
	for(auto &s:grid) cin>>s;
	//for (auto s:grid) cout<<s<<el;
	int rooms=0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(grid[i][j]!='#' && !visited[i][j]){
	            dfs(i,j);
	            rooms++;
	        }
	    }
	}
	cout<<rooms<<el;
}