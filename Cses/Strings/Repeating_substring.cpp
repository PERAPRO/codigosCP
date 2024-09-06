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
using mint=pair<int,int>;
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

const int MODS[] = { 1001864327, 1001265673 };
const mint BASE(256, 256), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, const int& mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, const int& mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int& mod) { return 1ll*a*b%mod; }
inline ll operator ! (const mint a) { return (ll(a.first)<<32)|ll(a.second); }
inline mint operator + (const mint a, const mint b) {
  return {add(a.first, b.first, MODS[0]), add(a.second, b.second, MODS[1])};
}
inline mint operator - (const mint a, const mint b) {
  return {sbt(a.first, b.first, MODS[0]), sbt(a.second, b.second, MODS[1])};
}
inline mint operator * (const mint a, const mint b) {
  return {mul(a.first, b.first, MODS[0]), mul(a.second, b.second, MODS[1])};
}

const int MAXN = 1e5+5;

mint base[MAXN];
void prepare() {
  base[0] = ONE;
  for(int i = 1; i < MAXN; i++) base[i] = base[i-1]*BASE;
}
template <class type>
struct hashing {
  vector<mint> code;
  hashing(type &t) {
    code.resize(t.size()+1);
    code[0] = ZERO;
    for (int i = 1; i < code.size(); ++i)
      code[i] = code[i-1]*BASE + mint{t[i-1], t[i-1]};
  }
  mint query(int l, int r) {
    return code[r+1] - code[l]*base[r-l+1];
  }
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    prepare();
    string s;
    cin>>s;
    int n = s.size();
    hashing hash(s);
    int lo = 0, hi = s.size();
    while(lo < hi){
        int mid = (lo + hi + 1) >> 1;
        unordered_map<ll,int> m;
        int check = 0;
        for(int i = 0;i + mid - 1<n;i++){
            ll cur_hash = !hash.query(i, i + mid - 1);
            m[cur_hash]++;
            check |= m[cur_hash] > 1;
        }
        if(check){
            lo = mid ;
        }else{
            hi = mid - 1;
        }
    }
    if(lo == 0){
        cout<<-1<<el;
        return 0;
    }
    map<ll,int> m;
    for(int i = 0;i + lo - 1<n;i++){
        ll cur_hash = !hash.query(i, i + lo - 1);
        m[cur_hash]++;
        if(m[cur_hash] > 1){
            cout<<s.substr(i, lo)<<el;
        }
    }
    
}

/*

*/