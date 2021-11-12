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
    os<<endl;
    return os;
}
string yes="YES";
string no="NO";
const int N=1e5+5;
bool matches[N];
bool aux[N];

void kmp(string &cur_p, string &s){
    string f=cur_p+'$'+s;
    int n=f.size();
    int pz=cur_p.size();
    vi ps(n);
    //vi ans;
    for(int i=1;i<n;i++){
        int j=ps[i-1];
        while(j && f[i]!=f[j]) j=ps[j-1];
        if(f[i]==f[j]) j++;
        ps[i]=j;
        if(ps[i]==pz) matches[i-pz]=1;
    }
}

vi kmp2(string &cur_p, string &s){
    string f=cur_p+'$'+s;
    int n=f.size();
    int pz=cur_p.size();
    vi ps(n);
    vi ans;
    for(int i=1;i<n;i++){
        int j=ps[i-1];
        while(j && f[i]!=f[j]) j=ps[j-1];
        if(f[i]==f[j]) j++;
        ps[i]=j;
        if(ps[i]==pz) ans.pb(i-2*pz);
    }
    return ans;
}


int main(){
    fast_io;
    /*
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //*/
    string s;
    while(cin>>s){
        memset(matches,0,sizeof matches); memset(aux,0,sizeof aux);
        string p;
        cin>>p;
        int sz=s.size();
        int pz=p.size();
        int pp=0;
        //Tengo que hacer dos fases :'v
        if(p==string(pz,'?')) {cout<<max(0,sz-pz+1)<<endl; continue;}

        string cur_p="";
        for(;pp<pz;pp++){
            if(p[pp]=='?') break;
            cur_p+=p[pp];
        }
        if(cur_p.size()) kmp(cur_p,s);
        else fill(matches,matches+N,1);

        //Halar cuanto me tengo que mover
        int tint=0;
        for(;pp<pz;pp++){
            if(p[pp]=='?') tint++;
            else break;
        }

        //Me muevo
        for(int i=0;i<=sz;i++){
            if(matches[i] && i+tint<=sz){
                aux[i+tint]=1;
            }
        }

        copy(aux,aux+N,matches);
        memset(aux,0,sizeof aux);

        while(pp<pz){
            cur_p="";
            for(;pp<pz;pp++){
                if(p[pp]=='?') break;
                cur_p+=p[pp];
            }

            vi match2=kmp2(cur_p,s);

            int len=cur_p.size();

            for(auto &match:match2){
                if(match+len<=sz && matches[match]){
                    aux[match+len]=1;
                }
            }

            copy(aux,aux+N,matches);
            memset(aux,0,sizeof aux);

            tint=0;
            for(;pp<pz;pp++){
                if(p[pp]=='?') tint++;
                else break;
            }

            //Me muevo
            for(int i=0;i<=sz;i++){
                if(matches[i] && i+tint<=sz){
                    aux[i+tint]=1;
                }
            }

            copy(aux,aux+N,matches);
            memset(aux,0,sizeof aux);
        }
        int ans=0;
        for(bool x:matches) if(x) ans++;
        cout<<ans<<endl;
    }
}