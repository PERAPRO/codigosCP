#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

int main(){
	fast_io;
	int testcases;
    cin>>testcases;
    while(testcases--){
        unsigned long long s;
        cin>>s;
        cout<<s*(s+2)<<endl;
    }
}