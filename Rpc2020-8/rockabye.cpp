#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    fast_io;
	int testcases;
	cin>>testcases;
	while(testcases--){
	    int n,k;
	    cin>>n>>k;
	    vector<pair<string,int>> nombres(n);
	    set<pair<int,int>> ans;
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        int f;
	        cin>>f;
	        ans.insert({f,i});
	        nombres[i].first=s;
	        nombres[i].second=f;
	    }
	    for(int i=0;i<k;i++){
	        auto x=*ans.begin();
	        int t=x.first;
	        int name=x.second;
	        cout<<t<<" "<<nombres[name].first<<endl;
	        ans.erase({t,name});
	        ans.insert({t+nombres[name].second,name});
	    }
	}
}
