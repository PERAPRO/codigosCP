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

const int Log2=27;
const int N=2e5+5;

int v[N], st[N][Log2],n;

void build(){
    for(int i=0;i<n;i++){
        st[i][0] = v[i];
    }
    
    for(int j=1;j<Log2;j++){
        for(int i=0;i + (1 << (j - 1)) < n; i++){
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int x = 31 - __builtin_clz(r - l + 1);
    return min(st[l][x], st[r - (1 << x) + 1][x]);
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n;
    int querys;
    cin>>querys;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    build();
    int l,r;
    
    for(int q=0;q<querys;q++){
        cin>>l>>r;
        l--,r--;
        cout<<query(l , r)<<el;
    }
}

/*

*/