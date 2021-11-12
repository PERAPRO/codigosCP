/// Write by Daniel Perez .PERAPRO
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
	    int n,t,m;
	    cin>>n>>t>>m;
	    queue<pair<int,int>> left;
	    queue<pair<int,int>> right;
	    for(int i=0;i<m;i++){
	        int arr; cin>>arr;
	        string side;
	        cin>>side;
	        if(side=="left"){
	            left.push({arr,i});
	        }else{
	            right.push({arr,i});
	        }
	    }
	    int a=1000000;
	    int b=1000000;
	    if(left.size()) a=left.front().first;
	    if(right.size()) b=right.front().first;
	    int tim=min(a,b);
	    bool lef =true;
	    vi ans(m);
	    int car=0;
	    while(left.size() || right.size()){
	        if(left.size() && right.size()){
	            int izq=left.front().first; //left.top();
	            int der=right.front().first; //right.top();
	            if(lef){
	                if(izq<=tim){
                      int v=max(izq,tim);
	                    while(left.size() && left.front().first<=v && car<n){
	                        car++;
	                        ans[left.front().second]=v+t;
	                        left.pop();
	                    }
	                    tim+=t;
	                    car=0;
	                    lef=!lef;
	                }else if(der<=tim){
	                    tim+=t;
	                    lef=!lef;
	                    int v=max(der,tim);
	                    while(right.size() && right.front().first<=v && car<n){
	                        car++;
	                        ans[right.front().second]=v+t;
	                        right.pop();
	                    }
	                    tim+=t;
	                    car=0;
	                    lef=!lef;
	                }else tim=min(izq,der);
	            }else{
	                if(der<=tim){
                      int v=max(der,tim);
	                    while(right.size() && right.front().first<=v && car<n){
	                        car++;
	                        ans[right.front().second]=v+t;
	                        right.pop();
	                    }
	                    tim+=t;
	                    car=0;
	                    lef=!lef;
	                }else if(izq<=tim){
	                    tim+=t;
	                    lef=!lef;
	                    int v=max(izq,tim);
	                    while(left.size() && left.front().first<=v && car<n){
	                        car++;
	                        ans[left.front().second]=v+t;
	                        left.pop();
	                    }
	                    tim+=t;
	                    car=0;
	                    lef=!lef;
	                }else tim=min(izq,der);
	            }
	        }else if(left.size()){
	            if(lef){
	                int primero=left.front().first;
	                int v=max(primero,tim);
	                while(left.size() && left.front().first<=v && car<n){
	                    car++;
	                    ans[left.front().second]=v+t;
	                    left.pop();
	                }
	                tim+=t;
	                car=0;
	                lef=!lef;
	            }else if(!lef){
                  tim=max(left.front().first+t,tim+t);
                  lef=!lef;
	            }
	        }else{
	            if(!lef){
	                int primero=right.front().first;
	                int v=max(primero,tim);
	                while(right.size() && right.front().first<=v && car<n){
	                    car++;
	                    ans[right.front().second]=v+t;
	                    right.pop();
	                }
	                tim+=t;
	                car=0;
	                lef=!lef;
	            }else{
	              tim=max(right.front().first+t,tim+t);
	              lef=!lef;
	            }
	        }
	    }
	    for(auto cars:ans) cout<<cars<<endl;
	    if(testcases!=0)cout<<endl;
	}
}
