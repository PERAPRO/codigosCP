/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
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

int fexp(int a, int b){
    int ans = 1;
    for(;b;a = a * a, b >>= 1){
        if(b&1){
            ans *= a;
        }
    }
    return ans;
}

bool check(vector<pii> &v){
    auto [x0, y0] = v[0];
    auto [x1, y1] = v[1];
    auto [x2, y2] = v[2];
    
    if((x1 == x0 && y1 == y0 + 1) && (x2 == x0 + 1 && y0 == y2)) return 1;
    if((x1 == x0 && y1 == y0 + 1) && (x2 == x0 + 1 && y0 + 1 == y2)) return 1;
    if((x1 == x0 + 1 && y1 == y0) && (x2 == x0 + 1 && y0 + 1 == y2)) return 1;
    if((x1 == x0 + 1 && y1 == y0 - 1) && (x2 == x0 + 1 && y0 == y2)) return 1;
    
    // cout<<"size : "<<v.size()<<el;
    // for(pii p:v){
    //     cout<<p.ff<<esp<<p.ss<<el;
    // }
    return 0;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    
    int nn = 1<<n;
    
    vector<vi> mx(nn, vi(nn));
    
    // map<int, vector<pii>> m;
    
    int colores = (fexp(4,n) - 1) / 3;
    // cout<<colores<<endl;
    
    vector<vector<pii>> m(colores + 5);
    
    for(int i=0;i<nn;i++){
        for(int j=0;j<nn;j++){
            cin>>mx[i][j];
            m[mx[i][j]].pb({i,j});
        }
    }
    
    bool ans = 1;
    
    for(int i = 0;i<colores;i++){
        if(!i) ans &= (m[i].size() == 1);
        else ans &= (m[i].size() == 3);
        
        if(i && m[i].size() == 3) ans &= check(m[i]);
    }
    
    cout<<ans<<el;
}

/*

*/