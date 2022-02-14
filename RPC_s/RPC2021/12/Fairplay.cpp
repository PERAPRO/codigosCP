#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define lli long long int

int main(){
    fastio
    string possible = "possible\n", impossible = "impossible\n";
    int n; cin>>n;
    map<pair<lli,lli>,int> p_bs;
    lli total_billards=0, total_pool=0;
    if (n%2){
        cout<<impossible;
        return 0;
    } 
    pair<lli,lli> p;
    
    for(int i=0;i<n;i++){
        cin>>p.first>>p.second;
        p_bs[p]++;
        total_billards += p.second;
        total_pool +=p.first;
    }
    if(total_billards % (n / 2) || total_pool % (n / 2)){
        cout<<impossible;
        return 0;
    }
    
    bool f = 1;
    
    lli pools = total_pool / (n / 2);
    lli billards = total_billards / (n / 2);
    
    for(auto [key,value]:p_bs){
        if(p_bs[make_pair(pools - key.first,billards - key.second)] != value) f = 0;
    }
    if(f)
        cout<<possible;
    else
        cout<<impossible;
    

}