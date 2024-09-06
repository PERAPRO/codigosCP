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

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int N = 2e5+5;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string n,m;
    cin>>n>>m;
    if(n == m){
        cout<<1<<el;
        return 0;
    }
    for(int i = 0;i<N;i++){
        map<char,long long> cnt;
        for(char c:n){
            cnt[c]++;
        }
        string new_s = "";
        for(auto[cc, cantidad]:cnt){
            new_s += to_string(cantidad);
            new_s += cc;
        }
        if(new_s == m){
            cout<<i + 2<<el;
            return 0;
        }
        if(new_s == n){
            cout<<"Does not appear"<<el;
            return 0;
        }
        if(new_s.size() > 100){
            cout<<"I’m bored"<<el;
            return 0;
        }
        n = new_s;
    }
    cout<<"Does not appear"<<el;
    
}

/*

*/