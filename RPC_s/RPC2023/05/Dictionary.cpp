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
string yes="yes";
string no="no";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string s;
    cin>>s;
    
    int n = s.size();
    
    map<char,char> m;
    
    string left =  "qwertasdfgzxcvb";
    string right = "yuiophjklnm";
    
    char last;
    
    if(count(all(left), s[0])) last = 'l';
    if(count(all(right), s[0])) last = 'r';
    
    bool can = 1;
    
    for(int i=1;i<n;i++){
        char cur;
        if(count(all(left), s[i])) cur = 'l';
        if(count(all(right), s[i])) cur = 'r';
        
        can &= (cur != last);
        last = cur;
    }
    
    cout<<(can ? yes : no)<<el;

}

/*

*/