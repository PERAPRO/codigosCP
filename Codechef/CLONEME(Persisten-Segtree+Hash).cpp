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

const ll mod = 1000777121;
const ll base = 256;

const int N=1e5+5;


struct segtree{
    //int l, r;
    int value = 0;
    segtree *left, *right;

    segtree(int value) : left(nullptr), right(nullptr), value(value) {}

    segtree(segtree *left, segtree *right): left(left), right(right) {
        if(left) value += left ->value;
        if(right) value += right ->value;
    }

};

segtree* build(int lx, int rx){
    if(lx == rx)
        return new segtree(0);
    int m = (lx + rx) / 2;
    return new segtree(build(lx, m), build(m + 1, rx));
}

segtree* update(segtree *v, int lx, int rx, int idx){
    if(lx == rx){
        return new segtree(v->value + 1);
    }
    int m = (lx + rx) / 2;

    if(idx <= m)
        return new segtree(update(v->left, lx, m, idx), v->right);
    return new segtree(v->left, update(v->right, m + 1, rx, idx));
}

pii quer = {0, 0};

void find_kth(segtree *vl, segtree *vr,int lx, int rx, int idx){
    if(lx == rx){
        quer.ss = vr->value - vl->value;
        return;
    }
    int m = (lx + rx) / 2;
    int left_count = vr->left->value - vl->left->value;
    if(idx <= m)
        return find_kth(vl->left, vr->left, lx, m, idx);
    quer.ff += left_count;
    return find_kth(vl->right, vr->right, m + 1, rx, idx);
}

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    //Idea: https://www.youtube.com/watch?v=aivMNbsQMG0&ab_channel=GauravSen
    int tc;
    cin>>tc;

    vl BASE(N, 1);
    for(int i=1;i<N;i++){
        BASE[i] = (BASE[i - 1] * base) % mod;
    }
    while(tc--){
        int n,querys,a,b,c,d;
        cin>>n>>querys;

        vl v(n + 1);
        vl pref_sqr(n + 1);
        vl pref_sum(n + 1);

        vl hash(n + 1);

        vector<segtree*> roots;

        roots.pb(build(0,N - 1));

        for(int i=1;i<=n;i++){
            cin>>v[i];
            pref_sum[i] = pref_sum[i - 1] + v[i];
            pref_sqr[i] = pref_sqr[i - 1] + v[i] * v[i];
            roots.pb(update(roots.back(), 0, N - 1, v[i]));
            hash[i] = (hash[i - 1] + BASE[v[i]]) % mod;
        }

        while(querys--){
            cin>>a>>b>>c>>d;
            ll hash1 = (hash[b] - hash[a - 1] + mod) % mod;
            ll hash2 = (hash[d] - hash[c - 1] + mod) % mod;

            if(hash1 == hash2){
                cout<<yes<<el;
                continue;
            }

            ll sums1 = pref_sum[b] - pref_sum[a - 1], sums2 = pref_sum[d] - pref_sum[c - 1];
            ll sqr1 = pref_sqr[b] - pref_sqr[a - 1], sqr2 = pref_sqr[d] - pref_sqr[c - 1];

            ll resta = sums1 - sums2;

            if(!resta){
                cout<<no<<el;
                continue;
            }
            
            ll suma = (sqr1 - sqr2) / resta;

            ll p = (suma + resta) / 2;
            ll q = suma - p;

            if(p > N - 2 || q > N - 2 || p < 1 || q < 1){
                cout<<no<<el;
                continue;
            }
            
            hash1 = (hash1 + BASE[q]) % mod;
            hash2 = (hash2 + BASE[p]) % mod;
            
            if(hash1 != hash2){
                cout<<no<<el;
                continue;
            }
            
            quer = {0, 0};
            find_kth(roots[a - 1], roots[b], 0, N - 1, p);
            pii pquer = quer;
            quer = {0,0};
            find_kth(roots[c - 1], roots[d], 0, N - 1, q);
            pii qquer = quer;

            if(!pquer.ss || !qquer.ss){
                cout<<no<<el;
                continue;
            }

            pii pseg = {pquer.ff, pquer.ff + pquer.ss - 1};
            pii qseg = {qquer.ff, qquer.ff + qquer.ss - 1};

            bool flag = !(pseg.ff > qseg.ss || pseg.ss < qseg.ff);

            if(hash1 == hash2 && flag){
                cout<<yes<<el;
            }else{
                cout<<no<<el;
            }
        }
    }
}

/*

*/