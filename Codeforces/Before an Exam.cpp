/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	int d,t;
	cin>>d>>t;
	int m=100000;
	int summ=0;
	vector<pair<int,int>> v(d);
	int sp=0;
	for(int i=0;i<d;i++) {
	    cin>>v[i].first>>v[i].second;
	    sp+=v[i].second;
	    summ+=v[i].first;
	    m=min(m,v[i].first);
	}
	//cout<<summ<<endl;
	if(t>sp || m>t || summ>t){
	    cout<<"NO\n";
	}else{
	    int ans=0;
	    vi aux(d);
	    for(int i=0;i<d;i++){
	        ans+=v[i].first;
	        aux[i]+=v[i].first;
	    }
	    //for (auto p:aux) cout<<p<<" ";
	   // cout<<endl;
	    if (ans<t){
    	    for(int i=0;i<d;i++){
    	        int y=(v[i].second-v[i].first);
    	        if(ans+y <= t){
    	            ans+=(v[i].second-v[i].first);
    	            aux[i]+=(v[i].second-v[i].first);
    	        }else{
                  aux[i]+=t-ans;
    	            ans+=t-ans;
    	        }
    	        //for (auto p:aux) cout<<p<<" ";
    	    }
	    }
	    cout<<"YES\n";
	    for(int i=0;i<d;i++){
	        if(i>0) cout<<" ";
	        cout<<aux[i];
	    }
	    cout<<endl;
	}
}

