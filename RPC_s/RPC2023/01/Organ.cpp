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

int g(int n){
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans *= i;
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    vi factoriales = {1,2,6,24,120,720,5040,40320,362880};
    
    int n;
    cin>>n;
    
    vi numbers;
    
    if(n == 1){
        cout<<0<<el;
        return 0;
    }
    
    while(n){
        int idx = upper_bound(all(factoriales), n) - factoriales.begin();
        n -= factoriales[idx - 1];
        numbers.pb(idx);
    }
    
    sort(all(numbers));
    
    cout<<numbers;

}

/*

*/