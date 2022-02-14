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

const int N = 1e7+5;
const int oo = 1e9;

bitset<N> isPrime;
vi primes;
vi twins;

void sieve(){
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(ll i=2;i<N;i++){
        if(isPrime[i]){
            primes.pb(i);
            for(ll j = i*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
    for(int i=0;i + 1<primes.size();i++){
        if(primes[i + 1] == primes[i] + 2){
            twins.pb(primes[i]);
            twins.pb(primes[i + 1]);
        }
    }
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    sieve();
    while(tc--){
        int n;
        cin>>n;
        int next = oo, prev = oo;
        int ii = lower_bound(all(twins), n) - twins.begin();
        
        if(ii < twins.size())
            next = twins[ii];
        if(ii != 0)
            prev = twins[ii - 1];
        
        if(abs(n - prev) < abs(n - next))
            cout<<prev<<el;
        else
            cout<<next<<el;
    }
}

/*

*/