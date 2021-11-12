#include <bits/stdc++.h>

using namespace std;

#define pb push_back


int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    vector<pair<int,int>> v2;
    for(int i=0;i<n;i++){
        int e,s;
        cin>>e>>s;
        v2.pb({e,s});
        v.pb({e,0});
        v.pb({s,1});
    }
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    int cnt=1;
    bool b= true;
    int cur=v2[n-1].first;
    for(int i=n-1;i>-1;i--){
        if(v2[i].second<cur){
            cnt++;
            cur=v2[i].first;
        }
    }
    cout<<cnt<<endl;
}