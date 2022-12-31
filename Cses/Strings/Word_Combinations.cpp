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
 
const ll oo = 1e18;
 
const int mod = 1e9+7;
 
const int N = 2e6 + 5;
 
int trie[N][26];
int finish[N];
int node = 1;
 
void add(string &s){
    int cur = 0;
    for(char c:s){
        if(!trie[cur][c - 'a']) trie[cur][c - 'a'] = node++;
        cur = trie[cur][c - 'a'];
    }
    finish[cur] = 1;
}
 
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    string s;
    cin>>s;
    
    int n = s.size();
    
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        string ss;
        cin>>ss;
        add(ss);
    }
    
    vi dp(n);
    // cout<<trie[0][0]<<el;
    
    int cur = 0;
    
    // for(int i=0;i<n;i++){
    //     if(!trie[cur][s[i] - 'a']) break;
    //     cur = trie[cur][s[i] - 'a'];
    //     if(finish[cur]) dp[0]++; 
    // }
    
    
    for(int i=0;i<n;i++){
        cur = 0;
        for(int j=i;j<n;j++){
            if(!trie[cur][s[j] - 'a']) break;
            cur = trie[cur][s[j] - 'a'];
            if(finish[cur]) dp[j] = (dp[j] + (i ? dp[i - 1] : 1)) % mod; 
        }
    }
    // cout<<dp;
    
    cout<<dp[n - 1]<<el;
}
 
/*
 
*/