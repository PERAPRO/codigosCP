#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
//#define endl '\n'
#define ll long long
typedef long double C;
typedef complex<C> P;
#define X real()
#define Y imag()
const ll mod = 7 + 1e9;






int main() {
    IO;
    int n,m,k;cin>>n>>m>>k;
    vector<int> f,s;
    map<int,vector<int>> m1,m2;
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        m1[x].push_back(y);
        m2[y].push_back(x);
        f.push_back(x);
        s.push_back(y);
    }
    sort(f.begin(),f.end());
    sort(s.begin(),s.end());

    int mini = min(m,n);
    for(auto p:m1){
        for(int i=0;i<p.second.size()-1;i++){
            if(p.second[i+1]-p.second[i]>0)mini = min(mini,p.second[i+1]-p.second[i]);
        }
    }
    for(auto p:m2){
        for(int i=0;i<p.second.size()-1;i++){
            if(p.second[i+1]-p.second[i]>0)mini = min(mini,p.second[i+1]-p.second[i]);
        }
    }
    for(int i=0;i<k;i++){
        if(f[i]-1>0)mini = min(mini,f[i]-1);
        if(s[i]-1>0)mini = min(mini,s[i]-1);
        if(n-f[i]>0)mini = min(mini,n-f[i]);
        if(m-s[i]>0)mini = min(mini,m-s[i]);
    }
    cout<<mini<<endl;
}