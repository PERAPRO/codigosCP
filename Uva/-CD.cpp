/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	cin.clear();
	cin.ignore(INT_MAX,'\n');
	string a;
 	getline(cin,a);
	while(testcases--){
	    vector<ll> tarifas(24);
	    for(int i=0;i<24;i++) cin>>tarifas[i];
	    string s;
	    cin.clear();
      cin.ignore(INT_MAX,'\n');
	    map<string,pair<pair<string,int>,pair<string,int>>> m;
	    while(getline(cin,s)){
        if(s=="") break;
        string placa="";
        string hora="";
        pair<string,int> accion;
        int espacios=0;
        string valor="";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ') espacios++;
            else if(espacios==0){
              placa+=s[i];
            }else if(espacios==1){
              hora+=s[i];
            }else if(espacios==2){
              accion.first+=s[i];
            }else if(espacios==3){
              valor+=s[i];
            }
        }
        accion.second=stoi(valor);
        if(accion.first=="enter"){
            accion.first=hora;
          if(m[placa].second.first!= "") m[placa].first=accion;
        }else if(accion.first=="exit"){
          accion.first=hora;
          if(m[placa].second.first!= "") m[placa].second=accion;
        }
	    }
	    for(auto[key,value]:m){
        if(value.first.first != "" && value.second.first != ""){
          int diai=stoi(value.first.first.substr(3,2));
          int diaf = stoi(value.second.first.substr(3,2));
          pair<int,int> horai= {stoi(value.first.first.substr(6,2)),stoi(value.first.first.substr(9,2))};
          pair<int,int> horaf= {stoi(value.second.first.substr(6,2)),stoi(value.second.first.substr(9,2))};
          if(diaf>diai || (diaf==diai && horaf>horai)){
            ll hora=stoi(value.first.first.substr(6,2));
            ll kms=value.second.second-value.first.second;
            //cout<<kms<<endl;
            //cout<<hora<<endl;
            ll ans=kms*tarifas[horai.first]+300;
            string aux=to_string(ans);
            cout<<key<<" $"<<aux.substr(0,aux.size()-2)<<"."<<aux.substr(aux.size()-2,2)<<endl;
          }
        }
	    }
	}
}
