/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;
#define abs_value(a)(((a)>0)?(a):-(a))

const int sz = 4000000;

bitset<sz> prime;
vi primes;


void sieve(){
    prime.set();
    prime[0]=prime[1]=0;
    for(ll i=2;i<=sz;i++){
        if(prime[i]){
            primes.pb(i);
            for(ll j=i*i;j<=sz;j+=i){
                prime[j]=0;
            }
        }
    }
}

long long mult(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

ll fexp(ll base, ll expo, ll mod){
    ll ans = 1;
    for(;expo;base=mult(base,base,mod),expo>>=1){
        if(expo&1)
            ans=mult(ans,base,mod);
    }
    return ans%mod;
}

bool isPrime(ll n, int iter=8){
    if(n<4)
        return n==2 || n==3;
    for(int i=0;i<iter;i++){
        ll a = 2 + rand() % (n-3);
        if(fexp(a,n-1,n)!=1)
            return false;
    }
    return true;
}


ll gcd(ll a, ll b){return !b ? a : gcd(b,a%b);}

long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}

long long rho(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long y = x0;
    long long g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(abs(x - y), n);
    }
    return g;
}

int main(){
	fast_io;
	sieve();
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
        vector<ll> ans;
        for(const ll &p : primes){
            while(n%p==0){
                ans.pb(p);
                n/=p;
            }
            if(n==1) break;
        }
        if(isPrime(n)){
            ans.pb(n);
        }else if (n>1){
            ll d=rho(n);
            ans.pb(min(d,n/d));
            ans.pb(max(d,n/d));
        }
        for(int i=0;i<ans.size()-1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[ans.size()-1]<<endl;
	}
}
