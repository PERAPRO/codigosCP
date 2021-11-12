/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
using pii=pair<int,int>;
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
char el = '\n';

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
const int maxn=100005;
const int l2=17;
struct spT{
    int _A[maxn],sT[maxn][l2];
    spT(int n,vector<int> a){
        for(int i=0;i<n;i++){
            _A[i]=a[i];
            sT[i][0]=i;
        }
        for(int j=1;(1<<j)<=n;j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                if(_A[sT[i][j-1]]<_A[sT[i+(1<<(j-1))][j-1]])
                    sT[i][j]=sT[i][j-1];
                else
                    sT[i][j]=sT[i+(1<<(j-1))][j-1];
            }
        }
    }
    int query(int i,int j){
        int k=log2(j-i+1);
        //cout<<k<<endl;
        if(_A[sT[i][k]]<=_A[sT[j-(1<<k)+1][k]])
            return sT[i][k];
        else
            return sT[j-(1<<k)+1][k];
    }
};

int main(){
	fast_io;
	int n;cin>>n;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	//cout<<a;
	spT table(n,a);/*
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        cout<<table.sT[i][j]<<el;*/
	int q;
	cin>>q;
	while(q--){
	    int i,j; cin>>i>>j;
	    cout<<a[table.query(i,j)]<<el;
	}
	//cout<<log2(100005);
}