#include <bits/stdc++.h>
#define ll long long 
#define ii pair<ll,ll>
#define vi vector<ll> 
#define vii vector<ii> 
#define ff first
#define ss second
using namespace std;


int main(){
  string s;cin>>s;
  int n = stoi(s);
  int ans;
  if(n < 10){
    ans = n+1;
  }
  else{
    ans = s.size()-1;
    ans *= 10;
    int fc = s[0] - '0';
    for(int i = 1;i<s.size();i++){
        if(s[i] - '0' < fc){
            fc--;
            break;
        }
        if(s[i] - '0' > fc) break;
    }ans += fc;
  }
  cout<<ans<<endl;
  return 0;
}
