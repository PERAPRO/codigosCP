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
using pii=pair<ll,ll>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ostream& operator<<(ostream& os, const vector<ll> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const ll oo = 1e15;

struct segtree{
    ll val1 = oo, val2 = oo;
    int l,r;
    segtree *left, *right;
    
    segtree (int l, int r, vi &v): l(l), r(r){
        if(l == r){
            val1 = v[l];
            val2 = v[l];
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l, m, v);
        right = new segtree(m + 1, r, v);
        val1 = min(left->val1, right->val1);
        val2 = min(left->val2, right->val2);
    }
    
    void update(int lx, int rx, ll v, int type){
        if(lx > r || rx < l) return;
        // cout<<"l "<<l<<" r "<<r<<" lx "<<lx<<" type "<<type<<endl;
        if(type == 1){
            if(l >= lx && r <= rx){
                // cout<<"if "<<endl;
                val1 = v;
                return;
            }
            left->update(lx, rx, v, type);
            right->update(lx, rx, v, type);
            val1 = min(left->val1, right->val1);
        }else{
            if(l >= lx && r <= rx){
                val2 = v;
                return;
            }
            left->update(lx, rx, v, type);
            right->update(lx, rx, v, type);
            val2 = min(left->val2, right->val2);
            
        }
    }
    
    ll query(int lx, int rx, int type){
        if(lx > r || rx < l) return oo;
        // if(lx < l || rx > r) return oo;
    
        if(type == 1){
            if(l >= lx && r <= rx){ 
                return val1;
            }
            return min(left->query(lx, rx, type), right->query(lx, rx, type));
        }else{
            if(l >= lx && r <= rx){
                return val2;
            }
            return min(left->query(lx, rx, type), right->query(lx, rx, type));
            
        }
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
    
    vi v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    segtree st(0,n - 1, v);
    // cout<<n<<endl;
    // map<int,set<int>> s1;
    // map<int,set<int>> s2;
    for(int i=0, j = n - 1;i<n;i++,j--){
        st.update(i, i, v[i] + i,1);
        // s1[v[i] + i].insert(i);
        st.update(j, j, v[j] + i, 2);
        // s2[v[j] + i].insert(j);
    }
    
    for(int qq = 0;qq<q;qq++){
        int type;
        cin>>type;
        if(type == 1){
            int x, value;
            cin>>x>>value;
            x--;
            // s1[st.query(x,x,1)].erase(x);
            // s2[st.query(x,x,2)].erase(x);
            st.update(x,x,value + x,1);
            // s1[value + x].insert(x);
            st.update(x,x,value + (n - 1 - x),2);
            // s2[value + (n - 1 - x)].insert(x);
        }else{
            int idx; cin>>idx;
            idx--;
            int left = st.query(0, idx, 2);
            // int i_left
            int right = st.query(idx , n - 1, 1);
            // int i_right = *s2[right].begin();
            // cout<<left<<esp<<right<<el;
            cout<<min(right - idx, left - (n - 1 - idx))<<el;
        }
        
    }
    
}

/*

*/