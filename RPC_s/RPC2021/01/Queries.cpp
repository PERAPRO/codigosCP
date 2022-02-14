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

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	    multiset<int> menores;
	    //multiset<int,greater<int>> mayores;
	    stack<int> pila;
	    int q;cin>>q;
	    while(q--){
	        int tipo; cin>>tipo;
	        int v;
	        if(tipo==1){
	            cin>>v;
	            pila.push(v);
	            menores.insert(v);
	            //mayores.insert(v);
	        }
	        if(tipo==2){
	            if(pila.size()){
	                int k=pila.top();
	                menores.erase(menores.find(k));
	                pila.pop();
	            }
	        }
	        if(tipo==3){
	            if(pila.size()){
    	            int menor=*menores.begin();
    	            auto it=menores.end();
    	            it--;
    	            int mayor=*it;
    	            cout<<abs(mayor-menor)<<endl;
	            }else{
	                cout<<"Empty!\n";
	            }
	        }
	    }
	}
}
