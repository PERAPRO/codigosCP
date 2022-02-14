#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int ymax=INT_MIN;
    int ymin=INT_MAX;
    int xmax=INT_MIN;
    int xmin=INT_MAX;
    int dots;
    cin>>dots;
    vector<pair<int,int>> d(dots);
    for(int i=0;i<dots;i++){
        cin>>d[i].first;
        cin>>d[i].second;
        ymin=min(d[i].second,ymin);
        ymax=max(d[i].second,ymax);
        xmin=min(d[i].first,xmin);
        xmax=max(d[i].first,xmax);
    }
    ll suma=0;
    //cout<<xmin<<" "<<xmax<<" "<<ymin<<" "<<ymax<<endl;
    for(int i=0;i<dots;i++){
        if(d[i%dots].first==d[(i+1)%dots].first){
            suma+=abs(d[i%dots].second-d[(i+1)%dots].second);
        }else{
            suma+=abs(d[i%dots].first-d[(i+1)%dots].first);
        }
        //cout<<i<<" "<<suma<<endl;
    }
    
    ll area=(2*abs(ymax-ymin))+(2*abs(xmax-xmin));
    //cout<<suma<<" "<<area<<endl;
    cout<<suma-area<<endl;
}