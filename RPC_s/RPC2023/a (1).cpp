#include <bits/stdc++.h>
using namespace std;
using bigint = __int128;
using ll = long long;
const bigint oo = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int tt; cin >> tt;
    while (tt--) {
        ll N, D; cin >> N >> D;
        if (N==1) { cout << 0 << endl; continue; }
        bigint n = N, d = D;
        ll lo = 1, hi = 64;
        while (lo<hi) {
            ll mid = lo+(hi-lo)/2;
            bigint best = 1;
            for(int i=0; i<mid; i++) {
                best = min(oo, best*(d+1));
            }
            if (best>=n) hi=mid;
            else lo=mid+1;
        }
        cout << lo << endl;
    }
    return 0;
}
