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

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string s;
    cin>>s;
    int n=s.size();
    int tcio=n/3;
    string ans;
    if(s.substr(0,tcio)==s.substr(tcio,tcio)) ans=s.substr(0,tcio);
    if(s.substr(tcio,tcio)==s.substr(tcio+tcio,tcio)) ans=s.substr(tcio,tcio);
    if(s.substr(0,tcio)==s.substr(tcio+tcio,tcio)) ans=s.substr(0,tcio);
    cout<<ans<<el;
}

/*

*/