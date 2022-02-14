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

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    while(cin>>n){
        //int x,c;
        
        vi v(n), c(n);
        for(int i=0;i<n;i++){
            cin>>v[i]>>c[i];
        }
        pii ans = {0,-1};
        
        vi srt = v;
        sort(all(srt));
        
        for(int i=0;i<n;i++){
            int cubre =  (lower_bound(all(srt), v[i] + c[i]) - srt.begin()) - (upper_bound(all(srt), v[i]) - srt.begin());
            if(cubre > ans.ss){
                ans = {v[i], cubre};
            }
        }
        
        cout<<ans.ff<<esp<<ans.ss<<el;
    }
}

/*

*/