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

vi dr = {1,-1, 0,0};    //D U L R
vi dc = {0, 0,-1,1};

const int N = 1000;
const int oo=1e9+7;
int n,m;

char mx [N][N]; 

bool isValid(int i, int j){
    return i > -1 && j > -1 && i < n && j < m && mx[i][j] != '#';
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n>>m;
    //vector<string> mx(n);
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            mx[i][j] = s[j];
        }
    }
    
    vector<pii> monsters;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx[i][j] == 'M')
                monsters.pb({i,j});
        }
    }
    
    vector<vi> distances(n, vi(m,oo));
    vector<vi> distances_m(n, vi(m,oo));
    vector<vi> parent(n, vi(m,-1));
    
    int x1,y1;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mx[i][j] == 'A')
                x1=i, y1=j;
                
    queue<pii> q;
    
    distances[x1][y1]=0;
    q.push({x1,y1});
    
    while(q.size()){
        int r=q.front().ff;
        int c=q.front().ss;
        q.pop();
        for(int i=0;i<4;i++){
            int nr= r + dr[i];
            int nc= c + dc[i];
            if(isValid(nr, nc) && distances[r][c] + 1 < distances[nr][nc]){
                parent[nr][nc] = i;
                distances[nr][nc] = distances[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    for(int i=0;i< (int) monsters.size(); i++){
        distances_m[monsters[i].ff][monsters[i].ss] = 0;
        q.push({monsters[i].ff, monsters[i].ss});
    }
    
    while(q.size()){
        int r=q.front().ff;
        int c=q.front().ss;
        q.pop();
        for(int i=0;i<4;i++){
            int nr= r + dr[i];
            int nc= c + dc[i];
            if(isValid(nr, nc) && distances_m[r][c] + 1 < distances_m[nr][nc]){
                //parent[nr][nc] = i;
                distances_m[nr][nc] = distances_m[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    int f1 = -1, f2 =-1;
    //bool f=0;
    
    for(int i=0;i<n;i++){
        if(distances[i][0] < distances_m[i][0])
            f1=i, f2=0;
        else if(distances[i][m - 1] < distances_m[i][m-1])
            f1=i, f2=m - 1;
    }
            
    for(int j=0;j<m;j++){
        if(distances[0][j] < distances_m[0][j])
            f1=0, f2=j;
        else if(distances[n - 1][j] < distances_m[n - 1][j])
            f1=n - 1, f2=j;
    }
    //cout<<f1<<esp<<f2<<el;
    if(f1 > -1){
        cout<<yes<<el;
        string path="";
        /*
        vi dr = {1,-1, 0,0};    //D U L R
        vi dc = {0, 0,-1,1};
        */
        while(parent[f1][f2] > -1){
            switch(parent[f1][f2]){
                case 0:
                    path+='D';
                    f1--;
                    break;
                case 1:
                    path+='U';
                    f1++;
                    break;
                case 2:
                    path += 'L';
                    f2++;
                    break;
                case 3:
                    path += 'R';
                    f2--;
                    break;
            }   
        }
        reverse(path.begin(), path.end());
        cout<<path.size()<<el<<path<<el;
    }else{
        cout<<no<<el;
    }
}

/*

*/