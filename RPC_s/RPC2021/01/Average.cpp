#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
using namespace std;
ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<endl;
    return os;
}
int main(){
    int cases;cin>>cases;
    while(cases--){
        int a,s; cin>>a>>s;
        vi ptos; vi grades;
        int tmp;
        int ptosTotales = 0;
        REP(i,a){
            cin>>tmp;ptos.pb(tmp);ptosTotales+=tmp;
        }
        while(s--){
            float student = 0;
            REP(i,a){
                cin>>tmp;
                student += (tmp*ptos[i]);
            }
            float ans = student/ptosTotales;
            int ans2 = ans;
            int tmp1 = ans/5; int tmp2=ans/5+1;
            int ansF;
            if(ans==ans2 && ans2%5==0){
                cout<<ans<<" SAME"<<endl;
            }
            else if(abs(ans-(tmp1*5))>abs(ans-(tmp2*5))){
                ansF = tmp2*5;
                cout<<ansF<<" UP"<<endl;
            }else{
                ansF = tmp1*5;
                cout<<ansF<<" DOWN"<<endl;
            }
            //ans = min(abs(ans-(tmp1*5)),abs(ans-(tmp2*5)));

        }
    }


    return 0;
}

