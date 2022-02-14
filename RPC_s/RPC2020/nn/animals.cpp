#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	string last_game;
	cin>>last_game;
	int n;
	cin>>n;
	vector<string> animals;
	bool possible = false;
	string caracter ="";
	for(int i=0;i<n;i++){
	    string k;
	    cin>>k;
	    if(last_game[last_game.length()-1]==k[0] && !possible){
	        possible=true;
	        cout<<k;
	        caracter+=k[k.length()-1];
	    }else{
	        animals.pb(k);
	    }
	}
	bool win = true;
	if(possible){
	    for(int i=0;i<animals.size();i++){
	        if(animals[i][0]==caracter[0]){
	            win=false;
	        }
	    }if(win){
	        cout<<'!'<<endl;
	    }else{
            cout<<endl;
	    }
	}else{
	    cout<<'?'<<endl;
	}
}
