#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> mint;

/// 1000234999, 1000567999, 1000111997, 1000777121
const int MODS[] = { 1001864327, 1001265673 };
const mint BASE(256, 256), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, const int& mod) { return a+b >= mod ? a+b-mod : a+b; } /// (a+b)%mod
inline int sbt(int a, int b, const int& mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int& mod) { return 1ll*a*b%mod; }
inline ll operator ! (const mint a) { return (ll(a.first)<<32)|ll(a.second); } /// long long 64 bits, cada hash es un entero de 32 bits
inline mint operator + (const mint a, const mint b) {
  return {add(a.first, b.first, MODS[0]), add(a.second, b.second, MODS[1])};
}
inline mint operator - (const mint a, const mint b) {
  return {sbt(a.first, b.first, MODS[0]), sbt(a.second, b.second, MODS[1])};
}
inline mint operator * (const mint a, const mint b) {
  return {mul(a.first, b.first, MODS[0]), mul(a.second, b.second, MODS[1])};
}

int main() {

  string t = "aaaaaaab";
  string p = "mun";

  vector<mint> value((int) t.size() + 1);
  value[0] = ZERO;
  for(int i = 0; i < (int) t.size(); ++i) {
    mint cur{t[i], t[i]};
    value[i + 1] = value[i] * BASE + cur;
  }

  vector<mint> base((int) t.size() + 1);
  base[0] = ONE;
  for(int i = 1; i < (int) base.size(); ++i) {
    base[i] = base[i - 1] * BASE;
  }

  function<mint(int i, int j)> get_hash = [&] (int i, int j) {
    return value[j + 1] - value[i] * base[j - i + 1];
  };

  mint target = ZERO;
  for(int i = 0; i < (int) p.size(); ++i) {
    mint cur{p[i], p[i]};
    target = target * BASE + cur;
  }

  set<ll> all;
  for(int i = 0; i + 2 < (int) t.size(); ++i) {
    all.insert(!get_hash(i, i + 2));
  }

  cout << all.size() << endl;

  return 0;
}
