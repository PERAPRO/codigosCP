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

// const int oo = 1e9+7, mod = 1e9+7;
const ll oo = 1e15; 

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int n;
    cin>>n;
    
    vi pos(n);
    
    set<pii> ranges;
    
    ranges.insert(mp(-oo,0));
    
    map<int,ll> frogs;
    
    for(int i = 0;i<n;i++){
        cin>>pos[i];
        frogs[i + 1] = pos[i];
        if(i && pos[i - 1] + 1 != pos[i]){
            ranges.insert(mp(pos[i - 1] + 1, pos[i] - 1));
        }
    }
    
    ranges.insert( mp( pos.back() + 1, oo) );
    
    
    int q;
    cin>>q;
    for(int b = 0;b<q;b++){
        int frog;
        cin>>frog;
        auto it = ranges.lower_bound( mp(frogs[frog], 0) );
        auto[left, right] = *it;
        
        it--;
        auto[left_prev, right_prev] = *it;
        ranges.erase(mp(left, right));
        ranges.erase(mp(left_prev, right_prev));
        if(right_prev + 1 == frogs[frog]){ // unir rango con la posicion de mi rana
            ranges.insert(mp(left_prev, frogs[frog]));
        }else{
            ranges.insert(mp(left_prev, right_prev));
            ranges.insert(mp(frogs[frog], frogs[frog]));
        }
        if(left + 1 <= right){ // tengo un rango valido adelante
            ranges.insert(mp(left + 1, right));
        }
        frogs[frog] = left;
        cout<<left<<el;
    }

}

/*
2
2
0 2
1 1
2
0 1
1 0
*/