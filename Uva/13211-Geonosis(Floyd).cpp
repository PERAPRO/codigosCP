/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<ll,ll>;
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

const ll oo=1e15;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<vl> m(n, vl(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        vi order(n);
        for(int i=0;i<n;i++) cin>>order[i];
        ll ans=0;
        reverse(order.begin(), order.end());
        
        vector<vl> distances = m;
        vector<bool> visited(n);
        
        for(int k=0;k<n;k++){
            int inter=order[k];
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    distances[i][j]= min(distances[i][j], distances[i][inter] + distances[inter][j]);
                }
            }
            
            visited[inter]=1;
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(! visited[i] || !visited[j]) continue;
                    ans += distances[i][j];
                }
            }
        }
        cout<<ans<<el;
            
    }
}

/*
3
3
0 35 58
12 0 5
1 2 0
0 1 2
3
0 9982 1413
8327 0 5612
3577 7893 0
1 0 2
4
0 50 10 30
4 0 23 58
2 1 0 5
67 24 25 0
0 3 1 2

96
41118
287
*/