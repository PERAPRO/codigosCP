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

int numbers[2][2];

int mapeo(int x, int y){
    return numbers[x][y];
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m;
    cin>>n>>m;
    
    numbers[0][0] = 2, numbers[0][1] = 1, numbers[1][0] = 3, numbers[1][1] = 4;
    
    vector<vector<char>> matrix(n, vector<char>(m));
    
    string s;
    
    int cur_t=0;
    
    map<pii,int> t;
    
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            matrix[i][j] = s[j];
            if(matrix[i][j] == 'T'){
                t[make_pair(i,j)] = cur_t;
                cur_t += 2;
            }
        }
    }
    
    int torres = cur_t / 2;
    
    //Cada torre tiene direccion horzontal o vertical, debo fijarlas de acuerdo a las necesidades
    //de las otras torres y de los objetivos
    //Un objetivo puede ser atacado por una o a lo sumo dos torres :)
    
    //2 SAT (a v b) = (~a -> b) ^ (~b -> a)
    
    //t[i][j] -> up, t[i][j] + 1 -> down;
    //t[i][j] + 2 * torres ->left, t[i][j] + 2 * torres + 1 -> right
    
    vector<vi> g(4 * torres);
    vector<vi> gt(4 * torres);
    
    auto add = [&] (int var1, int var1n, int var2,int var2n){
        g[var1n].pb(var2);
        g[var2n].pb(var1);
        
        gt[var2].pb(var1n);
        gt[var1].pb(var2n);
    };
    
    auto check_thief = [&] (int ii, int jj){
        vector<pii> verticales;
        
        for(int i = ii;i>-1;i--){
            if(matrix[i][jj] == '#') break;
            if(matrix[i][jj] == 'T'){
                verticales.pb({i,jj});
                break;
            }
        }
        for(int i = ii;i<n;i++){
            if(matrix[i][jj] == '#') break;
            if(matrix[i][jj] == 'T'){
                verticales.pb({i,jj});
                break;
            }
        }
        
        vector<pii> horizontales;
        
        for(int j = jj;j>-1;j--){
            if(matrix[ii][j] == '#') break;
            if(matrix[ii][j] == 'T'){
                horizontales.pb({ii,j});
                break;
            }
        }
        for(int j = jj;j<m;j++){
            if(matrix[ii][j] == '#') break;
            if(matrix[ii][j] == 'T'){
                horizontales.pb({ii,j});
                break;
            }
        }
        
        int var1, var1n, var2, var2n;
        
        if(verticales.size() == 1 && horizontales.size() == 1){
            var1 = t[make_pair(verticales[0].ff, verticales[0].ss)] + (verticales[0].ff > ii ? 0 : 1);
            var1n = var1 ^ 1;
            
            var2 = t[make_pair(horizontales[0].ff, horizontales[0].ss)] + 2 * torres + (horizontales[0].ss > jj ? 0 : 1);
            var2n = var2 ^ 1;
            
            add(var1, var1n, var2, var2n);
        }else if(horizontales.size() == 1){
            var1 = t[make_pair(horizontales[0].ff, horizontales[0].ss)] + 2 * torres + (horizontales[0].ss > jj ? 0 : 1);
            var1n = var1 ^ 1;
            
            var2 = var1;
            var2n = var2 ^ 1;
            
            add(var1, var1n, var2, var2n);
        }else if(verticales.size() == 1){
            var1 = t[make_pair(verticales[0].ff, verticales[0].ss)] + (verticales[0].ff > ii ? 0 : 1);
            var1n = var1 ^ 1;
            
            var2 = var1;
            var2n = var2 ^ 1;
            
            add(var1, var1n, var2, var2n);
        }
    };
    
    auto check_tower = [&] (int ii, int jj){
        
        //Solo evito chocar a mis vecinos, cuando analice a mis vecinos, evitaran chocarme a mi
        
        vector<pii> verticales;
        
        for(int i = ii - 1;i>-1;i--){
            if(matrix[i][jj] == '#') break;
            if(matrix[i][jj] == 'T'){
                verticales.pb({i,jj});
                break;
            }
        }
        for(int i = ii + 1;i<n;i++){
            if(matrix[i][jj] == '#') break;
            if(matrix[i][jj] == 'T'){
                verticales.pb({i,jj});
                break;
            }
        }
        
        vector<pii> horizontales;
        
        for(int j = jj - 1;j>-1;j--){
            if(matrix[ii][j] == '#') break;
            if(matrix[ii][j] == 'T'){
                horizontales.pb({ii,j});
                break;
            }
        }
        for(int j = jj + 1;j<m;j++){
            if(matrix[ii][j] == '#') break;
            if(matrix[ii][j] == 'T'){
                horizontales.pb({ii,j});
                break;
            }
        }
        
        int var1, var1n, var2, var2n;
        
        if(verticales.size()){
            var1 = t[make_pair(ii, jj)] + (ii > verticales[0].ff ? 1 : 0);
            var1n = var1 ^ 1;
            
            var2 = var1;
            var2n = var2 ^ 1;
            
            add(var1, var1n, var2, var2n);
        }
        if(horizontales.size()){
            var1 = t[make_pair(ii, jj)] + 2 * torres + (jj > horizontales[0].ss ? 1 : 0);
            var1n = var1 ^ 1;
            
            var2 = var1;
            var2n = var2 ^ 1;
            
            add(var1, var1n, var2, var2n);
        }
    };
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 'n'){
                check_thief(i, j);
            }else if(matrix[i][j] == 'T'){
                check_tower(i,j);
            }
        }
    }
    
    vi visited(4 * torres);

    stack<int> order;

    function<void (int)> dfs1 = [&] (int u){
        visited[u] = 1;
        for(int v:g[u]){
            if(!visited[v])
                dfs1(v);
        }

        order.push(u);
    };

    for(int i=0;i<4 * torres;i++){
        if(!visited[i])
            dfs1(i);
    }

    vi comp(4 * torres, -1);

    function<void(int, int)> dfs2 = [&] (int u, int cl){
        comp[u] = cl;
        for(int v:gt[u]){
            if(comp[v] == -1)
                dfs2(v,cl);
        }
    };


    for(int i=0, j = 0;i<4 * torres;i++){
        int u = order.top();
        order.pop();
        if(comp[u] == -1){
            dfs2(u, j++);
        }
    }

    bool flag=1;

    vi asignacion(2 * torres,0);

    for(int i=0;i<4 * torres;i += 2){
        if(comp[i] == comp[i + 1])
            flag = 0;
        asignacion[i / 2] = comp[i] > comp[i + 1];
    }
    /*
    for(auto vv:matrix){
        for(char c:vv){
            cout<<c;
        }
        cout<<el;
    }
    **/
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 'T')
                cout<<mapeo(asignacion[t[make_pair(i,j)] / 2], asignacion[(t[make_pair(i,j)] + 2 * torres) / 2]);
            else
                cout<<matrix[i][j];
        }
        cout<<el;
    }
    
}

/*

*/