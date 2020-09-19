/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	double r;
	cin>>r;
	double diametro=2*r;
	double k=1.0731338;
	double lado=(2*diametro)+(diametro/k);
	printf("%.5lf\n",lado*lado);
}
