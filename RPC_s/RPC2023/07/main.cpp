#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxN = 2e5 +20;
bool check(vector<pair<int,int>> &ranges,vector<int> a,vector<int> &list,int changes){
    for(int i=0;i<changes;i++)a[list[i]] = 1;
    for(int i=1;i<a.size();i++)a[i]+=a[i-1];
    for(auto p:ranges){
        if(a[p.second]-a[p.first-1]>(p.second-p.first+1)/2)return true;
    }

    return false;
}

int main() {
    ll n,k;cin>>n>>k;
    ll c = 1<<k;
    vector<ll> v(k);
    for(ll i=0;i<k;i++)cin>>v[i];
    ll l = 1, r = n;
    while(r>=l){
        ll aum = 0;
        for(ll i=1;i<c;i++){
            ll mul = 1;
            ll cont = 0;
            for(ll j=0;j<k;j++){
                if((1<<j)&i) {
                    mul *= v[j];
                    cont++;
                }
            }
            if(cont&1)aum+=r/mul - (l-1)/mul;
            else if(cont>0)aum-=r/mul - (l-1)/mul;
        }
        l = r+1;
        r += aum;
    }
    cout<<r<<endl;
    return 0;
}
