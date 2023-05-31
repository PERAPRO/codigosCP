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


tuple<vi, int , vi> get_arrays(vi array, int padre){
    bool lft = 1;
    
    vi left, right;
    
    for(int i=0;i<array.size();i++){
        if(array[i] == padre){
            lft = 0;
            continue;
        }
        
        if(lft) left.pb(array[i]);
        else right.pb(array[i]);
    }
    return {left, padre, right};
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    
    while(tc--){
        map<char,int> char_to_number;
        map<int,char> number_to_char;
        
        int nodes;
        cin>>nodes;
        
        string pre_s, in_s;
        cin>>pre_s>>in_s;
        
        vi pre(nodes), in(nodes);
        
        set<int> s;
        
        for(int i=0;i<nodes;i++){
            char_to_number[pre_s[i]] = i;
            number_to_char[i] = pre_s[i];
            pre[i] = i;
            s.insert(i);
        }
        
        for(int i = 0;i<nodes;i++){
            in[i] = char_to_number[in_s[i]];
        }
        
        vector<pii> g(nodes);
        
        function<void(vi, int, vi)> solve = [&](vi left, int p, vi right){
            if(!left.size()){
                g[p].ff = -1;
            }
            if(!right.size()){
                g[p].ss = -1;
            }
            
            if(left.size()){
                int nxt = *s.begin();
                s.erase(s.begin());
                auto [left_son, me, right_son] = get_arrays(left, nxt);
                solve(left_son, me, right_son);
                g[p].ff = nxt;
            }
            
            if(right.size()){
                int nxt = *s.begin();
                s.erase(s.begin());
                auto [left_son, me, right_son] = get_arrays(right, nxt);
                solve(left_son, me, right_son);
                g[p].ss = nxt;
            }
            
        };
        
        function<void(int)> pos = [&](int node){
            if(g[node].ff != -1) pos(g[node].ff);
            if(g[node].ss != -1) pos(g[node].ss);
            cout<<number_to_char[node];
        };
        
        s.erase(0);
        
        auto[left, p, right] = get_arrays(in, 0);
        
        solve(left, p, right);

        pos(0);
        cout<<el;
    }
}

/*

*/