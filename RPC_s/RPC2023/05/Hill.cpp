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

ll ans = 0, n;

vl v;

void check(int i){
    int l = i - 1, r = i + 1;
    
    while(l >= 0 && v[l] < v[l + 1]){
        l--;
    }
    while(r < n && v[r] < v[r - 1]){
        r++;
    }
    cout<<i<<esp<<l<<esp<<r<<el;
    ckmax(ans, min(v[i] - v[l + 1], v[i] - v[r - 1]));
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    // int n;
    cin>>n;
    
    v.assign(n, 0);
    
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    
    for(int i = 1;i<n - 1;i++){
        if(v[i - 1] < v[i] && v[i + 1] < v[i]){
            check(i);
        }
    }
    cout<<ans<<el;
}

/*

*/