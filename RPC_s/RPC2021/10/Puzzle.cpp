#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const char el = '\n';
/// Complexity: O(|N|*log(|N|))
/// Tested: https://tinyurl.com/y8g2q66b
namespace fft {
  typedef long long ll;
  const double PI = acos(-1.0);
  vector<int> rev;
  struct pt {
    double r, i;
    pt(double r = 0.0, double i = 0.0) : r(r), i(i) {}
    pt operator + (const pt & b) { return pt(r + b.r, i + b.i); }
    pt operator - (const pt & b) { return pt(r - b.r, i - b.i); }
    pt operator * (const pt & b) { return pt(r * b.r - i * b.i, r * b.i + i * b.r); }
  };
  void fft(vector<pt> &y, int on) {
    int n = y.size();
    for(int i = 1; i < n; i++) if(i < rev[i]) swap(y[i], y[rev[i]]);
    for(int m = 2; m <= n; m <<= 1) {
      pt wm(cos(-on * 2 * PI / m), sin(-on * 2 * PI / m));
      for(int k = 0; k < n; k += m) {
        pt w(1, 0);
        for(int j = 0; j < m / 2; j++) {
          pt u = y[k + j];
          pt t = w * y[k + j + m / 2];
          y[k + j] = u + t;
          y[k + j + m / 2] = u - t;
          w = w * wm;
        }
      }
    }
    if(on == -1)
      for(int i = 0; i < n; i++) y[i].r /= n;
  }
  vector<ll> mul(vector<ll> &a, vector<ll> &b) {
    int n = 1, la = a.size(), lb = b.size(), t;
    for(n = 1, t = 0; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
    vector<pt> x1(n), x2(n);
    rev.assign(n, 0);
    for(int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 |(i & 1 ? t : 0);
    for(int i = 0; i < la; i++) x1[i] = pt(a[i], 0);
    for(int i = 0; i < lb; i++) x2[i] = pt(b[i], 0);
    fft(x1, 1); fft(x2, 1);
    for(int i = 0; i < n; i++) x1[i] = x1[i] * x2[i];
    fft(x1, -1);
    vector<ll> sol(n);
    for(int i = 0; i < n; i++) sol[i] = x1[i].r + 0.5;
    return sol;
  }
}

int main(){
    fast_io;
    int d,k;
    while(cin>>d>>k){
        if(!d && !k) break;
        
        vector<char> digits(10);
        digits[0] = '0';
        for(int i=1;i<=9;i++){
            digits[i] = digits[i - 1] + 1;
        }
        //for(char c:digits) cout<<c<<" ";
        
        vector<long long> a(k,d);
        vector<long long> b(k,d);
        vector<long long> prod = fft::mul(a,b);
        long long carry = 0;
        carry = 0;
        for (int i = 0; i < prod.size(); i++){
            prod[i] += carry;
            carry = prod[i] / 10;
            prod[i] %= 10;
        }
        int ans = 0;
        for(int i:prod) ans+=i;
        cout<<ans<<el;
    }
}