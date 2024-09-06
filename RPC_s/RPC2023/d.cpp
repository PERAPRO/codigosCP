#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using bigint = __int128;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int n, r; cin >> n >> r;
    vector<bigint> a(2*n);
    for(int i=0; i<r; i++) {
        for(int j=0; j<2*n; j++) {
            int aij; cin >> aij;
            if (aij>n) a[j] += (bigint(1) << i);
        }
    }
    multiset<bigint> in;
    for(int i=0; i<2*n; i++) {
        bigint want = a[i] ^ ((bigint(1) << r)-1);
        if (in.count(want)) in.erase(in.find(want));
        else in.insert(a[i]);
    }
    if (in.size()) cout << "impossible" << endl;
    else cout << "possible" << endl;
    return 0;
}
