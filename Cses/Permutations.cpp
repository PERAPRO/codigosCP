#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;



int main(){
	fast_io;
	int n;
	cin>>n;
	if(n<4 && n!=1){
	    cout<<"NO SOLUTION"<<endl;
	}else if(n>=4){
	    vi v;
	    for(int i=2;i<=n;i+=2){
	        v.pb(i);
	    }
	    for (int i=1;i<=n;i+=2){
	        v.pb(i);
	    }
	    for (int i=0;i<v.size()-1;i++){
	        cout<<v[i]<<" ";
	    }
	    cout<<v[v.size()-1]<<endl;
	}
	if(n==1){
	    cout<<1<<endl;
	}
}