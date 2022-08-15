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

const ll mod = 998244353;

struct evento{
    int x, h1, h2, open;
    evento(){}
    evento(int x, int h1, int h2, int open): x(x), h1(h1), h2(h2), open(open) {}
};

bool cmp(evento a, evento b){
    return a.x < b.x;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    
    int x1,y1,x2,y2;
    
    bool f = 0;
    
    vector<evento> sl;
    
    for(int i=0;i<n;i++){
        
        cin>>x1>>y1>>x2>>y2;
        
        sl.pb(evento(x1, y1, y2, 1));
        sl.pb(evento(x2, y1, y2, 0));
        
    }
    
    set<int> s;
    
    sort(all(sl), cmp);
    
    for(int i=0;i<sl.size();i++){
        
        int open = sl[i].open;
        
        if(!open){
            
            auto it1 = s.upper_bound(sl[i].h1);
            
            if(it1 != s.end())
                f |= *it1 < sl[i].h2;
                
            
            s.erase(sl[i].h1);
            s.erase(sl[i].h2);
        }else{
            
            auto it1 = s.upper_bound(sl[i].h1);
            
            if(it1 != s.end())
                f |= *it1 < sl[i].h2;
                
            s.insert(sl[i].h1);
            s.insert(sl[i].h2);
        }
    }
    
    cout<<f<<el;
}

/*

*/