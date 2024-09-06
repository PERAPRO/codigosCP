#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const int MOD = 1e9+7;
struct matrix{
    int m[N][N];
    matrix(bool identity){
        memset(m,0,sizeof m);
        if(identity){
            for(int i=0; i<N; i++)m[i][i]=1;
        }
    }

    matrix operator * (const matrix &o) const{
        matrix res(false);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    res.m[i][j] += (m[i][k]*o.m[k][j])%MOD;
                    res.m[i][j]%=MOD;
                }
            }
        }
	return res;
    }
};

matrix fpow(matrix base, int exp){
    matrix res(true);
    for(;exp;base=base*base,exp>>=1){
        if(exp&1)res = res*base;
    }
    return res;
}
int main(){
    int cases;cin>>cases;
    while(cases--){
        matrix vec(false);
        matrix magic(false);
        int n;cin>>n;
        vec.m[0][0] = 0;vec.m[0][1] = 1; vec.m[0][2] = 2;vec.m[0][3] = 1;
        magic.m[0][0]=0; magic.m[0][1]=-1; magic.m[0][2]=0; magic.m[0][3]=0;
        magic.m[1][0]=1; magic.m[1][1]=3; magic.m[1][2]=0; magic.m[1][3]=0;
        magic.m[2][0]=0; magic.m[2][1]=1; magic.m[2][2]=1; magic.m[2][3]=0;
        magic.m[3][0]=0; magic.m[3][1]=0; magic.m[3][2]=1; magic.m[3][3]=1;
        if(n>=2){
            matrix ans = vec * fpow(magic,n-2);
            cout<<ans.m[0][1]<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
  return 0;
}





