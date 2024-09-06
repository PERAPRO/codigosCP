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

typedef double lf;
const lf eps = 1e-9;
typedef ll T;
struct pt {
    T x, y;
    pt operator + (pt p) { return {x+p.x, y+p.y}; }
    pt operator - (pt p) { return {x-p.x, y-p.y}; }
    pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
    pt operator * (T d) { return {x*d, y*d}; }
    pt operator / (lf d) { return {x/d, y/d}; } /// only for floating point
    bool operator == (pt b) { return x == b.x && y == b.y; }
    bool operator != (pt b) { return !(*this == b); }
    bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
    bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};
int cmp (lf a, lf b) { return (a + eps < b ? -1 :(b + eps < a ? 1 : 0)); } //double comparator

T norm(pt a) { return a.x*a.x + a.y*a.y; }
lf abs(pt a) { return sqrt(norm(a)); }
lf arg(pt a) { return atan2(a.y, a.x); }
pt unit(pt a) { return a/abs(a); }

T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; } // x = 90 -> cos = 0
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; } // x = 180 -> sin = 0
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }// clockwise = -
pt rot(pt p, lf a) { return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)}; }
pt rotate_to_b(pt a, pt b, lf ang) { return rot(a-b, ang)+b; } // rotate by ang center b
pt rot90ccw(pt p) { return {-p.y, p.x}; }
pt rot90cw(pt p) { return {p.y, -p.x}; }
pt translate(pt p, pt v) { return p+v; }
pt scale(pt p, double f, pt c) { return c + (p-c)*f; } // c-center

bool half(pt p) { /// true if is in (0, 180] (line is x axis)
    assert(p.x != 0 || p.y != 0); /// the argument of (0,0) is undefined
    return p.y > 0 || (p.y == 0 && p.x < 0);
}
bool half_from(pt p, pt v = {1, 0}) { //line is v (above v is true)
    return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);
}
bool polar_cmp(const pt &a, const pt &b) {//polar sort
    return make_tuple(half(a), 0) < make_tuple(half(b), cross(a,b));
//   return make_tuple(half(a), 0, sq(a)) < make_tuple(half(b), cross(a, b), sq(b)); // further ones appear later
}

struct polygon {
    vector<pt> p;
    polygon(int n) : p(n) {}
    int top = -1, bottom = -1;
    void delete_repetead() {
        vector<pt> aux;
        sort(p.begin(), p.end());
        for(pt &i : p)
            if(aux.empty() || aux.back() != i)
              aux.push_back(i);
        p.swap(aux);
    }
    bool is_convex() {
        bool pos = 0, neg = 0;
        for (int i = 0, n = p.size(); i < n; i++) {
            int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
            if (o > 0) pos = 1;
            if (o < 0) neg = 1;
        }
        return !(pos && neg);
    }
    lf area(bool s = false) { // better on clockwise order
        lf ans = 0;
        for (int i = 0, n = p.size(); i < n; i++)
            ans += cross(p[i], p[(i+1)%n]);
        ans /= 2;
        return s ? ans : abs(ans);
    }
};


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    
    vector<pt> pts(n);
    for(int i = 0;i<n;i++){
        cin>>pts[i].x>>pts[i].y;
    }
    
    double ans = 1e15;
    
    for(int i = 0;i<n;i++){
        for(int j = i + 1;j<n;j++){
            
            vector<pt> pol_a;
            vector<pt> pol_b;
            
            // pol_a.pb(pts[i]);
            // pol_a.pb(pts[j]);
            
            // pol_b.pb(pts[i]);
            // pol_b.pb(pts[j]);
            
            for(int k = i;k<=j;k++){
                // if(k == i || k == j) continue;
                // ll ori = orient(pts[i], pts[j], pts[k]);
                // if(ori >= 0) pol_a.pb(pts[k]);
                // else pol_b.pb(pts[k]);
                pol_a.pb(pts[k]);
            }
            for(int k = j;k<n;k++){
                // if(k == i || k == j) continue;
                // ll ori = orient(pts[i], pts[j], pts[k]);
                // if(ori >= 0) pol_a.pb(pts[k]);
                // else pol_b.pb(pts[k]);
                pol_b.pb(pts[k]);
            }
            for(int k = 0;k<=i;k++){
                // if(k == i || k == j) continue;
                // ll ori = orient(pts[i], pts[j], pts[k]);
                // if(ori >= 0) pol_a.pb(pts[k]);
                // else pol_b.pb(pts[k]);
                pol_b.pb(pts[k]);
            }
            int sz_a = pol_a.size();
            int sz_b = pol_b.size();
            
            if(sz_a == 2 || sz_b == 2) continue;
            // sort(all(pol_a));
            // sort(all(pol_b));
            
            polygon poly_a(sz_a);
            polygon poly_b(sz_b);
            
            poly_a.p = pol_a;
            poly_b.p = pol_b;
            
            lf area_a = poly_a.area();
            lf area_b = poly_b.area();
            // cout<<"Area a "<<area_a<<esp<<"Area b "<<area_b<<el;
            ans = min(ans, abs(area_a - area_b));
        }
    }
    cout<<fixed<<setprecision(1)<<ans<<el;
}

/*

*/