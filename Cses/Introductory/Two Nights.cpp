#include <iostream>

using namespace std;

int main() {
    long long k;
    cin>>k;
    for(long long i=1;i<=k;i++){
        cout<<(((i*i)*((i*i)-1))/2)-(4*(i-2)*(i-1))<<endl;
    }
}