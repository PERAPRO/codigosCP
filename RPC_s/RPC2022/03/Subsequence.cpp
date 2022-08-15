/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
    string s;
    cin>>s;
    
    ll n = s.size();
    
    string t;
    cin>>t;
    
    int tz = t.size();
    
    vector<vi> mp(26);
    
    for(int i=0;i<n;i++){
        mp[s[i] - 'a'].pb(i);
    }
    
    vector<pii> ans;
    
    //cout<<16<<endl;
    
    for(int i:mp[t[0] - 'a']){
        
        int idx = i;
        
        bool f = 1;
        //int final = i;
        
        for(int j = 1;j<tz;j++){
            auto it = upper_bound(all(mp[t[j] - 'a']), idx);
            if(it == mp[t[j] - 'a'].end()){ 
                f = 0;
                break;
            }else idx = *it;
        }
        if(f){
            ans.pb({i, idx});
        }
    }
    
    //cout<<ans.size()<<endl;
    
    ll res = 0;
    
    if(!ans.size()){
        cout<<0<<el;
        return 0;
    }
    
    for(int i=0;i<=ans.back().ff;i++){
        if(lower_bound(all(ans), pii(i, 0)) == ans.end()) continue;
        pii x = *lower_bound(all(ans), pii(i, 0));
        res = res + (n - x.ss);
    }
    
    cout<<res<<el;
    
}
/*

*/