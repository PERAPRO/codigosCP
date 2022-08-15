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

/// Complexity: O(|text|+SUM(|pattern_i|)+matches)
/// Tested: https://tinyurl.com/y2zq594p

const int N = 1e6 + 500;

const int alpha = 123;

int trie[N][alpha], fail[N], nodes, end_word[N];

void add(string &s, int i) {
  int cur = 0;
  for(int c : s) {
    int x = c;
    if(!trie[cur][x]) trie[cur][x] = ++nodes;
    cur = trie[cur][x];
  }
  //cnt_word[cur]++;
  end_word[cur] = i; // for i > 0
}
void build() {
  queue<int> q; q.push(0);
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int i = 0; i < alpha; ++i) {
      int v = trie[u][i];
      if(!v) trie[u][i] = trie[ fail[u] ][i]; // construir automata
      else q.push(v);
      if(!u || !v) continue;
      fail[v] = trie[ fail[u] ][i];
      //fail_out[v] = end_word[ fail[v] ] ? fail[v] : fail_out[ fail[v] ];
      //cnt_word[v] += cnt_word[ fail[v] ]; // obtener informacion del fail_padre
    }
  }
}

int main(){
	fast_io;
	///*
 	freopen("censor.in", "r" ,stdin);
    freopen("censor.out", "w", stdout);
    //*/
    string s;
    cin>>s;
    
    string p;
    cin>>p;
    
    add(p, 1);
    
    build();
    
    stack<int> st;
    
    st.push(0);

    string ans = "";
    
    for(int c:s){
        int cur = st.top();
        cur = trie[cur][c];
        
        st.push(cur);
        ans.pb(c);
        
        if(end_word[cur]){
            for(int k:p) st.pop(), ans.pop_back();
        }
    }
    
    cout<<ans<<el;
    
}

/*

*/