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

const int oo = 1e9+7;

const int sz = 500;

const int N=2e5+5;

int cdiv(int a, int b){
    return (a + b - 1) / b;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n, q, l, r, lb, rb, ans;
    cin>>n>>q;
    
    vi v(N,oo);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    vi b(N / sz + 1, oo);
    
    for(int i=0;i<n;i++){
        b[i / sz] = min(v[i] , b[i / sz]);
    }
    
    while(q--){
        cin>>l>>r;
        
        l--, r--;
        
        lb = l / sz;
        rb = r / sz;
        
        ans = oo;
        
        for(int i=l;i<=r;){
            if(i % sz == 0 && i + sz - 1 <= r){
                ckmin(ans, b[i / sz]);
                i += sz;
            }else{
                ckmin(ans, v[i]);
                i++;
            }
        }
        
        cout<<ans<<el;
    }
    
}

/*

*/