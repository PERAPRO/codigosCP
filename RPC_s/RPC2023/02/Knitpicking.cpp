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

ld pi = 3.14159265358979323846;

string impossible = "impossible";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    map<string,int> types;
    types["left"] = 0;
    types["right"] = 1;
    types["any"] = 2;
    
    int n;
    cin>>n;
    
    map<string, vector<int>> m;
    
    int anys = 0;
    
    for(int i=0;i<n;i++){
        string s, type;
        int cnt;
        cin>>s>>type>>cnt;
        if(types[type] == 2) anys++;
        if(m[s].size() == 0) m[s] = vi(3, 0);
        m[s][types[type]] = cnt;
    }
    
    int ans = 0;
    
    int to_complete = 0;
    
    for(auto [key, value]: m){
        int tmp = max(value[0], value[1]);
        ans += tmp;
        if(!value[0] && !value[1] && value[2]) ans++;
        to_complete |= value[2] >= 2 || (value[0] && value[1]) || (value[2] && (value[0] || value[1]));
    }
    
    if(to_complete)
        cout<<ans + 1<<el;
    else
        cout<<impossible<<el;

}

/*

*/