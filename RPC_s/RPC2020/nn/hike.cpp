#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	int days;
	cin>>days;
	vi temperaturas;
	for(int i=0;i<days;i++){
        int k;
        cin>>k;
        temperaturas.pb(k);
	}
	vi arrays (days-1,0);
	for(int i=0;i<days-2;i++){
        arrays[i+1]=max(temperaturas[i],temperaturas[i+2]);
	}
	int ans =arrays[1];
	int daysol=1;
	for(int i=1;i<days-1;i++){
        if(arrays[i]<ans){
            ans=arrays[i];
            daysol=i;
        }
	}
	cout<<daysol<<" "<<ans<<"\n";
}
