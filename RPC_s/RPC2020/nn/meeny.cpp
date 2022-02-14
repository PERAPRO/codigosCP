#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	string rima;
	int spaces=0;
	getline(cin,rima);
    for(int i=0;i<rima.length();i++){
        if(rima[i]==' '){
            spaces++;
        }
    }
    vector<string> team1;
    vector<string> team2;
    int n;
    cin>>n;
    vector<string> nombres;
    for(int i=0;i<n;i++){
        string k;
        cin>>k;
        nombres.pb(k);
    }
    team1.pb(nombres[(spaces)%n]);
    auto aux=nombres.begin();
    aux+=(spaces)%n;
    nombres.erase(aux);
    if(spaces>0) {
        spaces--;
    }
    int pos=0;
    for(int i=0;i<n-1;i++){
        if(i%2==0){
            team2.pb(nombres[(pos+spaces)%nombres.size()]);
            auto itr = nombres.begin();
            itr+=(pos+spaces)%nombres.size();
            nombres.erase(itr);
            if(nombres.size()>0){
                pos=(pos%nombres.size());
            }
        }else{
            team1.pb(nombres[(pos+spaces)%nombres.size()]);
            auto itr = nombres.begin();
            itr+=(pos+spaces)%nombres.size();
            nombres.erase(itr);
            if(nombres.size()>0)
                pos=(pos%nombres.size());
        }
    }
    cout<<team1.size()<<endl;
    for(auto x:team1){
        cout<<x<<endl;
    }
    cout<<team2.size()<<endl;
    for(auto x:team2){
        cout<<x<<endl;
    }
}
