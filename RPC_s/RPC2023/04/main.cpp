#include <bits/stdc++.h>
using namespace std;

#define ld double
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
//#define endl '\n'
#define ll long long
const ll mod = 7 + 1e9;




int main() {
    IO;
    int n,k;cin>>n>>k;
    vector<ll> ice;
    ll acum = 0;
    for(int i=0;i<n;i++){
        ld a;cin>>a;
        acum += -a * 10 / 5;
        acum = max(0LL,acum);
        ice.push_back(acum);
    }
    sort(ice.begin(),ice.end());
    // set<pair<ld,int>> s;
    // for(int i=0;i<ice.size();i++){
    //     s.insert({ice[i],i+1});
    // }
    for(int i=0;i<k;i++){
        if(i) cout<<' ';
        ll p;cin>>p;
        int idx = lower_bound(ice.begin(), ice.end(), p * 10) - ice.begin();
        cout<<n - idx;
        // auto it = s.lower_bound({p,0});
        // if(it==s.end())cout<<0<<' ';
        // else cout<<n-it->second+1<<' ';
    }
    cout<<endl;
}