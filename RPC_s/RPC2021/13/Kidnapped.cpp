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
    while(tc--){
        cin>>n>>m;
        
        vector<string> mx(n);
        
        auto isValid = [&] (int i, int j){
            return i >= 0 && i < n && j >= 0 && j < m && mx[i][j] != '#';
        };
        
        
        for(int i=0;i<n;i++){
            cin>>mx[i];
        }
        
        int ini_i, ini_j, fin_i, fin_j;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mx[i][j] == 'S')
                    ini_i = i, ini_j = j;
                if(mx[i][j] == 'X')
                    fin_i = i, fin_j = j;
            }
        }
        
        vector<vi> distances(n, vi(m, oo));
        
        distances[fin_i][fin_j] = 0;
        
        queue<int> qr, qc;
        
        qr.push(fin_i);
        qc.push(fin_j);
        
        while(qr.size()){
            int r = qr.front();
            int c = qc.front();
            qr.pop(); qc.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr, nc) && distances[r][c] + 1 < distances[nr][nc]){
                    distances[nr][nc] = distances[r][c] + 1;
                    qr.push(nr); qc.push(nc);
                }
            }
        }
        
        if(distances[ini_i][ini_j] == oo){
            cout<<"No exit"<<el;
            continue;
        }
        
        pii cur = {ini_i, ini_j};
        pii end = {fin_i, fin_j};
        
        while(cur != end){
            int r = cur.ff;
            int c = cur.ss;
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr, nc) && distances[nr][nc] == distances[r][c] - 1){
                    cout<<dirs[i];
                    cur = {nr, nc};
                    break;
                }
            }
        }
        cout<<el;
        
    }
}

/*

*/