/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

const int MOD = 1e9+7;

const int N=60;

struct matrix{
    ll m[N][N];
    matrix(bool identity){
        memset(m,0,sizeof m);
        if (identity){
            for(int i=0;i<N;i++) m[i][i]=1;
        }
    }
    matrix operator *(const matrix &o) const{
        matrix res(false);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++)
                    res.m[i][j] += (m[i][k]*o.m[k][j])%MOD;
                    res.m[i][j] %= MOD;
            }
        }
        return res;
    }
};


matrix fexp(matrix base, int exponente){
    matrix ans(true);
    for(;exponente;base = base*base,exponente>>=1){
        if(exponente&1) ans= ans*base;
    }
    return ans;
}


int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	while(testcases--){
	    ll t,e;
	    cin>>t>>e;
	    matrix m(false);
	    for(int i=0;i<t;i++){
	        for(int j=0;j<t;j++){
	            cin>>m.m[i][j];
	        }
	    }
	    matrix ans= fexp(m,e);
	    for(int i=0;i<t;i++){
	        for(int j=0;j<t;j++){
	            cout<<ans.m[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
}