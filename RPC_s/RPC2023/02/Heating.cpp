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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

struct edge;
typedef list<edge>::iterator iter;
 
struct edge{
    ll value, tolerance;
    iter next, prev;
    edge(ll value) : value(value), tolerance(value) {}
};
int n;

list<edge> lista(vl &v){
    list<edge> l;
    for(int i=0;i<n;i++){
        edge e(v[i]);
        if(!i){
            l.pb(e);
            l.back().prev = l.back().next = l.begin(); 
        }else{
            auto it = l.end();
            it--;
            edge &last = *it;
            e.next = last.next;
            e.prev = it;
            l.pb(e);
            it++;
            last.next = it;
            l.begin()->prev = it;
        }
    }
    return l;
}

bool check(list<edge> l, ll m){
    // cout<<"INITIAL SIZE = "<<l.size()<<" M: "<<m<<endl;
    auto it = l.begin();
    int borrados = 0;
    for(int i = 0;i<n;i++){
        if(it->value <= m){
            // cout<<"try with : "<<it->value<<endl;
            it->tolerance +=  m;
            // cout<<"my tolerance : "<<it->tolerance<<endl;
            while(it->prev->value <= it->tolerance || it->next->value <= it->tolerance){
                while(it->prev->value <= it->tolerance){
                    // cout<<"merge prev with : "<<it->prev->value<<endl;
                    it->tolerance += it->prev->tolerance;
                    it->value = min(it->value, it->prev->value);
                    it->prev->prev->next = it;
                    it->prev = it->prev->prev;
                    borrados++;
                    if(borrados == n - 1) return 1;
                }
                while(it->next->value <= it->tolerance){
                    // cout<<"merge next with : "<<it->next->value<<endl;
                    it->tolerance += it->next->tolerance;
                    it->value = min(it->value, it->next->value);
                    it->next->next->prev = it;
                    it->next = it->next->next;
                    borrados++;
                    if(borrados == n - 1) return 1;
                }
            }
            it->tolerance -= m;
        }
        it = it->next;
    }
    return borrados == n - 1;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    // int n;
    cin>>n;
    
    list<edge> l;
    
    vl v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    // for(edge e:lista(v)){
    //     cout<<"prev : "<<e.prev->value<<" value "<<e.value<<" next : "<<e.next->value<<el;
    // }
    ll lo = 0, hi = 6e18;
    // cout<<check(lista(v), 35)<<el;
    
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        bool can = check(lista(v), mid);
        // cout<<"low "<<lo<<" hi "<<hi<<" mid "<<mid<<endl;
        if(can){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout<<lo<<el;
    // assert(!check(lista(v), lo - 1));
}

/*

*/