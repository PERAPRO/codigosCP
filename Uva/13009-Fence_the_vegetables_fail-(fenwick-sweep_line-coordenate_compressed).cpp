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

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
string yes="YES";
string no="NO";

struct bit{
    int size;
    vector<int> values;
    void init(int n){
        values.resize(n);
        size=n;
    }
    int sum(int i){
        int sum=0;
        while(i>0){
            sum+=values[i];
            i-=i&(-i);
        }
        return sum;
    }
    void update(int i, int v){
        while(i<size){
            values[i]+=v;
            i+=i&(-i);
        }
    }
};



int main(){
    fast_io;
    int p,v;
    while(cin>>p>>v){
        if(!p || !v) {
            cout<<0<<el;
            continue;
        }
        priority_queue<pair<pii,int>> eventos;
        vector<pair<pii,int>> plantas(p);
        vector<int> ids;
        vector<pii> points(v);
        for(int i=0;i<p;i++){
            cin>>plantas[i].ff.ff>>plantas[i].ff.ss;
            plantas[i].ss=i+1;
            eventos.push({{plantas[i].ff.ff,plantas[i].ff.ss},0});
            ids.pb(plantas[i].ff.ff);
            ids.pb(plantas[i].ff.ss);
        }
        
        sort(plantas.begin(),plantas.end());

        cin>>points[0].ff>>points[0].ss;
        for(int i=1;i<v;i++){
            cin>>points[i].ff>>points[i].ss;
            if(points[i-1].ss == points[i].ss){
                if(points[i].ff<points[i].ff){ //points[i] abre
                    eventos.push({points[i],1});
                    eventos.push({points[i-1],2});
                }else{  //points[i-1] abre
                    eventos.push({points[i-1],1});
                    eventos.push({points[i],2});
                }
            }
            ids.pb(points[i].ff);
            ids.pb(points[i].ss);
        }
        if(points[0].ss == points[v-1].ss){  //Si o si el ultimo abre  ???
            eventos.push({points[v-1],1});
            eventos.push({points[0],2});
        }
        
        sort(ids.begin(),ids.end());
        ids.resize(unique(ids.begin(),ids.end()) - ids.begin());
        
        bit fenwick;
        fenwick.init(ids.size()+1);
        
        ll ans=0;

        while(eventos.size()){
            int type=eventos.top().ss;
            pii coordenadas={eventos.top().ff.ff,eventos.top().ff.ss};
            eventos.pop();
            if(type == 0){ // Recibo una planta
                // Tengo que mirar si pertenece o no?
                // Me interesa el y?
                pair<pii,int> aux={coordenadas,0};
                int k=fenwick.sum((lower_bound(ids.begin(),ids.end(),coordenadas.ss)-ids.begin())+1);
                if(!(k&1)) //No pertenece al poligono
                    ans+=plantas[lower_bound(plantas.begin(),plantas.end(),aux)-plantas.begin()].ss;
            }else if(type == 1){  // Abro un segmento
                fenwick.update((lower_bound(ids.begin(),ids.end(),coordenadas.ss)-ids.begin())+1,1);
            }else{ //Type = 2
                fenwick.update((lower_bound(ids.begin(),ids.end(),coordenadas.ss)-ids.begin())+1,-1);
            }
        }
        cout<<ans<<el;
    }
    return 0;
}