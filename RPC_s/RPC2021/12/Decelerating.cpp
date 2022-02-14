/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
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

const int N = 3005;
const ll oo = 1e15;

int n;

ll dp[N][N];
ll v[N];

ll go(int idx, int jump){
    if(idx >= n - 1) return v[n - 1];
    if(jump == 0) return -oo;
    ll &ans = dp[idx][jump];
    
    if(ans == -1){
        ans = -oo;
        ckmax(ans, go(idx + jump, jump) + v[idx]);
        ckmax(ans, go(idx, jump - 1));
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    memset(dp, -1, sizeof dp);
    
    cout<<go(0, n)<<el;
}

/*
4 
1 -1 1 1

4
1 1 -1 1
*/