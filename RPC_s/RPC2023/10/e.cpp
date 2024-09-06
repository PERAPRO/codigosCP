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

const int oo = 1e9+7, mod = 1e9+7;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */

    int n;
    cin>>n;

    set<vector<pii>> s;

    for(int p = 0;p<n;p++){
        int m;
        cin>>m;
        int x_mn = oo, y_mn = oo;
        vector<pii> cur(m);
        for(int b = 0;b<m;b++){
            int x,y;
            cin>>x>>y;
            ckmin(x_mn, x);
            ckmin(y_mn, y);
            cur[b] = {x,y};
        }

        for(auto&[x,y]:cur){
            x += 0 - x_mn;
            y += 0 - y_mn;
        }
        sort ( cur.begin ( ) , cur.end ( ) ) ;
        s.insert(cur);
    }

    cout<<s.size()<<el;

}

/*

*/
