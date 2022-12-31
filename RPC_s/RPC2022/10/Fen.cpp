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

ostream& operator<<(ostream& os, const vector<char> &v){
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
    
    string s;
    while(cin>>s){
        
        string new_s = "";
        
        for(char c:s){
            if(c == '/') continue;
            if(isdigit(c)){
                new_s += string(int(c - '0'), '0');
            }else{
                new_s += c;
            }
        }
        
        int idx = 0;
        
        vector<vector<char>> mx(8, vector<char>(8, '0'));
        int n = 8;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mx[i][j] = new_s[idx];
                idx++;
            }
        }
        
        // for(auto vv:mx) cout<<vv;
        
        for(int j=0;j<n;j++){
            for(int i=n - 1;i>=0;i--){
                cout<<mx[i][j];
                if(i) cout<<esp;
            }
            cout<<el;
        }
        cout<<el;
    }
}

/*

*/