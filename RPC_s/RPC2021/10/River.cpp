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
string yes = "Tobby puede cruzar";
string no = "Tobby no puede cruzar";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    while(tc--){
        int n=6;
        vi v(6);
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        
        if(sum & 1){
            cout<<no<<el;
            continue;
        }
        
        bool flag = 0;
        
        for(int i=1;i<(1<<n);i++){
            int cur_sum = 0;
            for(int j=0;j<6;j++){
                if((1<<j) & i){
                    cur_sum += v[j];
                }
            }
            if(cur_sum == sum / 2) flag = 1;
        }
        cout<<(flag ? yes : no)<<el;
    }
}

/*

*/