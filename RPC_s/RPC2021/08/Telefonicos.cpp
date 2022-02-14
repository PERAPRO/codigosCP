/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
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

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    vector<string> v(n);
    
    for(string &e:v) cin>>e;
    sort(v.begin(),v.end());
    
    map<string,int> m;
    
    for(string &s:v){
        int sz=s.size();
        string cur="";
        for(int i=0;i<sz-1;i++){
            cur+=s[i];
            if(m.count(cur)){
                m[cur]++;
            }
        }
        m[s]=0;
    }
    ll ans=0;
    for(auto [key,value]:m){
        ans+= 0LL + value;
    }
    cout<<ans<<el;
}

/*

*/