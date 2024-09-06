//g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL main.cpp -o main && ./main < in.txt
#include <bits/stdc++.h>
using namespace std;

void _print() { cerr << "]" << endl; }
template<typename T, typename... V>
void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifdef LOCAL
    #define dbg(x...) cerr << "[" << #x << "]: ["; _print(x)
#else
    #define dbg(x...)
    #define endl '\n'
#endif

typedef long long ll;
typedef pair<int, int> ii;
#define pb push_back
#define ff first
#define ss second
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b ; ++i)
#define rforn(i, n) for (int i = n; i >= 0; --i)
#define form(i, n, m, x) for (int i = n; i < m; i += x)
#define rform(i, n, m, x) for (int i = n; i >= m; i -= x)

struct suffixAutomaton{
    struct node{
        int len, link;
        map<char, int> next;
    };
    vector<node> sa;
    int last;
    suffixAutomaton(int n){
        sa.reserve(n * 2);
        last = add_node();
        sa[0].link = -1;
    }
    int add_node(){
        sa.pb({});
        return sz(sa) - 1;
    }
    int add_char(char c){
        int u = add_node(), p = last;
        sa[u].len = sa[last].len + 1;
        while(p != -1 && !sa[p].next.count(c)){
            sa[p].next[c] = u;
            p = sa[p].link;
        }
        if(p != -1){
            int q = sa[p].next[c];
            if(sa[p].len + 1 != sa[q].len){
                int clone = add_node();
                sa[clone] = sa[q];
                sa[clone].len = sa[p].len + 1;
                sa[q].link = sa[u].link = clone;
                while(p != -1 && sa[p].next[c] == q){
                    sa[p].next[c] = clone;
                    p = sa[p].link;
                }
            }else sa[u].link = q;
        }
        return last = u;
    }
    node& operator[](int i){return sa[i];}
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    int n = sz(s);
    suffixAutomaton sfa(n);
    vector<int> ans(n, 0);
    forn(i, n){
        int u = sfa.add_char(s[i]);
        // cout << u << " " << sfa[sfa[u].link].len << endl;
        if(u != 1){ 
            int a = sfa[sfa[u].link].len;
            if(a) ans[i] = min(ans[i - 1] + 1, ans[i - a] + 3); //Hay un estado que me permite comprimir.
            else ans[i] = ans[i - 1] + 1; //Soy el sufijo mas largo o no habia una ruta hacia mi ultima letra.
        }else ans[u - 1] = 1; //La primera letra del arbol
    }
    cout << ans[n - 1] << endl;
    return 0;
}