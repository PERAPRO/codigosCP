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
using pll=pair<ll,ll>;
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

vi levels;
int sz;
const int N = 1e5+5;
ll dp[N][2];
map<int,pll> m;

ll go(int level, int last_side){
    //if last_side = 0 in my previous movement i went down
    if(level == sz) return 0;
    
    ll &ans = dp[level][last_side];
    
    if(ans == -1){
        int cur_level = levels[level];
        ll delta_y = m[cur_level].ss - m[cur_level].ff;
        if(level == 0){
            ans = delta_y + min(go(level + 1, 0), go(level + 1, 1));
            return ans;
        }
        ll prev_level = levels[level - 1];
        ll delta_x = cur_level - prev_level;
        
        if(!last_side){
            ans = delta_x + delta_y + min(go(level + 1, 0) + abs(m[prev_level].ff - m[cur_level].ss), go(level + 1, 1) + abs(m[prev_level].ff - m[cur_level].ff));
        }else{
            ans = delta_x + delta_y + min(go(level + 1, 0) + abs(m[prev_level].ss - m[cur_level].ss), go(level + 1, 1) + abs(m[prev_level].ss - m[cur_level].ff));
        }
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        if(!m.count(x)){
            m[x] = mp(y,y);
        }
        ckmin(m[x].ff, y);
        ckmax(m[x].ss, y);
    }
    
    sz = m.size();
    for(auto[key, value]: m){
        levels.pb(key);
    }
    
    memset(dp, -1, sizeof dp);
    
    cout<<( min( go(0,0) , go(0,1) ) )<<el;
}

/*

*/