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
string no="NO SOLUTION";

const int oo = 1e9+7;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string s;
    cin>>s;
    int n = s.size();
    map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    deque<char> ans;
    int imp = 0;
    string centro = "";
    for(auto[key,value]:m){
        if(value & 1){
            imp++;
            centro = key;
        }
    }
    
    if(((n & 1) && (imp != 1)) || (n % 2 == 0 && imp)){
        cout<<no<<el;
        return 0;
    }
    //cout<<"hol" + centro + "a"<<el;
    if(imp) ans.pb(centro[0]);
    
    for(auto[key,value]:m){
        if(key == centro[0]) value--;
        for(;value;value-=2)
            ans.pb(key), ans.push_front(key);
    }
    for(char c:ans)cout<<c;
    cout<<el;
}

/*

*/