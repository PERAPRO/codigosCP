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

ll fexp(ll base, ll expo){
    ll ans=1;
    for(;expo;base=base*base,expo>>=1){
        if(expo&1){
            ans=base*ans;
        }
    }
    return ans;
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=v[i]*fexp(2,n-i-1);
    }
    long double ans2=ans/(long double)fexp(2,n);
    cout<<fixed<<setprecision(10)<<ans2<<el;
}

/*

*/