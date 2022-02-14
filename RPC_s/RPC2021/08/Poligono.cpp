/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
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

const int N=205;
char mx[N][N];

char dot='.', hs='#';

int n,m;


int ans=0;

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            mx[i][j]='.';
    
    cin>>n>>m;
    
    string s;
    
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++)
            mx[i][j] = s[j - 1];
    }        
    
    int sup=0, inf=0, der=0, izq=0;
    
    //  Inferiores
    
    int last=-1;
    
    for(int i=N-1;i>0;i--){
        last=-1;
        for(int j=0;j<N;j++){
            if(mx[i][j] == dot && mx[i - 1][j] == hs){
                if(last + 1 == j)
                    last=j;
                else{
                    last=j;
                    inf++;
                }
            }
        }
    }
    
    //  Superiores
    
    last = -1;
    
    for(int i=0; i<N-1 ;i++){
        last=-1;
        for(int j=0;j<N;j++){
            if(mx[i][j] == dot && mx[i + 1][j] == hs){
                if(last + 1 == j) // Prolongo el anterior
                    last=j;
                else{ //Empiezo uno nuevo y lo cuento
                    last=j;
                    sup++;
                }
            }
        }
    }
    
    //Derechos
    
    last = -1;
    
    for(int j=0; j<N-1 ;j++){
        last=-1;
        for(int i=0;i<N;i++){
            if(mx[i][j] == dot && mx[i][j + 1] == hs){
                if(last + 1 == i) // Prolongo el anterior
                    last=i;
                else{ //Empiezo uno nuevo y lo cuento
                    last=i;
                    der++;
                }
            }
        }
    }
    
    //Izquierdos
    
    for(int j=N-1;j>0;j--){
        last=-1;
        for(int i=0;i<N;i++){
            if(mx[i][j] == dot && mx[i][j - 1] == hs){
                if(last + 1 == i)
                    last=i;
                else{
                    last=i;
                    izq++;
                }
            }
        }
    }
    
    cout<<sup+inf+der+izq<<el;
    
    //cout<<sup<<esp<<inf<<esp<<der<<esp<<izq<<esp<<sup+inf+der+izq<<el;
    
}

/*
10 10
..........
.########.
.##..#..#.
.#...#..#.
.##.......
.#........
..........
..........
..........
..........
*/