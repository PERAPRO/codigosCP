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

int mx[1005][1005];
bool visited[1005][1005];

vi dr = {-1,-1,-1, 0,0, 1,1,1,0};
vi dc = {-1, 0, 1,-1,1,-1,0,1,0};

int n,m;

bool isValid(int i, int j){
    return i>-1 && j>-1 && i<n && j<m && !visited[i][j]  && mx[i][j];
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int p,a,b;
    cin>>n>>m>>p;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mx[i][j];
        }
    }
    
    int ans=0;
    
    for(int q=0;q<p;q++){
        cin>>a>>b;
        a--,b--;
        for(int i=0;i<9;i++){
            if(isValid(a + dr[i], b + dc[i])){
                visited[a + dr[i]][b + dc[i]]=1;
                ans++;
            }
        }
    }
    cout<<ans<<el;
}

/*

*/