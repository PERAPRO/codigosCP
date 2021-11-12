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
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ostream& operator<<(ostream& os, const vector<ll> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int N = 2e5+5;
const int LOG2 = 32; 

int lca[N][LOG2];


int solve(int from, int jumps){
    int ans = from;
    for(int i=0;jumps;jumps >>= 1, i++){
        if(jumps & 1){
            ans = lca[ans][i];
        }
    }
    
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q,child;
    cin>>n>>q;
    
    for(int i=0;i<n;i++){
        cin>>child;
        lca[i][0] = child - 1;
    }
    
    for(int j=0;j + 1< LOG2;j++){
        for(int i=0;i<n;i++){
            lca[i][j + 1] = lca[ lca[i][j] ][j];
        }
    }
    
    while(q--){
        int from,jumps;
        cin>>from>>jumps;
        from--;
        cout<<solve(from, jumps) + 1<<el;
    }
    
}

/*

*/