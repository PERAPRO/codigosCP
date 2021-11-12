#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main() {
    long long k;
    cin>>k;
    long long tsuma=(k*(k+1))/2;
    if(tsuma%2==0){
        cout<<"YES"<<endl;
        long long suma=tsuma/2;
        vector<ll> numeros;
        for(ll i=k;i>=1;i--){
            numeros.pb(i);
        }
        ll currents=0;
        vector<ll> set_2;
        ll last=0;
        for(ll i=1;i<k;i++){
            if(currents==suma){
                break;
            }else{
                currents+=numeros[i-1];
                set_2.pb(numeros[i-1]);
                numeros[i-1]=0;
                if(currents==suma){
                    break;
                }else{
                    set_2.pb(i);
                    currents+=i;
                    last=i;
                }
            }
        }
        vector<ll> set_1;
        for(ll i=0;i<k;i++){
            if(numeros[i]!=0){
                set_1.pb(numeros[i]);
            }
        }
        cout<<set_1.size()-last<<endl;
        cout<<set_1[0];
        for(ll i=1;i<set_1.size()-last;i++){
            cout<<" "<<set_1[i];
        }
        cout<<endl;
        cout<<set_2.size()<<endl;
        cout<<set_2[0];
        for(ll i=1;i<set_2.size();i++){
            cout<<" "<<set_2[i];
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}