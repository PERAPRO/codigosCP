/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
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
string yes="Yes";
string no="No";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    for(int t = 1;t<=tc;t++){
        int n,m,s;
        cin>>n>>m>>s;
        
        // * can be occupied, . cannot be occupied
        
        vector<vector<char>> board(155,vector<char>(155,'.'));
        
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                board[i + 51][j + 51] = s[j];
            }
        }
        
        for(int piece = 0;piece<s;piece++){
            int nn,mm;
            cin>>nn>>mm;
            
            vector<string> pc(nn);
            
            for(int i=0;i<nn;i++){
                cin>>pc[i];
            }
            
            bool f = 0;
            
            for(int i=0;i + nn < 155;i++){
                for(int j = 0;j + mm<155;j++){
                    //Chequeo si desde la esquina superior izquierada [i][j] matchea mi tablero con mi pieza
                    bool ff = 1;
                    for(int ii=0;ii<nn;ii++){
                        for(int jj = 0;jj<mm;jj++){
                            if(pc[ii][jj] == '*')
                                ff &= (board[i + ii][j + jj] == '*');
                        }
                    }
                    f |= ff;
                }
            }
            
            if(f)
                cout<<yes<<el;
            else
                cout<<no<<el;
                
        }
        cout<<el;
    }
}

/*

*/