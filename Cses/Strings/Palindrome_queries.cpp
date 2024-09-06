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
typedef pair<int,int> mint;


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

const int MAXN = 2e5+5;

mint base[MAXN];
void prepare() {
  base[0] = ONE;
  for(int i = 1; i < MAXN; i++) base[i] = base[i-1]*BASE;
}

struct segtree{
    int l, r;
    segtree *left = nullptr, *right = nullptr;
    mint value = ZERO;
    segtree(int l, int r) : l(l), r(r){
        if(l == r){
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l, m);
        right = new segtree(m + 1, r);
    }

    void update(int lx, int rx, mint v){
        if(l > rx || r < lx) return;
        if(l >= lx && r <= rx){
            value = v;
            return;
        }
        left->update(lx, rx, v);
        right->update(lx, rx, v);
        
        value = left->value + right->value;
    }
    
    mint query(int lx, int rx){
        if(l > rx || r < lx) return ZERO;
        if(l >= lx && r <= rx) return value;
        
        return left->query(lx, rx) + right->query(lx, rx);
    }
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    prepare();
    segtree hash_nor(0, n);
    segtree hash_rev(0, n);

    for(int i = 0;i<n;i++){
        hash_nor.update(i + 1, i + 1, mint{s[i], s[i]} * base[i]);
    }
    reverse(all(s));
    for(int i = 0;i<n;i++){
        hash_rev.update(i + 1, i + 1, mint{s[i], s[i]} * base[i]);
    }
    
    function<mint(int, int, int)> get_hash = [&](int i, int j, int type){
        if(type == 1){
            return hash_nor.query(0, j + 1) - hash_nor.query(0, i);
        }else{
            //corregir indices
            return hash_rev.query(0, n - i) - hash_rev.query(0, n - (j + 1));
        }
    };

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int idx;
            char c;
            cin>>idx>>c;
            hash_nor.update(idx, idx, mint{c, c} * base[idx - 1]);
            hash_rev.update(n - (idx - 1), n - (idx - 1), mint{c, c} * base[(n - (idx - 1)) - 1]);
        }else{
            int a,b;
            cin>>a>>b;
            a--,b--;
            int l = n - 1 - b;
            int r = n - 1 - a;
            if(l < a){
                cout<<(get_hash(a, b, 1) ==  base[a - l] * get_hash(a, b, 2) ? yes : no)<<el;
            }else{
                cout<<(base[l - a] * get_hash(a, b, 1) ==  get_hash(a, b, 2) ? yes : no)<<el;
            }
        }
    }
    
    
}

/*

*/