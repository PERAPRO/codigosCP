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
        os<<i<<"";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";


ll a,b,c,d;
ll dist (ll k){
    return max(abs(k - a) * c, abs(k - b) * d) + k * min(c, d);
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    while(tc--){
        cin>>a>>b>>c>>d;
        // a donde estoy yo, b donde esta el ascensor, c tiempo mio, d tiempo del ascesor
        
        // yo soy mas rapido que el ascensor
        if(c < d){
            cout<<a * c<<el;
            continue;
        }
        
        //el ascensor esta muy lejos, me sale mejor irme a pie
        if(a * c < b * d){
            cout<<a * c<<el;
            continue;
        }
        
        
        //me tengo que encontrar con el ascensor
        //el ascensor esta debajo de mi,luego tengo que esperar o subir cierto pisos
        
        ll lo = 0, hi = max(a,b);
        
        ll ans = 1e15;
        
        while(lo < hi){
            ll m1 = lo + (lo + hi) / 3, m2 = hi - (lo + hi) / 3;
            // cout<<m1<<esp<<m2<<endl;
            ckmin(ans, dist(m1));
            ckmin(ans, dist(m2));
            if(dist(m1) > dist(m2)){
                lo = m1 + 1;
            }else{
                hi = m2 - 1;
            }
        }
        
        cout<<ans<<el;
        
        //el ascensor esta encima mio, el ascensor tiene que bajar, tengo que esperarlo o ir subiendo
        
    }
}

/*

*/