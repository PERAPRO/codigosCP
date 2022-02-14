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
    int n;
    cin>>n;
    set<string> conclusions;
    int error =0;
    string s,text;
    getline(cin,s);
    for(int i=1;i<=n;i++){
        getline(cin,s);
        //cout<<s<<el;
        stringstream ss(s);
        bool f=0;
        bool c=0;
        while(ss>>text && !error){
            if(text=="->"){
                f=1;
                continue;
            }
            if(f){
                conclusions.insert(text);
            }else{
                if(conclusions.count(text) == 0){
                    error=i;
                    break;
                }
            }
        }
    }
    if(!error)
        cout<<"correct"<<el;
    else
        cout<<error<<el;
}

/*

*/