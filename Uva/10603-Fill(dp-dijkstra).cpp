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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int N = 205;
const int oo = 1e9;

struct dp_d{
    int A,B,C;
    int distance;
    
    dp_d(){};
    dp_d(int A,int B,int C, ll distance):A(A),B(B),C(C),distance(distance) {};
    
    bool operator<(const dp_d &e) const{
        return distance > e.distance;
    }
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    while(tc--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        
        //TLE con las tres dimensiones
        vector<vector<int>> distances(N, vector<int>(N, oo));
        
        priority_queue<dp_d> q;
        
        distances[0][0] = 0;
        q.push({0,0,c,0});
        
        pair<int, int> ans;
        
        while(q.size()){
            int A = q.top().A ,B = q.top().B, C = c - (A + B), distance = q.top().distance;
            q.pop();
            if(distance != distances[A][B]) continue;
            
            if((A <= d && A > ans.ff) || (A == ans.ff && distance < ans.ss)) ans = {A, distance};
            if((B <= d && B > ans.ff) || (B == ans.ff && distance < ans.ss)) ans = {B, distance};
            if((C <= d && C > ans.ff) || (C == ans.ff && distance < ans.ss)) ans = {C, distance};
            
            
            //casos
            
            //de a a b y c
            int to_pass = min(A, b-B);
            if(distances[A - to_pass][B + to_pass] > distance + to_pass) {
                distances[A - to_pass][B + to_pass] = distance + to_pass;
                q.push({A - to_pass, B + to_pass, C, distance + to_pass});
            }
            
            to_pass = min(A, c-C);
            if(distances[A - to_pass][B] > distance + to_pass) {
                distances[A - to_pass][B] = distance + to_pass;
                q.push({A - to_pass, B, C + to_pass, distance + to_pass});
            }
            
            //de b a a y c
            to_pass = min(B, a-A);
            if(distances[A + to_pass][B - to_pass] > distance + to_pass) {
                distances[A + to_pass][B - to_pass] = distance + to_pass;
                q.push({A + to_pass, B - to_pass, C, distance + to_pass});
            }
            
            to_pass = min(B, c-C);
            if(distances[A][B - to_pass] > distance + to_pass) {
                distances[A][B - to_pass] = distance + to_pass;
                q.push({A, B - to_pass, C + to_pass, distance + to_pass});
            }
            
            //de c a a y b
            to_pass = min(C, a-A);
            if(distances[A + to_pass][B] > distance + to_pass) {
                distances[A + to_pass][B] = distance + to_pass;
                q.push({A + to_pass, B, C - to_pass, distance + to_pass});
            }
            
            to_pass = min(C, b-B);
            if(distances[A][B + to_pass] > distance + to_pass) {
                distances[A][B + to_pass] = distance + to_pass;
                q.push({A, B + to_pass, C - to_pass, distance + to_pass});
            }
        }
        cout<<ans.ss<<esp<<ans.ff<<el;
    }

}

/*

*/


