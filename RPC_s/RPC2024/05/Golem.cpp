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

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";


int main(){
	fast_io;
	int n;
	cin>>n;
	vi cnt(21);
	vi v(n);
	for(int i = 0;i<n;i++){
	    cin>>v[i];
	    cnt[v[i]]++;
	}
	sort(all(v));
	vi ans;
	int used = 0;
	int start = v[0];
	while(cnt[start]) cnt[start]--,used++,ans.pb(start);
// 	cout<<ans;
	while(used != n){
	   // cout<<"used"<<esp<<used<<endl;
	    int cur = ans.back();
	    for(int i = cur;i>0;i--){
	       // cout<<"divisor : "<<i<<endl;
	        if(cur % i == 0){
	            int find = 0;
	            for(int j = 1;j<=20;j++){
	                if(j % i == 0 && cnt[j]){
	                    find = 1;
	                   // cout<<"j : "<<j<<esp<<cnt[j]<<endl;
	                    while(cnt[j]) used++, cnt[j]--, ans.pb(j);
	                   // cout<<yes<<endl;
	                    break;
	                }
	            }
	            if(find) break;
	        }
	    }
	   // process:
	}
// 	cout<<ans;
    int anss = 0;
    for(int i = n - 1;i>0;i--){
        anss += __gcd(ans[i], ans[i - 1]);
    }
    cout<<anss<<el;
}

/*

*/