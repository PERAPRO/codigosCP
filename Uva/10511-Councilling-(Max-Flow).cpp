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
string yes="YES";
string no="Impossible.";

int INF=1e9+7;
int N;


int bfs(int s, int t, vector<int>& parent, vector<vi> &adj, vector<vi> &capacity) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int max_flow(int s, int t, vector<vi> &adj, vector<vi> &capacity) {
    int flow = 0;
    vector<int> parent(N);
    int new_flow;

    while (new_flow = bfs(s, t, parent,adj,capacity)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}



int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    string s;
    getline(cin,s);
    getline(cin,s);
    while(tc--){
        //cout<<tc<<el;
        
        int personas=0;
        
        map<string,vector<string>> partys;
        map<string,vector<string>> clubes;
        vector<string> people;
        vector<string> cc;
        
        while(getline(cin,s)){
            if(s=="") break;
            //cout<<s<<el;
            stringstream ss(s);
            string nombre, party,club;
            
            ss>>nombre>>party;
            partys[party].pb(nombre);
            people.pb(nombre);
            while(ss>>club){
                //for(string sn:clubes[club]) assert(sn!=nombre);
                clubes[club].pb(nombre);
            }
            
            //Clubes van de 1 a clubes, personas de clubes+1 a clubes+personas, partidos de 
            //clubes+personas+1 a clubes+personas+partys ST lo de antes +1
            
            personas++;
        }
        
        int csz=clubes.size();
        int psz=partys.size();
        sort(people.begin(),people.end());
        
        N=csz+personas+psz+3;
        
        int st=csz+personas+psz+1;
        
        vector<vi> g(N);
        vector<vi> capacity(N,vi(N));
        
        //Se dice que un partido no puede tener mas de la mitad de los concejales luego
        
        int maxf=csz/2;
        if(csz%2 == 0) maxf--;  //---------------?-----------------
        
        //Armo el grafo y las capacidades
        int cnt=1;
        for(auto &[key,value]:clubes){
            g[0].pb(cnt), g[cnt].pb(0);
            capacity[0][cnt]=1;
            sort(value.begin(),value.end()); value.erase(unique(value.begin(),value.end()),value.end());
            for(int i=0;i<value.size();i++){
                int node=lower_bound(people.begin(),people.end(),value[i])-people.begin();
                g[cnt].pb(csz+node+1),g[csz+node+1].pb(cnt);
                capacity[cnt][csz+node+1]=1;
            }
            cnt++;
            cc.pb(key);
        }
        
        cnt+=personas;
        
        for(auto &[key,value]:partys){
            g[st].pb(cnt), g[cnt].pb(st);
            capacity[cnt][st]=maxf;
            sort(value.begin(),value.end()); value.erase(unique(value.begin(),value.end()),value.end());
            for(int i=0;i<value.size();i++){
                int node=lower_bound(people.begin(),people.end(),value[i])-people.begin();
                g[cnt].pb(csz+node+1),g[csz+node+1].pb(cnt);
                capacity[csz+node+1][cnt]=1;
            }
            cnt++;
        }
        
        //for(auto vv:g) cout<<vv;
        
        int flow=max_flow(0,st,g,capacity);   //cout<<flow<<el;
        
        if(flow == csz){
            //cout<<yes<<el;
            //for(auto vv:capacity) cout<<vv;
            
            //Reconstruct the answer with bfs
            vector<pair<string,string>> ans; //Primera posicion persona, segunda club
            vector<bool> visited(N);
            queue<int> q;
            q.push(0);
            while(q.size()){
                int cur=q.front();
                //cout<<cur<<endl;
                q.pop();
                if(visited[cur]) continue;
                visited[cur]=1;
                //cout<<300<<endl;
                if(cur<=csz){
                    for(int u:g[cur]){
                        if(cur > 0 && capacity[u][cur] == 1){ // u es persona?
                            ans.pb(make_pair(people[u-csz-1],cc[cur-1]));
                        }
                        q.push(u);
                    }
                }
            }
            for(int i=0;i<csz;i++){
                cout<<ans[i].ff<<esp<<ans[i].ss<<el;
            }
            
        }else{
            cout<<no<<el;
        }
        if(tc>0) cout<<el;
        //Toca reconstruir :ccc
    }
    return 0;
}

/*

*/