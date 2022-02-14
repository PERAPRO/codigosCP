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
int eps=1e-6;
int main(){
	fast_io;
	double radio;
	cin>>radio;
	int n;
	cin>>n;
	vector<pii> points(n);
	for(auto &e:points) cin>>e.ff>>e.ss;
	int ans=0;
	vector<double> distancias(n);
	for(int i=0;i<n;i++){
	    distancias[i]=sqrt(points[i].ff*points[i].ff+points[i].ss*points[i].ss);
	}
	for(int i=0;i<n;i++){
	    if(distancias[i]<=radio-eps) ans++;
	}
	cout<<ans<<el;
}