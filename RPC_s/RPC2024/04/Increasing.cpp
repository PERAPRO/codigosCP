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

const int N = 35;
const int nmax = 105;
int n;
// int dp[N][nmax];
int v[N];
// int go(int i, int last){
//     if(i == n) return 0;
    
//     int &ans = dp[i][last];
//     if(ans == -1){
//         ans = 0;
//         ckmax(ans, go(i + 1, last));
//         if(v[i] > last){
//             ckmax(ans, go(i + 1, v[i]) + 1);
//         }
//     }
//     return ans;
    
// }

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    // int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    
    int ans = 0;
    int cur = 1;
    for(int i = 1;i<n;i++){
        if(v[i - 1] < v[i]) cur++;
        else{
            ckmax(ans, cur);
            cur = 1;
        }
    }
    ckmax(ans, cur);
    cout<<ans<<el;
    // memset(dp, -1, sizeof dp);
    // cout<<go(0,0)<<el;
}

/*

*/