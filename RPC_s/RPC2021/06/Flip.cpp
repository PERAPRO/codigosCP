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
char esp = ' ';

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

typedef long double T;

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int t,s,n;          //t currrent time, s sand in grams, in the sandglass flows 1gr per second
    cin>>t>>s>>n;
    vi v(n);
    int cur=0;
    int k;
    if(n==1){    // hay max(0,t-k) arena en el nivel inferior falta (s-(m)) segundos para que acabe
        cin>>k;
        int m=max(0,t-k);
        cout<<max(0,s-m)<<el;
        return 0;

    }
    int arriba, abajo=s;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i>0){
            arriba=abajo-(v[i]-v[i-1]);
            arriba=max(0,arriba);
            abajo=s-arriba;
        }
    }
    cout<<max(0,abajo-(t-v.back()))<<el;
}

/*

*/