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

bool cmp(pii a, pii b){
    if(a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff > b.ff;
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string s;
    cin>>s;
    vi v(26);
    for(char c:s){
        v[c - 'a']++;
    }
    vector<pii> st;
    for(int i=0;i<26;i++){
        if(v[i]){
            st.pb({v[i],i});
        }
    }
    sort(all(st), cmp);
    string ans = "";
    for(pii p:st){
        ans += string(p.ff,'a' + p.ss);
    }
    cout<<ans<<el;
}

/*

*/