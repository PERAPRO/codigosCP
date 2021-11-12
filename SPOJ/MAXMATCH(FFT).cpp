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
using comp = complex<double>;
using poly = vector<comp>;
const double PI=acos(-1);

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";


void FFT(vector<comp> & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	vector<comp> wp(n>>1);
	for(int k = 1; k < n; k <<= 1){
		for(int j = 0; j < k; ++j)
			wp[j] = polar(1.0, PI * j / k * inv);
		for(int i = 0; i < n; i += k << 1){
			for(int j = 0; j < k; ++j){
				comp t = X[i + j + k] * wp[j];
				X[i + j + k] = X[i + j] - t;
				X[i + j] += t;
			}
		}
	}
	
	if(inv == -1)
		for(int i = 0; i < n; ++i)
			X[i] /= n;
	//cout<<inv<<endl;
}


vector<int> operator*(const vector<int>& A, const vector<int>& B){
  int m = A.size(), n = B.size();
  int sz = m+n-1;
  int SZ=1;
  while(SZ<sz) SZ<<=1;
  poly a(SZ), b(SZ);
  for(int i = 0; i < m; ++i){
    a[i] = A[i];
  }
  for(int i = 0; i < n; ++i){
    b[i] = B[i];
  }
  //for(auto c: a) cout<<c<<el;
  FFT(a,1);
  FFT(b,1);
  poly c(SZ);
  for(int i = 0; i < SZ; ++i){
    c[i] = a[i]*b[i];
  }
  //cout<<yes<<endl;
  FFT(c,-1);
  //cout<<yes<<endl;
  vi ans(SZ);
  for(int i=0;i<sz;i++) ans[i]=c[i].real()+0.5;
  ans.resize(sz);
  return ans;
}


/*
poly operator*(poly A, poly B){
    int m = A.size(), n = B.size();
    int sz = m+n-1;
    // rellenamos con ceros hasta la potencia de 2 más cercana
    int SZ = nearestPowerOfTwo(sz);
    A.resize(SZ);
    B.resize(SZ);
    // transformamos A y B
    poly An = FFT(A, 1);
    poly Bn = FFT(B, 1);
    poly Cn(SZ);
    // multiplicación punto a punto
    for(int i = 0; i < SZ; ++i){
        Cn[i] = An[i] * Bn[i];
    }
    // transformada inversa
    poly C = FFT(Cn, -1);
    C.resize(sz);
    return C;
}*/

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    string s;
    cin>>s;
    int n=s.size();
    int sz=1;
    while(sz<n) sz<<=1;
    vi a(n);
    vi b(n);
    vi c(n);
    for(int i=0;i<n;i++){
        if(s[i]=='a') a[i]=1;
        if(s[i]=='b') b[i]=1;
        if(s[i]=='c') c[i]=1;
    }
    vi ar=a; vi br=b; vi cr=c;
    reverse(ar.begin(),ar.end()); reverse(br.begin(),br.end()); reverse(cr.begin(),cr.end());
    vi as=a*ar;
    vi bs=b*br;
    vi cs=c*cr;
    vi ans(n);
    //cout<<a<<ar<<as<<el;
    for(int i=1;i<n;i++){
        ans[i]=as[i+n-1]+bs[i+n-1]+cs[i+n-1];
    }
    //cout<<ans<<el;
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,ans[i]);
    }
    vi aans;
    for(int i=1;i<n;i++){
        if(ans[i]==mx) aans.pb(i);
    }
    cout<<mx<<el;
    for(auto i:aans) cout<<i<<el;
}

/*

*/