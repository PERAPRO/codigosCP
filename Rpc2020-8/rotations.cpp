#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int entero(string s){
    int suma=0;
    if(s[4]=='1') suma+=1;
    if(s[3]=='1') suma+=2;
    if(s[2]=='1') suma+=4;
    if(s[1]=='1') suma+=8;
    if(s[0]=='1') suma+=16;
    return suma;
}

int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	while(testcases--){
	    unsigned int n; cin>>n;
	    set<int> sol;
	    string s="";
	    for(int i=31;i>-1;i--){
	        if(n & 1<<i) s+="1";
	        else s+="0";
	    }
	    //cout<<s<<endl;
	    for(int i=0;i<32;i++){
	        string aux="";
	        aux+=s[(i+4)%32];
	        aux+=+s[(i+3)%32];
	        aux+=+s[(i+2)%32];
	        aux+=+s[(i+1)%32];
	        aux+=+s[(i)%32];
	        //cout<<aux<<endl;
	        sol.insert(entero(aux));
	        //cout<<entero(aux)<<endl;
	    }
	    if(sol.size()==32) cout<<"yes\n";
	    else cout<<"no\n";
	}
}