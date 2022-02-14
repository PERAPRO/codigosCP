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

const int N=1e6+5;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string from;
    string to;
    cin>>from>>to;
    
    for(int i=0;i<from.size();i++)
        if(from[i] == '/') from[i] = ' ';
        
    for(int i=0;i<to.size();i++)
        if(to[i] == '/') to[i] = ' ';
        
    stringstream from1(from);
    stringstream to1(to);
    
    deque<string> s1;
    deque<string> s2;
    
    string s;
    
    while(from1>>s){
        s1.pb(s);
    }
    
    while(to1>>s){
        s2.pb(s);
    }
    
    deque<string> pref;
    
    while(s1.size() && s2.size() && s1.front() == s2.front()){
        pref.pb(s1.front());
        s1.pop_front();
        s2.pop_front();
    }
    
    deque<string> suf;
    
    while(s1.size() && s2.size() && s1.back() == s2.back()){
        suf.push_front(s1.back());
        s1.pop_back();
        s2.pop_back();
    }
    
    string ans = "";
    
    for(int i=0;i<pref.size();i++){
        //if(i) ans+='/';
        ans += pref[i] + "/";
    }
    
    ans += '{';
    
    for(int i=0;i<s1.size();i++){
        if(i) ans += '/';
        ans+=s1[i];
    }
    
    ans+= " => ";
    
    for(int i=0;i<s2.size();i++){
        if(i) ans += '/';
        ans+=s2[i];
    }
    
    ans += '}'; 
    
    for(int i=0;i<suf.size();i++){
        //if(i) ans += '/';
        ans += "/" + suf[i];
    }
    
    cout<<ans<<el;
    
}

/*

*/