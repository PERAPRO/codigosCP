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

const int oo = 1e9;

int n,m;

vi dr = {-1,0, 0,1}; // U R L D
vi dc = {0 ,1,-1,0};
vector<char> dirs = {'U', 'R', 'L', 'D'};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cout<<"Case "<<t<<":"<<el;
        int n,m,querys;
        cin>>m>>n;
        
        vector<string> mx(n);
        
        auto isValid = [&] (int i, int j){
            return i >= 0 && i < n && j >= 0 && j < m && mx[i][j] != '#';
        };
        
        
        for(int i=0;i<n;i++){
            cin>>mx[i];
        }
        
        vector<vi> visited(n, vi(m,0));
        
        int cc=1;
        
        auto bfs = [&] (int i, int j){
            queue<int> qr, qc;
            visited[i][j] = cc;
            qr.push(i);
            qc.push(j);
            while(qr.size()){
                int r = qr.front();
                int c = qc.front();
                qr.pop(); qc.pop();
                for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(isValid(nr, nc) && !visited[nr][nc]){
                        visited[nr][nc] = cc;
                        qr.push(nr);
                        qc.push(nc);
                    }
                }
            }
        };
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mx[i][j] != '#' && !visited[i][j]){
                    bfs(i,j);
                    cc++;
                }
            }
        }
        
        vi ans(cc + 2);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[visited[i][j]]++;
            }
        }
        
        //cout<<16<<endl;
        
        cin>>querys;
        while(querys--){
            int i,j;
            cin>>i>>j;
            i--,j--;
            if(mx[i][j] == '#'){
                cout<<0<<el;
                continue;
            }
            cout<<ans[visited[i][j]]<<el;
        }
        
    }
}

/*

*/