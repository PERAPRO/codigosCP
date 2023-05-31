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

const int N = 1e5+5;
const int oo = 1e9;
int n;
map<int,int> ids;
vector<set<pii>> gruas;
vector<vi> gruas_in_city(N, vi());

ll dp[N];

ll go(int city){
    if(city == n) return 0;
    
    ll &ans = dp[city];
    if(ans == -1){
        ans = go(city + 1);
        for(int grua:gruas_in_city[city]){
            auto it = gruas[grua].upper_bound(mp(city, oo));
            if(it == gruas[grua].end()) continue;
            // cout<<it->ff<<el;
            int cur_cost = gruas[grua].lower_bound(mp(city, 0))->ss;
            ckmax(ans, go(it->ff) + (it->ss - cur_cost));
        }
    }
    return ans;
}

vector<vector<pii>> datos(N, vector<pii>(12, mp(-1, -1)));
vector<int> keys;
pii zero = {-1, -1};
int new_id(int id){
    return lower_bound(all(keys), id) - keys.begin();
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    // int n;
    cin>>n;
    
    int id = 0;
    
    for(int i=0;i<n;i++){
        int g; cin>>g;
        for(int j = 0;j<g;j++){
            int id_grua, cost;
            cin>>id_grua>>cost;
            datos[i][j] = mp(id_grua, cost);
            keys.pb(id_grua);
            // if(!ids.count(id_grua)) ids[id_grua] = id++;
            
            // gruas[id_grua][i] = cost;
            // gruas_in_city[i].pb(id_grua);
        }
    }
    
    sort(all(keys));
    keys.erase(unique(all(keys)), keys.end());
    // cout<<keys;
    set<pii> s;
    gruas.assign(keys.size(), s);
    
    for(int i=0;i<n;i++){
        for(int g = 0;g<12;g++){ 
            if(datos[i][g] == zero) break;
            auto [grua_id, cost] = datos[i][g];
            // cout<<"n : "<<i<<esp<<"grua_id "<<grua_id<<esp<<"cost "<<cost<<el;
            int n_id = new_id(grua_id);
            gruas[n_id].insert(mp(i, cost));
            gruas_in_city[i].pb(n_id);
        }
    }
    
    // cout<<gruas_in_city[3]<<el;
    // for(auto[city, cost]:gruas[1]){
    //     cout<<"city "<<city<<" costo: "<<cost<<el;
    // }
    
    memset(dp, -1, sizeof dp);
    
    cout<<go(0)<<el;
    

}

/*

*/