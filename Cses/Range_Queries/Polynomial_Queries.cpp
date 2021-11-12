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
string yes="Yes";
string no="No";

ll change(ll n, ll a, ll b){
    if(!n || !a || !b) return 0;
    return n * (a + b) / 2;
}

struct segtree{
    int l = 0, r = 0;
    ll value = 0;
    segtree *left = nullptr, *right = nullptr;
    int a = 0, b = 0;

    segtree(int l, int r, vl &v): l(l), r(r){
        if(l == r){
            value = v[l];
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l , m, v);
        right = new segtree(m + 1, r, v);
        value = left->value + right->value;
    }

    void push(){
        if(!a or !b || l == r) return;
        ll left_elem = left->r - left->l;
        ll factor = (b - a)/(r - l);
        
        left->a += a, left->b += a + left_elem * factor;
        right->a += a + (left_elem + 1) * factor, right->b += b; 
        
        left->value += change(left->r - left->l + 1, a, a + left_elem * factor);
        right->value += change(right->r - right->l + 1, a + (left_elem + 1) * factor, b);
        
        a = b = 0;
    }

    void update(int lx, int rx, int ax, int bx){
        push();
        if(r < lx || l > rx) return;
        if(l >= lx && r <= rx){
            a += ax, b += bx;
            value += change(r - l + 1, ax, bx);
            return;
        }
        int m = (l + r) / 2;
        if(m >= lx && rx > m){ // Me divido en los dos hijos
            int left_c = m - lx;
            left->update(lx, m, ax, ax + left_c);  //Cuantos elementos necesito del lado izquierdo
            right->update(m + 1, rx, ax + left_c + 1, bx);
        }else if(m >= lx){
            left->update(lx, rx, ax, bx);
        }else{
            right->update(lx, rx, ax, bx);
        }
        value = left->value + right->value;
    }

    ll query(int lx, int rx){
        push();
        if(r < lx || l > rx) return 0;
        if(l >= lx && r <= rx){
            return value;
        }
        return left->query(lx, rx) + right->query(lx, rx);
    }
};

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q,type,a,b;
    cin>>n>>q;
    vl v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    segtree st(0, n - 1, v);
    for(int query = 0;query < q;query++){
        cin>>type>>a>>b;
        //cout<<"query # "<<query<<endl;
        a--,b--;
        if(type == 1){
            st.update(a, b, 1, 1 + (b - a));
        }else{
            cout<<st.query(a, b)<<el;
        }
    }
}

/*
int n,q;
cin>>n>>q;
vl v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}

int type,a,b;
while(q--){
    cin>>type>>a>>b;
    a--,b--;
    if(type == 1){//Update
        for(int i = a,j=1;i<=b;i++,j++){
            v[i]+=j;
        }
    }else{
        ll sum = 0;
        for(int i=a;i<=b;i++) sum+=v[i];
        cout<<sum<<el;
    }
}
    
import random
n = random.randint(15,20)
q = random.randint(18,20)

print(n,q)

vector = [0] * n
for i in range (n):
    vector[i] = random.randint(1000000000,100000000000)
    
for i in range (n):
    print(vector[i], end = " ")
print()

for i in range(q):
    tipo = random.randint(1,2)
    a = random.randint(1,n)
    b = random.randint(a,n)
    print(tipo , a , b)

    
*/