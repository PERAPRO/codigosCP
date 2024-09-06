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
using pii=pair<ll,ll>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int oo = 1e9+7, mod = 1e9+7;
// const ll oo = 1e15; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cross(ll x1, ll y1, ll x2, ll y2){
    return x1 * y2 - y1 * x2;
}

bool check(vector<pair<ll,ll>> &v){
    if(v.size() <= 2) return 1;
    for(int i = 2;i<v.size();i++){
        if(cross(v[1].ff - v[0].ff, v[1].ss - v[0].ss, v[i].ff - v[0].ff, v[i].ss - v[0].ss)) return 0;
    }
    return 1;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int n;
    cin>>n;
    
    if(n <= 6){
        cout<<"possible"<<el;
        return 0;
    }
    
    vector<pair<ll,ll>> pts(n);
    for(auto&[x,y]:pts){
        cin>>x>>y;
    }
    
    int ans = 0;
    
    for(int intentos = 0;intentos<1200;intentos++){
        uniform_int_distribution<int> dis(0, n - 1);
        int frst_pt = dis(rng);
        int scnd_pt = dis(rng);
        // while(frst_pt == scnd_pt) scnd_pt = dis(rng);
        if(frst_pt == scnd_pt) scnd_pt = (frst_pt + 1) % n; 
        //frst_pt y scnd_pt son mis dos primeros candidatos la primera linea
        auto [x1, y1] = pts[frst_pt];
        auto [x2, y2] = pts[scnd_pt];
        
        vector<pair<ll,ll>> restantes;
        
        for(int i = 0;i<n;i++){
            if(i == frst_pt || i == scnd_pt) continue;
            
            if(cross(pts[i].ff - x1, pts[i].ss - y1, x2 - x1, y2 - y1)){ //no es colineal
                restantes.pb(pts[i]);
            }
        }
        
        if(restantes.size() <= 4){
            ans |= 1;
            break;
        }
        
        uniform_int_distribution<int> dis2(0, restantes.size() - 1);
        
        int ff_pt = dis2(rng);
        int ss_pt = dis2(rng);
        // while(ff_pt == ss_pt) ss_pt = dis2(rng);
        if(ff_pt == ss_pt) ss_pt = (ff_pt + 1) % restantes.size(); 
        
        
        auto[xx1,yy1] = restantes[ff_pt];
        auto[xx2,yy2] = restantes[ss_pt];
        
        vector<pair<ll,ll>> set2;
        vector<pair<ll,ll>> set3;
        
        for(int i = 0;i<restantes.size();i++){
            if(i == ff_pt || i == ss_pt) continue;
            
            if(!cross(restantes[i].ff - xx1, restantes[i].ss - yy1, xx2 - xx1, yy2 - yy1)){
                set2.pb(restantes[i]);
            }else{
                set3.pb(restantes[i]);
            }
        }
        
        ans |= (check(set2) && check(set3));
    }
    
    cout<<(ans ? "possible" : "impossible")<<el;

}

/*
2
2
0 2
1 1
2
0 1
1 0
*/