// Write by DanielPerez .PERAPRO

#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

ll getSum(ll n){
    ll sum=0;
    for(ll i=1; i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i == i){
                sum+=i;
            }else{
                sum+=i;
                sum+=(n/i);
            }
        }
    }
    sum-=n;
    return sum;
}

int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	while(testcases--){
	    ll k;
	    cin>>k;
	    if(getSum(k)>k) cout<<"abundant\n";
	    else if(getSum(k)<k) cout<<"deficient\n";
	    else cout<<"perfect\n";
	}
}