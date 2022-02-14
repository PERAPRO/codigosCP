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

int fexp(int a, int b){
    int ans = 1;
    for(;b;a=a*a,b>>=1){
        if(b&1)
            ans = ans * a;
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    int sz = fexp(3,n);
    vector<vector<char>> mx(sz, vector<char>(sz, ' '));
    
    function<void(pii, pii)> solve = [&] (pii top_left, pii bottom_right){
        if(top_left == bottom_right){
            mx[top_left.ff][top_left.ss] = '#';
            return;
        }
        int q = (bottom_right.ff - top_left.ff + 1) / 3;
        solve(top_left, mp(top_left.ff + q - 1, top_left.ss + q - 1)); // sup izq
        solve(mp(top_left.ff + q + q, top_left.ss), mp(bottom_right.ff, bottom_right.ss - q - q)); //sup der
        solve(mp(top_left.ff + q, top_left.ss + q), mp(bottom_right.ff - q, bottom_right.ss - q));//Centro
        solve(mp(top_left.ff, top_left.ss + q + q), mp(bottom_right.ff - q - q, bottom_right.ss)); //inf izq
        solve(mp(bottom_right.ff - q + 1, bottom_right.ss - q + 1), bottom_right);
    };
    
    solve(mp(0,0), mp(sz - 1, sz - 1));
    
    for(vector<char> &vc:mx){
        for(char c:vc){
            cout<<c;
        }
        cout<<el;
    }
}

/*

*/