#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    int n;
    vector<pair<int, int>> calls;
    cin>>n;
    for (int i = 0; i < n; i ++){
      int in;
      cin>>in;
      calls.push_back({i + 1, in});
    }
    //for (auto e:calls)
    //cout<<e.first<<" "<<e.second<<endl;
    int k = 0;
    int i=0;
    while (n > 1){
        if(i==n) i=0;
        //comienzo desde k con tamaño n y cuento
        k=calls[i].second-1;
        i=(k+i)%n;
        //cout<<"sacamos el indice "<<i<<endl;
        calls.erase(calls.begin()+i);
        n--;
    }
    cout<<calls[0].first<<"\n";
}