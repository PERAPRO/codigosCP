#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;



int main(){
	fast_io;
	string s;
	cin>>s;
	int maximo=0;
	int current=0;
	for(int i=0;i<s.length()-1;i++){
	    if(s[i]==s[i+1]){
	        current++;
	        maximo=max(maximo,current);
	    }else{
	        current=0;
	    }
	}
    cout<<++maximo<<endl;
}