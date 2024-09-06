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

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

struct suffixAutomaton {
    struct node {
        int len, link; bool end;
        map<char, int> next;
        int cnt; ll in, out;
    };

    vector<node> sa;
    int last; ll substrs = 0;

    suffixAutomaton() {}
    suffixAutomaton(string &s) {
        sa.reserve(s.size()*2);
        last = add_node();
        sa[0].link = -1;
        sa[0].in = 1;
        for (char &c : s) add_char(c);
        for (int p = last; p; p = sa[p].link) sa[p].end = 1;
    }

    int add_node() { sa.pb({}); return sa.size()-1; }

    void add_char(char c) {
        int u = add_node(), p = last;
        sa[u].len = sa[last].len + 1;
        while (p != -1 && !sa[p].next.count(c)) {
            sa[p].next[c] = u;
            sa[u].in += sa[p].in;
            substrs += sa[p].in;
            p = sa[p].link;
        }
        if (p != -1) {
            int q = sa[p].next[c];
            if (sa[p].len + 1 != sa[q].len) {
                int clone = add_node();
                sa[clone] = sa[q];
                sa[clone].len = sa[p].len + 1;
                sa[clone].in = 0;
                sa[q].link = sa[u].link = clone;
                while (p != -1 && sa[p].next[c] == q) {
                    sa[p].next[c] = clone;
                    sa[q].in -= sa[p].in;
                    sa[clone].in += sa[p].in;
                    p = sa[p].link;
                }
            } else sa[u].link = q;
        }
        last = u;
    }

    void run(string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (u && !sa[u].next.count(s[i])) u = sa[u].link;
            if (sa[u].next.count(s[i])) u = sa[u].next[s[i]];
        }
    }

    int match_str(string &s) {
        int u = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (!sa[u].next.count(s[i])) return 0;
            u = sa[u].next[s[i]];
        }
        return count_occ(u);
    }

    int count_occ(int u) {
        if (sa[u].cnt != 0) return sa[u].cnt;
        sa[u].cnt = sa[u].end;
        for (auto &v : sa[u].next)
            sa[u].cnt += count_occ(v.ss);
        return sa[u].cnt;
    }

    ll count_paths(int u) {
        if (sa[u].out != 0) return sa[u].out;
        for (auto &v : sa[u].next)
            sa[u].out += count_paths(v.ss) + 1;
        return sa[u].out;
    }
    
    node& operator[](int i) { return sa[i]; }
};
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string s;
    cin>>s;
    suffixAutomaton sa(s);
    // ll ans = 0;
    vl dp(2 * s.size());
    function<ll(int, int)> dfs = [&] (int u, int p){
        if(dp[u]) return dp[u];
        ll &ans = dp[u] = 1;
        for(auto v:sa[u].next){
            if(v.ss == p) continue;
            ans += dfs(v.ss, u);
        }
        return ans;
    };
    
    cout<<dfs(0,0) - 1<<el;
}

/*

*/