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
    // pt(T x, T y):x(x), y(y){}
    pt operator + (pt p) { return {x+p.x, y+p.y}; }
    pt operator - (pt p) { return {x-p.x, y-p.y}; }
    pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
    pt operator * (T d) { return {x*d, y*d}; }
    // pt operator / (lf d) { return {x/d, y/d}; } /// only for floating point
    bool operator == (pt b) { return x == b.x && y == b.y; }
    bool operator != (pt b) { return !(*this == b); }
    bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
    bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};
int cmp (lf a, lf b) { return (a + eps < b ? -1 :(b + eps < a ? 1 : 0)); } //double comparator

// T norm(pt a) { return a.x*a.x + a.y*a.y; }
// lf abs(pt a) { return sqrt(norm(a)); }
// lf arg(pt a) { return atan2(a.y, a.x); }
// pt unit(pt a) { return a/abs(a); }

// T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; } // x = 90 -> cos = 0
// T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; } // x = 180 -> sin = 0
// T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }// clockwise = -
// pt rot(pt p, lf a) { return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)}; }
// pt rotate_to_b(pt a, pt b, lf ang) { return rot(a-b, ang)+b; } // rotate by ang center b
// pt rot90ccw(pt p) { return {-p.y, p.x}; }
// pt rot90cw(pt p) { return {p.y, -p.x}; }
// pt translate(pt p, pt v) { return p+v; }
// pt scale(pt p, double f, pt c) { return c + (p-c)*f; } // c-center

// lf norm ( pt p ) { return hypotl ( p.x, p.y ); }
// lf dis( pt p, pt q ) { return norm( p - q ); }


lf dis(pt p, pt q){
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

// bool half(pt p) { /// true if is in (0, 180] (line is x axis)
//     assert(p.x != 0 || p.y != 0); /// the argument of (0,0) is undefined
//     return p.y > 0 || (p.y == 0 && p.x < 0);
// }
// bool half_from(pt p, pt v = {1, 0}) { //line is v (above v is true)
//     return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);
// }
// bool polar_cmp(const pt &a, const pt &b) {//polar sort
//     return make_tuple(half(a), 0) < make_tuple(half(b), cross(a,b));
// //   return make_tuple(half(a), 0, sq(a)) < make_tuple(half(b), cross(a, b), sq(b)); // further ones appear later
// }

// struct polygon {
//     vector<pt> p;
//     polygon(int n) : p(n) {}
//     int top = -1, bottom = -1;
//     void delete_repetead() {
//         vector<pt> aux;
//         sort(p.begin(), p.end());
//         for(pt &i : p)
//             if(aux.empty() || aux.back() != i)
//               aux.push_back(i);
//         p.swap(aux);
//     }
//     bool is_convex() {
//         bool pos = 0, neg = 0;
//         for (int i = 0, n = p.size(); i < n; i++) {
//             int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
//             if (o > 0) pos = 1;
//             if (o < 0) neg = 1;
//         }
//         return !(pos && neg);
//     }
//     lf area(bool s = false) { // better on clockwise order
//         lf ans = 0;
//         for (int i = 0, n = p.size(); i < n; i++)
//             ans += cross(p[i], p[(i+1)%n]);
//         ans /= 2;
//         return s ? ans : abs(ans);
//     }
// };

lf ans = 1e15;
const int N = 16;
int n, n3;
pt pts[N];

// void solve(int idx, vector<vector<pt>> v){
//     // cout<<"idx : "<<idx<<endl;
    
//     if(idx == 3 * n){
//         //intentar
//         vector<lf> areas;
//         for(int i = 0;i<n;i++){
//             lf s = 0;
//             lf a,b,c;
//             if(v[i].size() != 3) break;
//             // for(int j = 0;j<3;j++){
//             //     s += dis(v[i][j], v[i][(j + 1) % 3]);
//             // }
//             a = dis(v[i][0], v[i][1]);
//             b = dis(v[i][1], v[i][2]);
//             c = dis(v[i][2], v[i][0]);
//             // cout<<a<<esp<<b<<esp<<c<<el;
//             s = a + b + c;
//             s /= 2;
//             areas.pb( sqrt(s * (s - a) * (s - b) * (s - c)) );
//         }
//         sort(all(areas));
//         // cout<<"here2"<<endl;
//         // cout<<areas;
//         ans = min(ans, areas.back() - areas[0]);
//         // cout<<ans<<endl;
//     }
    
//     for(int i = 0;i<n;i++){
//         if(v[i].size() < 3){
//             // cout<<"i : "<<i<<" idx : "<<idx<<el;
//             v[i].pb(pts[idx]);
//             solve(idx + 1, v);
//             v[i].pop_back();
//         }
//     }
// }

void solve2(int idx, set<int> used, vector<lf> areas){
    // cout<<idx<<endl;
    if(idx == n){
        sort(all(areas));
        ans = min(ans, areas.back() - areas[0]);
    }
    for(int i = 0;i<n3;i++){
        if(used.count(i)) continue;
        for(int j = i + 1;j<n3;j++){
            if(used.count(j)) continue;
            for(int k = j + 1 ;k<n3;k++){
                if(used.count(k)) continue;
                used.insert(i);
                used.insert(j);
                used.insert(k);
                lf a,b,c,s;
                a = dis(pts[i], pts[j]);
                b = dis(pts[j], pts[k]);
                c = dis(pts[k], pts[i]);
                s = a + b + c;
                s /= 2;
                areas.pb( sqrt(s * (s - a) * (s - b) * (s - c)) );
                // cout<<areas.back()<<el;
                solve2(idx + 1, used, areas);
                used.erase(i);
                used.erase(j);
                used.erase(k);
                areas.pop_back();
            }
        }
    }
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    // int n;
    cin>>n;
    n3 = 3 * n;
    // vector<pt> pts(n);
    for(int i = 0;i<n3;i++){
        cin>>pts[i].x>>pts[i].y;
    }
    // vector<vector<pt>> v(n);
    solve2(0, set<int>(), vector<lf>());
    cout<<fixed<<setprecision(1)<<ans<<el;
    // cout<<
    // int 3n = 3 * n;
    // for(int i = 0;i<3n;i++){
    //     for(int j = i + 1;i<3n;i++){
    //         for(int k = j + 1;k<3n;k++){
    //             for(int a = 0;a<3n;a++){
    //                 for(int b = a + 1;b<3n;b++){
    //                     for(int c = )
    //                 }
    //             }
    //         }
    //     }
    // }
    
}

/*

*/