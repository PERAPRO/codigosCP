/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	string veredict="";
	string filename;
	getline(cin,filename);
	string givenfn;
	getline(cin,givenfn);
	vector<string> reesp;
	vector<string> redadas;
	if(!(givenfn == filename+".c" || givenfn == filename+".cpp" || givenfn == filename+".java" || givenfn == filename+".py")){
	    veredict="Compile Error\n";
	}else{
	    int r,d,t;
	    cin>>r>>d>>t;
	    if(r!=0){
	        veredict="Run-Time Error\n";
	    }else if(t>d){
	        veredict="Time Limit Exceeded\n";
	    }
	    int lineasrespuesta; cin>>lineasrespuesta;
	    cin.clear();
	    cin.ignore(INT_MAX,'\n');
	    for(int i=0;i<lineasrespuesta;i++){
	        string k; 
	        getline(cin,k);
	        reesp.pb(k);
	    }
	    int lineasrecibidas; cin>>lineasrecibidas;
	    cin.clear();
	    cin.ignore(INT_MAX,'\n');
	    for(int i=0;i<lineasrecibidas;i++){
	        string k; 
	        getline(cin,k);
	        redadas.pb(k);
	    }
	    bool flag =1;
	    if(lineasrespuesta != lineasrecibidas && veredict==""){
	        veredict="Wrong Answer\n";
	    }else if(veredict==""){
	        for(int i=0;i<lineasrespuesta;i++){
	            if(reesp[i]!=redadas[i]){
	                flag=0;
	                break;
	            }
	        }
	        if(flag){
	            veredict="Correct\n";
	        }else{
	            veredict="Wrong Answer\n";
	        }
	    }
	}
	cout<<veredict;
}