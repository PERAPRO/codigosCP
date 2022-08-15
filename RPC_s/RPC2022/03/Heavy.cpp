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
    string a,b;
    cin>>a>>b;
    
    ll wa = a.size();
    ll sum_a = 0;
    
    for(char c:a) sum_a += c - '0';
    
    ll ans_a = wa * sum_a;
    
    ll wb = b.size();
    ll sum_b = 0;
    
    for(char c:b) sum_b += c - '0';
    
    ll ans_b = wb * sum_b;
    
    //cout<<ans_a<<esp<<ans_b<<el;
    
    if(ans_a == ans_b)
        cout<<0<<el;
    else if(ans_a > ans_b)
        cout<<1<<el;
    else
        cout<<2<<el;
}

/*

*/