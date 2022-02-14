/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;



int main(){
	fast_io;
	float x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	float x3,y3,x4,y4;
	cin>>x3>>y3>>x4>>y4;
	float ans=0;
	float p1=(y2-y1)/(x2-x1);
	float p2=(y4-y3)/(x4-x3);
	float px=(-(p2*x3)+y3+(p1*x1)-y1)/(p1-p2);
	//cout<<p1<<" "<<p2<<" "<<px<<endl;
	float yen1 = (p1*(px-x1)+y1);
	float yen2 = (p2*(px-x3)+y3);
	//cout<<yen1<<" "<<yen2<<endl;
	if(((px<=x2+0.000005 && px>=x1+0.000005) && (yen1>=y1-0.000005 && yen1<=y2+0.000005)) && 
	((px-0.000005<=x3 && px>=x4-0.000005) && (yen1>=y3-0.000005 && yen1<=y4+0.000005))){
	    if(y2<y4){
	        float xaux = ((y2-y3)+p2*x3)/(p2);
	        float base(abs(xaux-x2));
	        float pal = base/2;
	        float altura = (y2-yen2);
	        ans=(base*altura)/2;
	    }else{
	        float xaux = ((y4-y1)+p1*x1)/(p1);
	        float base(abs(xaux-x4));
	        float pal = base/2;
	        float altura = (y4-yen2);
	        ans=(base*altura)/2;
	    }
	}else{
	    ans=0;
	}
	cout<<ans<<endl;
}