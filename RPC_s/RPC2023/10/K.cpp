#include <bits/stdc++.h>

using namespace std ;

long long factorial [ 1000001 ] ;

int knights [ 5001 ] ;
long long MOD = 1000000007;
int main ( ){
    int n ;int h ;
    cin>>n>>h;
    long long aux = 1 ;
    factorial [ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; i++ ){
        aux *=i ;
        aux %= MOD ;
        factorial [ i ] = aux ;
    }
    int cont = 0 ;
    for ( int i=0 ; i < h ; i++ ){
        int x ;
        cin>>x ;
        knights [ i ] = x ;
        cont+= x;
    }
    if ( cont == n ){
        cout<<"0"<<endl ;
        return 0 ;
    }
    int k = n - cont ;
    int pos = 0 ;
    cont = 0 ;
    long long ans = 0;
    for ( int i = 0 ; i < n ; i++ ){
        while ( cont < i and pos != h){
            cont += knights [ pos ] ;
            if ( cont <= i ){
                pos++ ;
            }
            else{
                cont -= knights [ pos ] ;
                break;
            }
        }
        ans += factorial [ n - 1 ] ;
        ans %= MOD ;
        if ( n - cont - 1 != 0 ){
            ans -=  ( factorial [ cont ] * factorial [ n - cont - 1 ]  ) % MOD   ;
        }
        else{
            ans -=factorial [ cont ];
        }
        ans %= MOD ;
        if ( ans < 0 ) ans+= MOD ;

    }
    cout<<ans<<endl;
    return 0 ;
}

