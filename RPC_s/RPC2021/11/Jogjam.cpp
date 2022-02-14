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

struct pt{
    ld x,y;
    pt(){}
    pt(ld x, ld y): x(x), y(y){}
};

ld distances(pt a, pt b){
    return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    pt a,b,c,d;
    ld ans = 0;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    ckmax(ans,distances(a,b));
    //ckmax(ans,distances(a,d));
    //ckmax(ans,distances(b,c));
    ckmax(ans,distances(c,d));
    cout<<fixed<<setprecision(10)<<ans<<el;
}

/*

*/