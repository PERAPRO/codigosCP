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
    int old_list;
    cin>>old_list;
    
    map<string,int> m;
    
    for(int i=0;i<old_list;i++){
        string s;
        cin>>s;
        m[s]++;
        for(int j = 0;j<9;j++){
            string aux = s;
            aux[j] = '?';
            m[aux]++;
            for(int k = j + 1;k<9;k++){
                string aux2 = aux;
                aux2[k] = '?';
                m[aux2]++;
            }
        }
        
        for(int l = 3;l<=9;l++){
            for(int ini = 0;ini + l<=9;ini++){
                string aux = s;
                for(int k = ini, len = 0;len<l;len++,k++){
                    aux[k] = '?';
                }
                    m[aux]++;
            }
        }
    }
    
    int new_list;
    cin>>new_list;
    
    // for(auto [key, value]:m){
    //     cout<<"key : "<<key<<esp<<"value : "<<value<<el;
    // }
    
    for(int q = 0;q<new_list;q++){
        string ss;
        cin>>ss;
        if(count(all(ss), '*') > 0){
            int res = 9 - ss.size() + 1;
            string new_s = "";
            int ii = 0;
            for(;ii<ss.size();ii++){
                if(ss[ii] == '*') break;
                new_s += ss[ii];
            }
            ii++;
            for(int  k =0;k<res;k++) new_s += '?';
            for(;ii<ss.size();ii++) new_s += ss[ii];
            ss = new_s;
        }
        // cout<<ss<<el;
        cout<<m[ss]<<el;
    }
}

/*

*/