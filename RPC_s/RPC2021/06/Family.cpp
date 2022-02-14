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
char esp = ' ';

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int photos;
    cin>>photos;
    vi ans;
    for(int photo=0;photo<photos;photo++){
        int people;
        cin>>people;
        vi heights(people);
        vi mx(people,-1);
        vi mn(people,-1);
        set<int> mins;
        set<pair<int,int>> nums;
        for(int i=0;i<people;i++){
            cin>>heights[i];
            nums.insert({heights[i],i});
        }
        for(int i=people-1;i>-1;i--){
            if(i==people-1){
                mx[i]=heights[i];
                continue;
            }
            mx[i]=max(heights[i],mx[i+1]);
        }
        mins.insert(heights[0]);
        for(int i=1;i<people;i++){
            auto it=mins.upper_bound(heights[i]);
            if(it!=mins.end()){
                mn[i]=*it;
            }
            mins.insert(heights[i]);
        }
        for(auto p:nums){
            int value=p.ff;
            int idx=p.ss;
            if(idx==0 || idx==people-1) continue;
            if(mn[idx]<mx[idx+1] && mn[idx]>value) {
                ans.pb(photo+1);
                break;
            }
        }
    }
    cout<<ans.size()<<el;
    for(int a:ans) cout<<a<<el;
}

/*

*/