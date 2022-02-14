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

string cubo="cube";
string cil="cylinder";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,value;
    cin>>n;
    priority_queue<int> cubos;
    priority_queue<int> cilindros;
    string type;
    for(int i=0;i<n;i++){
        cin>>type>>value;
        if(type=="cube"){
            cubos.push(value);
        }else{
            cilindros.push(value);
        }
    }
    vector<pair<string,int>> ans;
    for(int i=0;i<n;i++){
        int maxcu=-1,maxci=-1;
        if(cubos.size())maxcu=cubos.top();
        if(cilindros.size())maxci=cilindros.top();
        if(maxcu>0 && maxci>0){
            //Ambos se pueden contener
            if(maxcu>=2*maxci && (int)sqrt(2*maxci*maxci)>=maxcu){
                ans.pb({cubo,maxcu});
                cubos.pop();
            }else if((int)sqrt(2*maxci*maxci)>=maxcu){//El cilindro puede contener al cubo
                ans.pb({cil,maxci});
                cilindros.pop();
            }else if(maxcu>=2*maxci){ // El cubo puede contener al cilindro
                ans.pb({cubo,maxcu});
                cubos.pop();
            }
        }else if(maxci>-1){
            ans.pb({cil,maxci});
            cilindros.pop();
        }else{
            ans.pb({cubo,maxcu});
            cubos.pop();
        }
    }
    if(ans.size()==n){
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            cout<<ans[i].ff<<esp<<ans[i].ss<<el;
        }
    }else{
        cout<<"impossible"<<el;
    }
}

/*

*/