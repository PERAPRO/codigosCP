/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
#define pb push_back
typedef long long ll;

string ans="";
int n;
bool isspecial(char c){
    if( c=='/' || c=='*') return true;
    else return false;
}


bool dp(int i, string s){
    if(i==3){
        int especiales=0;
        for(int i=0;i<3;i++) if(isspecial(s[i])) especiales++;
        if(especiales==0 || especiales==3){
            int k=4;
            for(int i=0;i<3;i++){
                if(s[i]=='+') k+=4;
                else if(s[i]=='-') k-=4;
                else if(s[i]=='*') k*=4;
                else if(s[i]=='/') k/=4;
            }
            if(k==n){
                ans=s;
                return true;
            }
            return false;
        }else if(especiales==1){
            int k=4;
            if(isspecial(s[0])){
                for(int i=0;i<3;i++){
                    if(s[i]=='+') k+=4;
                    else if(s[i]=='-') k-=4;
                    else if(s[i]=='*') k*=4;
                    else if(s[i]=='/') k/=4;
                }
            }else if(isspecial(s[1])){
                if(s[1]=='+') k+=4;
                else if(s[1]=='-') k-=4;
                else if(s[1]=='*') k*=4;
                else if(s[1]=='/') k/=4;
                if(s[0]=='+') k=4+k;
                else if(s[0]=='-') k=4-k;
                else if(s[0]=='*') k=4*k;
                else if(s[0]=='/') k=4/k;
                if(s[2]=='+') k+=4;
                else if(s[2]=='-') k-=4;
                else if(s[2]=='*') k*=4;
                else if(s[2]=='/') k/=4;
            }else{
                int aux=4;
                if(s[2]=='+') k+=4;
                else if(s[2]=='-') k-=4;
                else if(s[2]=='*') k*=4;
                else if(s[2]=='/') k/=4;
                if(s[0]=='+') aux+=4;
                else if(s[0]=='-') aux-=4;
                if(s[2]=='+') k=aux+k;
                else if(s[2]=='-') k=aux-k;
            }
            if(k==n){
                ans=s;
                return true;
            }
            return false;
        }
        else{
            int k=4;
            if(isspecial(s[0]) && isspecial(s[1])){
                for(int i=0;i<3;i++){
                    if(s[i]=='+') k+=4;
                    else if(s[i]=='-') k-=4;
                    else if(s[i]=='*') k*=4;
                    else if(s[i]=='/') k/=4;
                }
            }else if(isspecial(s[0]) && isspecial(s[2])){
                int aux=4;
                if(s[0]=='*') k*=4;
                else k/=4;
                if(s[2]=='*') aux*=4;
                else aux/=4;
                if(s[1]=='+') k=k+aux;
                else k=k-aux;
            }else{
                for(int i=1;i<3;i++){
                    if(s[i]=='+') k+=4;
                    else if(s[i]=='-') k-=4;
                    else if(s[i]=='*') k*=4;
                    else if(s[i]=='/') k/=4;
                }
                if(s[0]=='+') k=4+k;
                else k=4-k;
            }
            if(k==n){
                ans=s;
                return true;
            }
            return false;
        }
    }
    s.pb('+');
    bool a= dp(i+1,s);
    s.pop_back();
    s.pb('-');
    bool b= dp(i+1,s);
    s.pop_back();
    s.pb('*');
    bool c= dp(i+1,s);
    s.pop_back();
    s.pb('/');
    bool d= dp(i+1,s);
    s.pop_back();
    //cout<<i<<" "<<s<<endl;
    return a||b||c||d;
}

int main(){
	fast_io;
	int testcases;
	cin>>testcases;
	while(testcases--){
	    ans="";
	    cin>>n;
	    if(dp(0,"")){
	        cout<<4<<" "<<ans[0]<<" "<<4<<" "<<ans[1]<<" "<<4<<" "<<ans[2]<<" "<<4<<" = "<<n<<endl;
	    }else{
	        cout<<"no solution\n";
	    }
	}
}