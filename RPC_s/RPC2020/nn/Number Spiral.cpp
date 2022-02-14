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
	    ll row;
	    cin>>row;
	    ll column;
	    cin>>column;
	    if(column>row){
	        if(column%2){
	            cout<<(column*column)-row+1<<endl;
	        }else{
	            cout<<((column-1)*(column-1))+row<<endl;
	        }
	    }else if(row>column){
	        if(row%2==0){
	            cout<<(row*row)-column+1<<endl;
	        }else{
	            cout<<((row-1)*(row-1))+column<<endl;
	        }
	    }else{
	        cout<<(row*column)-row+1<<endl;
	    }
	}
}