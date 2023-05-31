#include <bits/stdc++.h>
using namespace std;

#define ld float
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
//#define endl '\n'
#define ll long long
const ll mod = 7 + 1e9;




int main() {
    IO;
    int n,k;cin>>n>>k;
    vector<ld> ice;
    ld acum = 0;
    for(int i=0;i<n;i++){
        ld a;cin>>a;
        acum += -a/5;
        acum = max((ld)0,acum);
        ice.push_back(acum);
    }
    sort(ice.begin(),ice.end());
    set<pair<ld,int>> s;
    for(int i=0;i<ice.size();i++){
        s.insert({ice[i],i+1});
    }
    while(k--){
        ld p;cin>>p;
        auto it = s.lower_bound({p,0});
        if(it==s.end())cout<<0<<' ';
        else cout<<n-it->second+1<<' ';
    }
    cout<<endl;
}