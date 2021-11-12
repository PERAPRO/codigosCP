#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;



int main(){
	fast_io;
	ll n;
	cin>>n;
	if(n==1){
	    cout<<n<<endl;
	}else{
	    cout<<n<<" ";
	}
	while(n!=1){
	    if(n%2==0){
	        n/=2;
	        if(n==1){
	            cout<<n<<endl;
	        }else{
	            cout<<n<<" ";
	        }
	    }else{
	        n*=3;
	        n++;
	        if(n==1){
	            cout<<n<<endl;
	        }else{
	            cout<<n<<" ";
	        }
	    }
	}
}