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
string yes="yes";
string no="no";

bool signos_iguales(int a, int b){
    if(a >= 0 && b >= 0) return 1;
    if(a <= 0 && b <= 0) return 1;
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
    
    vector<pii> v(n);
    
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i] = mp(a, b);
        if(abs(a) == 90){
            cout<<yes<<el;
            return 0;
        }
    }
    
    map<int,int> m;
    
    
    for(int i=0;i<n;i++){
        if(signos_iguales(v[i % n].ss, v[(i + 1) % n].ss)){
            for(int i = min(v[i % n].ss, v[(i + 1) % n].ss);i<=max(v[i % n].ss, v[(i + 1) % n].ss);i++){
                m[i]++;
            }
        }else{
            if(abs(v[i % n].ss) + abs(v[(i + 1) % n].ss) == abs(abs(v[i % n].ss) - 180) + abs(abs(v[(i + 1) % n].ss) - 180)){
                cout<<yes<<el;
                return 0;
            }
            if(abs(v[i % n].ss) + abs(v[(i + 1) % n].ss) > abs(abs(v[i % n].ss) - 180) + abs(abs(v[(i + 1) % n].ss) - 180)){
                for(int i = min(v[i % n].ss, v[(i + 1) % n].ss);i<=0;i++){
                    m[i]++;
                }
                for(int i = max(v[i % n].ss, v[(i + 1) % n].ss);i>=0;i--){
                    m[i]++;
                }
            }else{
                for(int i = min(v[i % n].ss, v[(i + 1) % n].ss);i>=-180;i--){
                    m[i]++;
                }
                for(int i = max(v[i % n].ss, v[(i + 1) % n].ss);i<=180;i++){
                    m[i]++;
                }
            }
        }
    }
    
    // for(auto[key, value]:m) cout<<key<<esp;
    
    // cout<<el;
    // cout<<m.size()<<el;
    
    cout<<(m.size() == 361 ? yes : no)<<el;
}

/*

*/