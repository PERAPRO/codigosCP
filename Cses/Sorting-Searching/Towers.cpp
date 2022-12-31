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

const int N = 2e5+5;
int n;
vector<vi> g(N);
vi values(N);

int visited(int u, int p){
    int ans  = 1;
    for(int v:g[u]){
        if(v == p) continue;
        ans += visited(v,u);
    }
    return values[u] = ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n;
    multiset<int> s;
    // int towers++;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(s.upper_bound(t) == s.end()){
            s.insert(t);
        }else{
            int level = *s.upper_bound(t);
            s.erase(s.find(level));
            s.insert(t);
        }
    }
    
    cout<<s.size()<<el;
}

/*

*/