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

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    ll c;
    cin>>c;
    int n;
    cin>>n;
    
    vector<ll> primes(n);
    map<ll, ll> cnt;
    for(int i = 0;i<n;i++){
        cin>>primes[i];
        cnt[primes[i]]++;
    }
    
    sort(all(primes));
    
    pii ans;
    
    for(int i = 0;i<n;i++){
        if(cnt[c / primes[i]] && primes[i] * (c / primes[i]) == c){
            ans = {primes[i], c / primes[i]};
            break;
        }
    }
    cout<<ans.ff<<esp<<ans.ss<<el;
}

/*

*/