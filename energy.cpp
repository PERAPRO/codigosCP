#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int testcases;
    cin>>testcases;
    while(testcases--){
        int consumo;
        cin>>consumo;
        cout<<consumo;
        if(consumo<=1000){
            cout<<" "<<consumo*a<<endl;
        }else{
            int exceso=consumo-1000;
            cout<<" "<<(1000*a)+(exceso*b)<<endl;
        }
    }
}