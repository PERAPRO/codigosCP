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

const int maxn=50005, l2=16;

struct spT{
    int _A[maxn], sT[maxn][l2];
    spT(int n,vector<int> a){
        for(int i=0;i<n;i++){
            _A[i]=a[i];
            sT[i][0]=i;
        }
        for(int j=1;(1<<j)<=n;j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                if(_A[sT[i][j-1]]>_A[sT[i+(1<<(j-1))][j-1]])
                    sT[i][j]=sT[i][j-1];
                else
                    sT[i][j]=sT[i+(1<<(j-1))][j-1];
            }
        }
    }
    int query(int i, int j){
        int k=log2(j-i+1);
        if(_A[sT[i][k]]>=_A[sT[j-(1<<k)+1][k]])
            return sT[i][k];
        else
            return sT[j-(1<<k)+1][k];
    }
};

int main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vi v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	spT table(n,v);
	int ans=0;
	/*
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++)
	        cout<<table.sT[i][j]<<" ";
	   cout<<el;
	}*/
	while(m--){
	    int a,b;
	    cin>>a>>b;
	    if(b==a+1 || a==b+1 || b==a){
	        ans++;
	        continue;
	    }
	    int ma,i;
	    if(b<a){
	        swap(a,b);
	        i=table.query(a,b-2);
	        ma=v[i];
	        if(ma<=v[b-1]) ans++;
	        continue;
	    }
	    i=table.query(a,b-2);
	    ma=v[i];
	    //cout<<v[table.query(0,3)]<<endl;
	    //cout<<"a,b= "<<a<<" "<<b-2<<" ma = "<<ma<<" i = "<<i<<el;
	    if(ma<=v[a-1]) ans++;
	}
	cout<<ans<<el;
}