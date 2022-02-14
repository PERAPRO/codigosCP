#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
const lli mod=((1LL<<31)-1);
const int N = 1e4+1;
struct st{
    st *left, *right;
    int l,r,mid;
    int mx, mn;
    int lux;
    st(int l, int r) : l(l), r(r){
        if(l!=r){
            mid = (l+r)/2;
            left = new st(l,mid);
            right = new st(mid+1,r);
        }
    }
    void update(int pos, int val){
        if(l==r){
            lux = val; //si llegamos a un nodo hoja
            mn = val;
            mx = val;
        }
        else{
            if(pos>mid)right->update(pos,val);
            else left->update(pos,val);
            mn = min(left->mn,right->mn);
            mx = max(left->mx , right->mx);
        }
    }

    int getV(int a, int b){
        if(a<=l && r<=b)return lux; //que me sirva todo
        if(b<l || a>r)return 0; //que no me sirva
        else return left->getV(a,b) + right->getV(a,b); //seguimos probando
    }
    int getMin(int a, int b){
        if(a<=l && r<=b)return mn; //que me sirva todo
        if(b<l || a>r)return 0; //que no me sirva
        else return min(left->getMin(a,b) , right->getMin(a,b)); //seguimos probando
    }
    int getMax(int a, int b){
        if(a<=l && r<=b)return mx; //que me sirva todo
        if(b<l || a>r)return 0; //que no me sirva
        else return max(left->getMax(a,b) , right->getMax(a,b)); //seguimos probando
    }
};
int main(){
    fast_io;
    int n;cin>>n;
    int q;cin>>q;
    st tree(1,n);
    int tmp;
    REP(i,n){
        cin>>tmp;
        tree.update(i+1,tmp);//creamos el st
    }
    REP(i,q){
        string tipo;cin>>tipo;
        int l,r;cin>>l>>r;
        if(tipo=="MAX"){
            cout<<tree.getMax(l,r)<<endl;
        }
        else if(tipo=="MIN"){
            cout<<tree.getMin(l,r)<<endl;
        }
        else tree.update(l,r);//creamos el st
    }
    return 0;
}



