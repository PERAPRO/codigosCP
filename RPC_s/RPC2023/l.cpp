#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int maxn = 1e6+10;
int f[maxn], s[maxn], depth[maxn], leaf[maxn], par[maxn], cnt[maxn];
bool leaves[maxn];
int find(int n) { return f[n] = (f[n] == n) ? n : find(f[n]); }
int merge(int a, int b) {
    a=find(a), b=find(b);
    if (a==b) return leaf[a];
    if (s[a]<s[b]) swap(a, b);
    s[a] += s[b];
    if (depth[leaf[a]] < depth[leaf[b]]) leaf[a]=leaf[b];
    f[b]=a;
    return leaf[a];
}

unordered_set<int> tree[maxn];
void dfs(int u, int p) {
    vector<int> c;
    for(auto& v : tree[u]) {
        if (v == p) continue;
        depth[v]=depth[u]+1;
        c.push_back(v);
        par[v]=u;
        dfs(v, u);
    }
    if (c.size()==1) merge(u, c[0]);
    else if (c.empty()) leaves[u]=1;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int n, k; cin >> n >> k;
    for(int i=0; i<n; i++) f[i]=i, leaf[i]=i, s[i]=1;
    for(int i=1; i<n; i++) {
        int pi; cin >> pi;
        tree[i].insert(pi);
        tree[pi].insert(i);
    }

    dfs(0, 0);
    set <pii> in;
    for(int i=0; i<n; i++) {
        if (i) tree[i].erase(par[i]);
        if (leaves[i]) {
            in.insert({s[find(i)], i});
            cnt[i]=s[find(i)];
        }
    }

    while (k) {
        pii best = *in.begin();
        int u=best.second, m=best.first;
        //cout << u << ' ' << m << ' ' << k << endl;
        if (m>k) break;

        in.erase(in.begin());
        k -= m;

        while (find(par[u]) == find(u) && par[u]!=0 ) {
            tree[par[u]].erase(u);
            u=par[u];
        }
        tree[par[u]].erase(u);
        u=par[u];

        if (tree[u].size() == 1) {
            merge(u, *tree[u].begin());
            int w = find(u);
            //cout << "new: " << u << endl;
            if (leaves[leaf[w]]) {
                in.erase({cnt[leaf[w]], leaf[w]});
                cnt[leaf[w]] = s[w];
                in.insert({cnt[leaf[w]], leaf[w]});
            }
        } else if (tree[u].empty()) {
            leaves[u]=1;
            cnt[u]=s[find(u)];
            in.insert({cnt[u], u});
        }
    }

    cout<<in.size() << endl;
    return 0;
}
