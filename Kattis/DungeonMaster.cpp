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

int oo=1e8;

int dr[]={1,-1,0, 0,0, 0};
int dc[]={0, 0,1,-1,0, 0};
int dl[]={0, 0,0, 0,1,-1};

int main(){
	fast_io;
	int layers,rows,columns;
	while(1){
	    cin>>layers>>rows>>columns;
	    if(!layers && !rows && !columns) break;
	    vector<vector<string>> grid(layers,vector<string>(rows));
	    pair<int,pii> start;
	    pair<int,pii> fin;
	    for(int i=0;i<layers;i++){
	        for(int j=0;j<rows;j++){
	            cin>>grid[i][j];
	            for(int k=0;k<columns;k++){
    	            if(grid[i][j][k]=='S'){
    	                start={i,{j,k}};
    	            }
    	            if(grid[i][j][k]=='E') 
    	                fin={i,{j,k}};
    	        }
	        }
	    }
	    //for(auto vs:grid)
	        //for(auto s:vs)
	            //cout<<s<<el;
	    vector<vector<vi>> distances(layers,vector<vi>(rows,vi(columns,oo)));
	    function<bool(int,int,int)> isvalid=[&] (int capa, int fila, int columna){
	        if(capa>-1 && capa<layers && fila>-1 && fila<rows && columna>-1 && 
	            columna <columns && grid[capa][fila][columna] != '#' && distances[capa][fila][columna] == oo) 
	           return 1;
	       else return 0;
	    };
	    int l,r,c,nl,nr,nc;
	    distances[start.ff][start.ss.ff][start.ss.ss]=0;
	    queue<pair<int,pii>> q;
	    q.push(start);
	    while(q.size()){
	        //cout<<"it queue"<<endl;
	        l=q.front().ff;
	        r=q.front().ss.ff;
	        c=q.front().ss.ss;
	        q.pop();
	        //cout<<l<<" "<<r<<" "<<c<<endl;
	        for(int i=0;i<6;i++){
	            nl=l+dl[i];
	            nr=r+dr[i];
	            nc=c+dc[i];
	            if(isvalid(nl,nr,nc)){
	                //cout<<"->"<<nl<<" "<<nr<<" "<<nc<<endl;
	                distances[nl][nr][nc]=distances[l][r][c]+1;
	                q.push({nl,{nr,nc}});
	                //cout<<"fin queue"<<endl;
	            }
	            //cout<<"fin queue"<<endl;
	        }
	        
	    }
	    //cout<<start.ff<<" "<<start.ss.ff<<" "<<start.ss.ss<<el;
	    //cout<<fin.ff<<" "<<fin.ss.ff<<" "<<fin.ss.ss<<endl;
	    if(distances[fin.ff][fin.ss.ff][fin.ss.ss]!=oo) 
	        cout<<"Escaped in "<<distances[fin.ff][fin.ss.ff][fin.ss.ss]<<" minute(s)."<<el;
	    else
	        cout<<"Trapped!"<<el;
	}
}