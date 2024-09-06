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

const int N = 1002;
const int M = 102;
const ll mod = 1e9+7;
int n, m;

const int alpha = 256;
vector<vector<int>> kmp_automaton(string &t) {
  vector<vector<int>> aut( t.size() + 1, vector<int> ( alpha ) );
  aut[0][ t[0] ] = 1;
  for(int i = 1, j = 0; i <= t.size(); ++i) {
    aut[i] = aut[j];
    if(i < t.size()) {
      aut[i][ t[i] ] = i+1;
      j = aut[j][ t[i] ];
    }
  }
  return aut;
}

vector<vi> aut;
ll dp[N][M];
string s;
ll go(int in, int im){
    // if(im == m) return 1;
    if(in == n){
        return im == m;
    }
    
    ll &ans = dp[in][im];
    if(ans == -1){
        ans = 0;
        for(int i = 'A';i<='Z';i++){
            int t = aut[im][i];
            if(im == m){
                ans = (ans + go(in + 1, im)) % mod;
            }
            else if(i == s[im]){
                ans = (ans + go(in + 1, im + 1)) % mod;
            }else{
                ans = (ans + go(in + 1, t)) % mod;
            }
            // cout<<ans<<esp<<in<<esp<<im<<el;
        }
        // cout<<ans<<el;
    }
    return ans;
}
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n>>s;
    aut = kmp_automaton(s);
    m = s.size();
    // cout<<n<<esp<<s<<esp<<m<<el;
    memset(dp, -1, sizeof dp);
    
    cout<<go(0,0)<<el;
}

/*
aababa|
aaabab
*/