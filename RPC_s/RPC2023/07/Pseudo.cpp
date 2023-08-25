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

int dp[25][3][25];
int n, k;

int go(int idx, int prev, int cur){
    if(idx == n) return 1;
    
    int &ans = dp[idx][prev][cur];
    if(ans == -1){
        ans = 0;
        // if(prev == 2){
        //     ans += go(idx + 1, 1, cur - 1);
        //     // ans += go(idx + 1, 0, k);
            
        //     ans += go(idx + 1, 0, cur - 1);
        //     // ans += go(idx + 1, 1, k);
        // }else{
            
            if(cur){
                if(prev){
                    ans += go(idx + 1, 1, cur - 1);
                    ans += go(idx + 1, 0, k - 1);
                }
                else{
                    ans += go(idx + 1, 0, cur - 1);
                    ans += go(idx + 1, 1, k - 1);
                }
            }else{
                if(prev){
                    ans += go(idx + 1, 0, k - 1);
                }else{
                    ans += go(idx + 1, 1, k - 1);
                }
            }
        // }
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n>>k;
    memset(dp, -1, sizeof dp);
    cout<<go(0, 0, k)<<el;

}

/*

*/