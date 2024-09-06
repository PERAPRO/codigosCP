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
// int hola[3];

const int N = 1e6+5;

vector<vector<set<int>>> gs(2, vector<set<int>>(N));

void transform(string s, int idx){
    int node = -1;
    int parent = -1;
    vi parents;
    
    string cur_node = "";
    int open = 0;
    for(char c:s){
        // if(c == '(' && !open){
        //     parent = stoi(cur_node);
        //     node = stoi(cur_node);
        //     parents[node] = node;
        //     open = 1;
        //     cur_node = "";
        // }else if (c == '('){
        //     if(cur_node.size() == 0){
        //         continue;
        //     }
        //     node = stoi(cur_node);
        //     // parent = node;
        //     parents[node] = parent;
        //     cout<<parent<<esp<<node<<endl;
        //     gs[idx][parent].insert(node), gs[idx][node].insert(parent);
        //     cout<<parent<<esp<<node<<endl;
            
        //     cur_node = "";
        // }else if(c == ')'){
        //     if(cur_node.size() == 0) {
        //         continue;
        //     }
        //     node = stoi(cur_node);
        //     parents[node] = parent;
        //     cout<<parent<<esp<<node<<endl;
        //     gs[idx][parent].insert(node), gs[idx][node].insert(parent);
        //     // cout<<node
        //     node = parents[node];
        //     parent = parents[node];
        //     // cout<<node<<esp<<parent<<el;
        //     cur_node = "";
        // }else if(c != ' '){
        //     cur_node += c;
        // }
        // // cout<<"final : "<<cur_node<<endl;
        if(c == '('){
            //si abro y tengo algo yo sere el padre de lo que este adentro
            if(cur_node.size()){
                // parents. = stoi(cur_node);
                node = stoi(cur_node);
                parents.pb(node);
                cur_node = "";
            }else{ //entonces ?? lo que esta adentro necesita padre
                
            }
        }else if(c == ')'){
            //si cierro y tengo algo hago la conexion
            if(cur_node.size()){
                node = stoi(cur_node);
                // cout<<parents.back()<<esp<<node<<el;
                gs[idx][parents.back()].insert(node), gs[idx][node].insert(parents.back());
                cur_node = "";
            }else{ //entonces??
                int last_node = parents.back();
                parents.pop_back();
                // cout<<"last_node : "<<last_node<<el;
                // cout<<parents.back()<<esp<<last_node<<el;
                gs[idx][parents.back()].insert(last_node), gs[idx][last_node].insert(parents.back());
                
            }
            
        }else if(c != ' '){
            cur_node += c;
        }
    }
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string a,b;
    // cin>>a>>b;
    getline(cin, a);
    getline(cin, b);
    transform(a, 0);
    // cout<<"PRIMERA"<<el;
    transform(b, 1);
    cout<<(gs[0] == gs[1] ? "Yes" : "No")<<el;
}

/*
11 (10) (12 (13) (17) (28))
11 (12 (17) (28) (13)) (10)

*/