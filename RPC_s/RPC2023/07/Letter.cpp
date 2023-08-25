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
    int words;
    cin>>words;
    vector<string> v(words);
    for(int i=0;i<words;i++){
        cin>>v[i];
    }
    
    vector<vi> mx(31, vi(26));
    
    for(int i = 0;i<words;i++){
        for(int j = 0;j<v[i].size();j++){
            mx[j][v[i][j] - 'a']++;
        }
    }
    
    for(int i = 0;i<31;i++){
        int cur_max = *max_element(all(mx[i]));
        if(!cur_max) break;
        cout<<i + 1<<":";
        for(int j = 0;j<26;j++){
            if(mx[i][j] == cur_max)
                cout<<esp<<char(j + 'a');
        }
        cout<<el;
    }

}

/*

*/