/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;


const int N=2;
const int MOD =1e9+7;


struct matrix{
    ll m[N][N];
    matrix(bool identity){
        memset(m,0,sizeof m);
        if(identity){
            for( int i=0;i<N;i++)
                m[i][i]=1;
        }
    }
    matrix operator*(const matrix &o) const{
        matrix res(false);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for (int k=0;k<N;k++){
                    res.m[i][j] += (m[i][k]*o.m[k][j])%MOD;
                    res.m[i][j] %= MOD;
                }
            }
        }
        return  res;
    }
};


matrix fexp(matrix base,int expo){
    matrix ans(true);
    for(;expo;base=base*base,expo>>=1){
        if(expo&1){
            ans = ans* base;
        }
    }
    return ans;
}

int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	while(testcases--){
	    int a,b,n;
	    cin>>a>>b>>n;
	    matrix m(false);
	    m.m[0][0] = 0;
	    m.m[0][1] = 1;
	    m.m[1][0] = 1;
	    m.m[1][1] = 1;
	    matrix aux= fexp(m,n-1);
	    matrix inicio(false);
	    inicio.m[0][0]=a;
	    inicio.m[0][1]=b;
	    matrix ans= inicio*aux;
	    cout<<ans.m[0][1]<<endl;
	}
}