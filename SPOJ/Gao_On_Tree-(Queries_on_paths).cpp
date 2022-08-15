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

const int maxn = 22;
const int sz = 700;
const int N = 1e5 + 5;

vi g[N];

int nodef[N], elef[N], level[N];
int lca[N][maxn], val[N], res[ 2 * N];

int s[N], t[N], ft[2 * N];

int timer = 0;

struct query{
    int l, r, c, idx, lca;
};

query Q[2 * N];

void dfs(int node, int par, int lvl){
    level[node] = lvl;
    lca[node][0] = par;
    
    s[node] = timer;
    ft[timer] = node;
    timer++;
    
    for(int child: g[node]){
        if(child == par) continue;
        dfs(child, node, lvl + 1);
    }
    
    t[node] = timer;
    ft[timer] = node;
    timer++;
}

void init(int n){
    for(int j = 1; j<maxn; j++){
        for(int i=1;i<=n;i++){
            if(lca[i][j - 1] != -1){
                lca[i][j] = lca[ lca[i][j - 1] ][j - 1];
            }
        }
    }
}

int getLca(int a, int b){
    if(level[a] > level[b]) swap(a, b);
    
    int d = level[b] - level[a];
    
    int f = 0;
    
    while(d){
        if(d & 1)
            b = lca[b][f];
            
        d >>= 1;
        f++;
    }
    
    if(a == b) return a;
    
    for(int j = maxn - 1; j>=0; j--){
        if(lca[a][j] != -1 && (lca[a][j] != lca[b][j]))
            a = lca[a][j], b = lca[b][j];
    }
    return lca[a][0];
}


bool cmp(query &a, query &b){
    if(a.l / sz != b.l / sz) return a.l / sz < b.l / sz;
    return ((a.l / sz) & 1 ? a.r > b.r : a.r < b.r);
}

void add(int idx)
{
	int node = ft[idx];
	nodef[node]++;
 
	if(nodef[node] == 1)
	{
		int c = val[node];
		elef[c]++;
	}
	else
	{
		int c = val[node];
		elef[c]--;
	}
}
 
void remove(int idx)
{
	int node = ft[idx];
	nodef[node]--;
 
	if(nodef[node] == 1)
	{
		int c = val[node];
		elef[c]++;
	}
	else
	{
		int c = val[node];
		elef[c]--;
	}
}
 

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int n,q,a,b,c;
    int tc = 0;
    
    while(cin>>n){
        if(tc) cout<<el;
        tc++;
        
        cin>>q;
        
        //initialize
		for(int i=0;i<=n;i++)
		g[i].clear() , elef[i] = 0 , nodef[i] = 0;
 
		for(int i=1;i<=q;i++)
		res[i] = 0;
 
		for(int i=1;i<=n;i++)
		cin>>val[i];
 
		for(int i=1;i<n;i++)
		cin>>a>>b , g[a].push_back(b) , g[b].push_back(a);
 
		timer = 1;
		memset(lca , -1 , sizeof lca);
		
		dfs(1 , -1 , 0);
		init(n);
 
		for(int i=1;i<=q;i++)
		{
			cin>>a>>b>>c;
			if(s[a] > s[b])
			swap(a , b);
 
			int lca = getLca(a , b);
 
			Q[i].idx = i , Q[i].c = c;
 
			//first type of query
			if(a == lca)
			Q[i].l = s[a] , Q[i].r = s[b] , Q[i].lca = -1;
 
			//second type of query
			else
			Q[i].l = t[a] , Q[i].r = s[b] , Q[i].lca = lca;
		}
 
		sort(Q+1 , Q+q+1 , cmp);
 
		int ML = 1 , MR = 0;
 
		for(int i=1;i<=q;i++)
		{
			int L = Q[i].l;
			int R = Q[i].r;
			int c = Q[i].c;
			int lca = Q[i].lca;
			int idx = Q[i].idx;
 
			while(MR < R)
			MR++ , add(MR);
 
			while(ML > L)
			ML-- , add(ML);
 
			while(MR > R)
			remove(MR) , MR--;
 
			while(ML < L)
			remove(ML) , ML++;
 
			if(elef[c] > 0)
			res[idx] = 1;
 
			if((lca != -1) && (val[lca] == c))
			res[idx] = 1;
		}
 
		for(int i=1;i<=q;i++)
		if(res[i] == 1)
		cout<<"Find"<<el;
		else
		cout<<"NotFind"<<el;
    }
}

/*

*/