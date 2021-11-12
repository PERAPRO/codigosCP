/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

bool isPrime(int n){
    if(!n || n==1) return false;
    if(n==2) return true;
    for(int j=2;j*j<=n;j++){
        if (n%j==0) return false;
    }
    return true;
}


int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	    ll m,n;
	    cin>>m>>n;
	    for(int i=m;i<=n;i++){
	        if(isPrime(i))
	        cout<<i<<endl;
	    }
	    cout<<endl;
	}
}