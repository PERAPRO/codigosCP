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
	int n;
	cin>>n;
	int k;
	cin>>k;
	// n estudiantes  k preguntas
	vector<string> grid(n);
	for(auto &e:grid) cin>>e;
	int ans=-1e8;
	for(int i=0;i<2048;i++){
	    int corrects=1e8;
	    string sol="";
	    for(int j=0;j<=10;j++){
	        if((1<<j) & i){
	            sol+='T';
	        }else{
	            sol+='F';
	        }
	    }
	    //cout<<sol<<el;
	    for(auto s:grid){
	        int buenas=0;
	        for(int j=0;j<k;j++){
	            if(s[j]==sol[j]){
	                buenas++;
	            }
	        }
	        corrects=min(corrects,buenas);
	    }
	    ans=max(ans,corrects);
	}
	cout<<ans<<el;
}