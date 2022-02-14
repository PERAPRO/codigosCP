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
using pii=pair<ll,ll>;
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

int n;

bool check(ll computers, deque<pii> &times){
    ll sobrante = 0;
    ll last = 0;
    for(pii p:times){
        if((p.ff - last) * computers + sobrante < p.ss) return 0;
        else{
            sobrante = ((p.ff - last) * computers + sobrante) - p.ss;
            last = p.ff;
            int var = (p.ss - last) * computers + sobrante;
        }
    }
    return 1;
}


int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */

    cin>>n;
    vi a(n), b(n);
    deque<pii> v(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    for(int i=0;i<n;i++){
        v[i] = {b[i], a[i]};
    }

    sort(all(v));

    while(v.front().ff < 0) v.pop_front();

    n = v.size();

    int lo = 1; int hi = 1e9+5;

    check(2,v);

    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(0 >= check(mid, v)){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }

    cout<<lo<<el;

    /*
    for(pii p:v){
        //cout<<p.ss<<esp<<p.ff<<el;
        cout<<p.ff<<esp<<p.ss<<el;
    }
    */
}

/*

*/