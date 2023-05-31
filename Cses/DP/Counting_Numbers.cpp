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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
string yes="YES";
string no="NO";

//Calcular los numeros arcoiris de 1 a n inclusive
/*
Ideas principales:
Guardar el digito que ya puse a mi izquierda, y poner todos menos ese.
*/

string s;
int n;
// const int mod=998244353;

ll dp[25][10][2][2];

ll go(int idx, int ultimo, bool leading, bool match){
    if(idx == n && ultimo == 0 && leading == 0) return 0;
    if(idx == n) return 1;
    if(dp[idx][ultimo][leading][match]>0) return dp[idx][ultimo][leading][match];


    int ub = 9;
    if(!match) ub = s[idx] - '0';   //Match es true si llene con un numero menor antes, luego puedo usar todos
    ll ans=0;
    for(int i=0;i<=ub;i++){
        if(i != ultimo || (!leading && ultimo == 0 && i == 0)){
            if(match || i < ub)//Si no he usado un menor a mi izquierda, match==0 solo puedo ir hasta el ub
                ans = (ans + go(idx + 1, i,!(i == 0) || leading, 1));
            else
                ans = (ans + go(idx + 1, i,!(i == 0) || leading, 0));
        }
    }
    return dp[idx][ultimo][leading][match] = ans;
}

bool check(){
    bool ans = 1;
    for(int i=0;i<s.size() - 1;i++){
        if(s[i] == s[i + 1]){
            ans = 0;
        }
    }
    return ans;
}

int main(){
    fast_io;
    memset(dp,-1,sizeof dp);
    
    cin>>s;
    n = s.size();
    ll l = go(0, 0, 0, 0);
    // cout<<l<<el;
    bool lcuenta = check();
    
    memset(dp,-1,sizeof dp);
    cin>>s;
    n = s.size();
    ll r = go(0, 0, 0, 0);
    
    ll ans = (r - l + lcuenta);
    // cout<<r<<el;
    cout<<ans<<el;
    return 0;
}