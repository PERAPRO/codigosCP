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

const int oo = 1e9+7;

int n;

bool good(int idx, vi &v){
    int elemento = v[idx - 1];
    int mn = oo;
    int f = 1;
    for(int i = idx;i + 1<n;i++){
        f &= v[i] < v[i + 1];
        ckmin(mn, v[i]);
    }
    ckmin(mn, v[n - 1]);
    
    return mn >= elemento && f;
}

int main(){
	fast_io;
	///*
 	freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    //*/
    //int n;
    cin>>n;
    
    vi v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    vi st(n);
    iota(all(st), 1);
    
    int ans = 0;
    
    while(v != st){
        
        for(int i=0;i + 1<n;i++){
            swap(v[i], v[i + 1]);
            if(good(i + 2, v)) break;
        }
        //cout<<v<<endl;
        ans++;
    }
    
    cout<<ans<<el;
}

/*

*/