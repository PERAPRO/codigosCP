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

const int sz = 450;

const int N=2e5+5;

int cdiv(int a, int b){
    return (a + b - 1) / b;
}

struct query{
    int l, r, id;
    query(){}
    query(int l, int r, int id) : l(l), r(r), id(id){}
};

bool cmp(query &a, query &b){
    if(a.l / sz != b.l / sz) return a.l / sz < b.l / sz;
    return ((a.l / sz) & 1 ? a.r > b.r : a.r < b.r);
}

int freq[N];
int v[N];

int total = 0;

void rem(int idx){
    freq[idx]--;
    if(!freq[idx]) total--;
}

void add(int idx){
    if(!freq[idx]) total++;
    freq[idx]++;
}

int get_ans(){
    return total;
}


int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n, q, l, r;
    cin>>n>>q;
    
    map<int,int> m;
    
    int compress = 1;

    for(int i=0;i<n;i++){
        cin>>v[i];
        if(!m.count(v[i])){
            m[v[i]] = compress;
            v[i] = compress++;
        }else{
            v[i] = m[v[i]];
        }
    }

    vector<query> querys(q);

    for(int i= 0; i<q;i++){
        cin>>l>>r;
        l--, r--;
        querys[i] = {l,r,i};
    }

    sort(all(querys), cmp);

    l = 0, r = -1;

    vi ans(q);

    for(int i=0;i<q;i++){
        query cur = querys[i];

        while(r < cur.r) add( v[++r] );
        while(l > cur.l) add( v[--l] );
        while(l < cur.l) rem( v[l++] );
        while(r > cur.r) rem( v[r--]);

        ans[cur.id] = get_ans();
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<el;

}

/*

*/