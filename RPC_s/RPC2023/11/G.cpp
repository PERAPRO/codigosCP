#include <bits/stdc++.h>

using namespace std ;
int r , c ;
long long MOD = 1000000007 ;
long long dp [ 2050 ] [ 10 ] [ 1001 ] ;
long long bus ( int mask , int x , int y ) {
    if ( x >= r ){
        y++;
        x  = 0 ;
    }
    if ( y >= c ) return 1 ;
    long long &ans = dp [ mask ] [ x ] [y ] ;
    if ( ans != -1 ) return ans;
    ans = bus ( ( mask >> 1 ) , x + 1 , y ) ;
    if ( x == 0 ){
        if ( !( (mask>>1) & 1 )  ){
            if ( r == 1 ){
                mask += (1<<(r+1) ) ;
                ans += bus ( ( mask >> 1 ) , x + 1 , y ) ;
            }
            else if ( !( (mask>>2) & 1 ) ){
                mask += (1<<(r+1) ) ;
                ans += bus ( ( mask >> 1 ) , x + 1 , y ) ;
            }
        }
    }
    else if ( x == r - 1 ){
        if ( !( mask & 1 ) && !( ( mask >> (r) ) & 1 ) && !( (mask>>1) & 1 ) ){
            mask += (1<<(r+1) ) ;
            ans += bus ( ( mask >> 1 ) , x + 1 , y ) ;
        }
    }
    else if ( !( mask & 1 ) && !( ( mask >> (r) ) & 1 ) && !( (mask>>1) & 1 ) && !( (mask>>2) & 1 ) ) {
        mask += (1<<(r+1) ) ;
        ans += bus ( ( mask >> 1 ) , x + 1 , y ) ;
    }
    ans %= MOD;
    return ans ;
}
int main ( ){
    #ifdef LOCAL
        freopen ( "input.txt" , "r" , stdin ) ;
    #endif
    memset ( dp , -1 , sizeof dp ) ;
    cin>>r>>c ;
    cout<<bus ( 0 , 0 , 0 )<<endl;
    return 0 ;
}
