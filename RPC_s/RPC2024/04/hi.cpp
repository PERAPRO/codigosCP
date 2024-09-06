// Hi! :)
#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0)
#define precise(ans,k) fixed << setprecision(k) << ans //k digit
#define all(s) s.begin(),s.end()
#define LSOne(x) ((x) & -(x)) //To get the value of the least significant bit of S that is on (first from the right)
#define ss second
#define ff first

using namespace std;

typedef long long ll;
typedef double lf;

const lf PI = acos(-1);
const ll MOD = 1e9+7;

inline ll modFun(ll a, const ll& mod);
ll sqrtFun(ll x);
/***************************************************************/
const ll oo = 1e16+2;
const ll N = 200005;

vector<pair<lf,lf>> vc;

double areaT(pair<lf,lf> a, pair<lf,lf> b, pair<lf,lf> c) {
    auto[x1,y1] = a;
    auto[x2,y2] = b;
    auto[x3,y3] = c;
    return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

// Función para calcular la distancia entre dos puntos
double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Función para calcular el área de un triángulo dado tres puntos
double areaT2(pair<lf,lf> aa, pair<lf,lf> bb, pair<lf,lf> cc) {
    auto[x1,y1] = aa;
    auto[x2,y2] = bb;
    auto[x3,y3] = cc;

    // Calcular las longitudes de los lados del triángulo
    double a = distancia(x1, y1, x2, y2);
    double b = distancia(x2, y2, x3, y3);
    double c = distancia(x3, y3, x1, y1);

    // Calcular el semiperímetro
    double s = (a + b + c) / 2.0;

    // Aplicar la fórmula de Néron para calcular el área
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int n;
pair<lf, lf> memo[(1<<16)];
pair<lf,lf> dp(int mask)
{   
    if(mask == 0) return make_pair(oo, 0.0);
    pair<lf,lf> &r = memo[mask];
    if(r.ff > -1.0 && r.ss > -1.0) return r;
    
    int m = mask;
    vector<int> ones;
    while(m > 0)
    {
        int two_pow_v = LSOne(m);
        int v = __builtin_ctz(two_pow_v);
        m -= two_pow_v;
        ones.push_back(v);
    }

    lf dif = oo;
    for(int i = 0; i < (int)ones.size(); i++)
    {
        for(int j = i+1; j < (int)ones.size(); j++)
        {
            for(int k = j+1; k < (int)ones.size(); k++)
            {   
                lf ar = areaT2(vc[ones[i]], vc[ones[j]], vc[ones[k]]);
                auto[mn,mx] = dp(mask^(1<<ones[i])^(1<<ones[j])^(1<<ones[k]));
                mx = max(mx, ar);
                mn = min(mn, ar);

                if(dif > abs(mx-mn))
                {
                    r = make_pair(mn, mx);  
                    dif = abs(mx-mn);
                }
            }
        }
    }

    return r;
}

int main()
{
    FAST;
    cin >> n;
    for(int i = 0; i < 3*n; i++)
    {
        lf x,y; cin >> x >> y;
        vc.push_back(make_pair(x,y));
    }   

    for(int j = 0; j < (1<<(3*n)); j++) memo[j] = make_pair(-1.0, -1.0);

    auto [mn, mx] = dp((1<<(3*n))-1);
    // cout << mx << " " << mn << '\n';
    lf ans = mx-mn;
    cout << round(ans) << '\n';

    return 0;
}

/***************************************************************/
inline ll modFun(ll a, const ll& mod) 
{
    if(a>=0) return a%mod;
    else 
    {
        ll kmd = (abs(a)+mod-1)/mod;
        return (a+(mod*kmd))%mod;
    }
}
ll sqrtFun(ll x)
{
    ll rx = (x >= 36 ? (ll)sqrt(x)-5: 1); while (rx*rx<x) ++rx;
    return rx;
}

/***************************************************************/
// Author: Sebastián
/***************************************************************/