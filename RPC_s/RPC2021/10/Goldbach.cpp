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

bool isPrime(int k){
    int cnt = 0;
    for(int i=1;i<=k;i++){
        if(!(k % i)) cnt++;
    }
    return cnt == 2;
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    
    bitset<401> primes;
    
    vi primesarr;
    
    for(int i=2;i<401;i++){
        if(isPrime(i)){
            primes[i] = 1;
            primesarr.pb(i);
        }
    }
    while(tc--){
        int ways = 0;
        int n;
        cin>>n;
        for(int i=0;i<primesarr.size();i++){
            if(n - primesarr[i] >= 0 && primes[n - primesarr[i]]){
                ways += (n - primesarr[i] == primesarr[i] ? 2 : 1);
            }
        }
        cout<<ways / 2<<el;
    }
}

/*

*/