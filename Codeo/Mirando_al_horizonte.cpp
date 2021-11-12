/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	int t=testcases;
	while(testcases--){
	    cout<<"Case #"<<abs(t-testcases)<<":";
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++) cin>>a[i];
	    vector<int> ans(n);
	    for(int i=n-1;i>-1;i--){
	        ans[i]=i+1;
	        if(i!=n-1 && a[ans[i]]<=a[i]){
	            while(ans[i]<n && a[ans[i]]<=a[i]){
	                ans[i]=ans[ans[i]];
	            }
	        }
	    }
	    //for(auto x:ans) cout<<" "<<x;
	    //cout<<endl;
	    for(int i=0;i<n;i++){
	        if(ans[i]>=n) cout<<" "<<-1;
	        else cout<<" "<<a[ans[i]];
	    }
	    cout<<endl;
	}
}