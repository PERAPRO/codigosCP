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
    os<<'\n';
    return os;
}

ostream& operator<<(ostream& os, const vector<vector<char>> &v){
    for(vector<char> vv:v){
        for(char c:vv) os<<c;
        os<<el;
    }
    os<<endl;
    return os;
}

string yes="YES";
string no="NO";

int explore(int i, int j,char c,vector<vector<char>> &m){
    int ans=0;
    int l=j, r=j;
    //Comenzamos explorando a lo horizontal

    while(l>=0 && m[i][l]==c) l--;
    if(l>=0 && m[i][l]!=c || l<0) l++;
    while(r<m[0].size() && m[i][r]==c) r++;
    if(r<m[0].size() && m[i][r]!=c || r>=m[0].size()) r--;
    ans=max(ans,abs(r-l)+1);

    l=r=i;
    //Explorando Vertical  //l-> down
    while(l<m.size() && m[l][j]==c ) l++;
    if(l<m.size() && m[l][j]!=c || l>=m.size()) l--;
    while(r>=0 && m[r][j]==c ) r--;
    if(r>=0 && m[r][j]!=c || r<0) r++;
    ans=max(ans,abs(r-l)+1);

    l=r=0;
    //Exploracion diagonal creciente
    while(i-l>=0 && j+l<m[0].size() && m[i-l][j+l]==c) l++;
    if(i-l>=0 && j+l<m[0].size() && m[i-l][j+l]!=c || (i-l<0 || j+l>=m[0].size())) l--;
    while(i+r<m.size() && j-r>=0 && m[i+r][j-r]==c) r++;
    if(i+r<m.size() && j-r>=0 && m[i+r][j-r]!=c || (i+r>=m.size() || j-r<0)) r--;
    ans=max(ans,abs(r-l)+1);

    l=r=0;
    //Exploracion diagonal decreciente
    while(i+l<m.size() && j+l<m[0].size() && m[i+l][j+l]==c) l++;
    if(i+l<m.size() && j+l<m[0].size() && m[i+l][j+l]!=c || (i+l>=m.size()) || j+l>=m[0].size()) l--;
    while(i-r>=0 && j-r>=0 &&  m[i-r][j-r]==c) r++;
    if(i-r>=0 && j-r>=0 && m[i-r][j-r]!=c || (i-r<0 || j-r<0)) r--;
    ans=max(ans,abs(r-l)+1);

    return ans;
}

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //*/
    int h,w,k;
    cin>>h>>w>>k;
    vector<vector<char>> m(h,vector<char>(w,'D'));
    vi alturas(w,h-1);
    int win=0;
    for(int i=0;i<h*w;i++){
        int col,l;
        cin>>col;
        col--;
        if(i%2==0){
            m[alturas[col]][col]='A';
            l=explore(alturas[col],col,'A',m);
            if(l>=k){
                win=i+1;
                break;
            }
            alturas[col]--;
        }else{
            m[alturas[col]][col]='B';
            l=explore(alturas[col],col,'B',m);
            if(l>=k){
                win=i+1;
                break;
            }
            alturas[col]--;
        }
        //cout<<i<<esp<<l<<el<<m;
    }
    if(!win)
        cout<<'D'<<el;
    else if(win&1) cout<<'A'<<esp<<win<<el;
    else cout<<'B'<<esp<<win<<el;
}

/*

*/