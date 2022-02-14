#include<bits/stdc++.h>

using namespace std;
char el='\n';
int main(){
    int n; cin>>n;
    vector<vector<int>> a;
    for (int i =0; i < 3; i ++){
    	vector<int> k;
    	for (int j = 0; j < n; j++){
    	    int c; cin>>c;k.push_back(c);
    	}
    	a.push_back(k);
    }
    vector<int> ans;
    for (int j = 0; j < n; j++){
    	vector<int> b;
    	for (int i = 0; i < 3; i++){
    	    b.push_back(a[i][j]);
    	}
    	sort(b.begin(), b.end());
    	ans.push_back(b[1]);
    	//cout<<b[1]<<' ';
    }
    cout<<ans[0];
    for(int i=1;i<n;i++){
        cout<<" "<<ans[i];
    }
    cout<<'\n';
}
