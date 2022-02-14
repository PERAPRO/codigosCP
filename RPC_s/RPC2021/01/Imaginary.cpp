#include<bits/stdc++.h>

using namespace std;

struct complexA{
        int real, i;
};

complexA compute(int a, int b){
	complexA c;
        if (b % 4 == 0) {
              c.real = a;
              c.i = 0;
        }
        else if( b % 2 == 0){
            c.real = -a;
            c.i = 0;
        } 
        else if (b % 4 == 1){
                c.real = a;
                c.i = 1;
        }
	else {
                c.real = -a;
                c.i = 1;
        }
	return c;

};

int main(){
        int a, b;
        cin>>a>>b;
        do{
                complexA c = compute(a, b);
                string k = c.i?"i":"";
                cout<<c.real<<k<<endl;
                cin>>a>>b;
        } while(a||b);

}
