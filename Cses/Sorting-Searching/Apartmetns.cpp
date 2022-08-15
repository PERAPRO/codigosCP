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
    
    int n,m,k;
    cin>>n>>m>>k;
    
    deque<int> appli(n);
    multiset<int> applis;
    
    for(int i=0;i<n;i++){
        cin>>appli[i];
        applis.insert(appli[i]);
    }
    
    deque<int> apar(m);
    
    for(int i=0;i<m;i++){
        cin>>apar[i];
    }
    
    sort(all(appli));
    sort(all(apar));
    
    int ans = 0;
    
    for(int i=0;i<m;i++){
        auto search = applis.lower_bound(apar[i] - k);
        if(search == applis.end()) continue;
        int val = *search;
        if(abs(val - apar[i]) > k) continue;
        
        ans++;
        applis.erase(applis.find(val));
    }
    
    cout<<ans<<el;
}

/*

*/