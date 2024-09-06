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

const int N = 1e5 + 5;
const int M = 2e5+5;

int p[N];
set<int> wars[N];

int find(int n){
    // while(p[n] >= 0) n = p[n];
    // return n;
    if(p[n] >= 0) return p[n] = find(p[n]);
    return n;
}

void Union(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return ;
    
    if(-p[a] < -p[b]) swap(a, b); //a es el mas grade, pego b a a 
    // cout<<p[a]<<esp<<p[b]<<el;
    for(int enemy:wars[b]){
        wars[enemy].erase(b);
        wars[enemy].insert(a);
        wars[a].insert(enemy);
    }

    wars[b].clear();
    
    p[a] += p[b];
    p[b] = a;
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m;
    cin>>n>>m;
    
    memset(p, -1, sizeof p);
    
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        wars[a].insert(b);
        wars[b].insert(a);
    }
    
    int queries;
    cin>>queries;
    for(int q = 0;q<queries;q++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        a = find(a), b = find(b);
        if(a == b){
            cout<<"NEXT"<<el;
        }else if(wars[a].count(b)){
            cout<<"AVOID WAR"<<el;
        }else{
            Union(a, b);
            cout<<"FOR THE PEACE"<<el;
        }
    }
}

/*

*/