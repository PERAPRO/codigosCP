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
string yes="YES";
string no="NO";

int main(){
	fast_io;
	int n,p;
	cin>>n>>p;
	vi v(n);
	for(auto &e:v) cin>>e;
	vi ans1;
	int aux1=p;
	for(int i=0;i<n-1;i++){
	    if(v[i+1]<v[i]){
	        ans1.pb(aux1--);
	    }else{
	        ans1.pb(aux1);
	    }
	    if(v[i]==0) aux1=0;
	}
	ans1.pb(aux1);
	vi ans2;
	int aux2=0;
	for(int i=n-1;i>0;i--){
	    if(v[i-1]>v[i]){
	        ans2.pb(aux2++);
	    }else{
	        ans2.pb(aux2);
	    }
	}
	ans2.pb(aux2);
	reverse(ans2.begin(),ans2.end());
	//cout<<ans1<<ans2;
	if(ans1==ans2){
	    for(auto e:ans1) cout<<e<<el;
	}else{
	    int diferentes=0;
	    for(int i=0;i<n-1;i++){
	        if(v[i]!=v[i+1])
	            diferentes++;
	    }
	    if(diferentes==0){//Todos son iguales
	        if(p>1){
	            cout<<"ambiguous"<<el;
	        }else{
	            if(v[0]==0)for(auto e:v) cout<<0<<el;
	            else for(auto e:v) cout<<1<<el;
	        }
	    }else
	        cout<<"ambiguous"<<el;
	}
}