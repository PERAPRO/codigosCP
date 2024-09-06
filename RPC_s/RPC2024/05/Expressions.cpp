/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int numeros, cambios;
    cin>>numeros>>cambios;
    int expresiones = numeros - 1;
    int total = numeros + expresiones;
    vector<string> v(total);
    
    for(int i = 0;i<total;i++){
        cin>>v[i];
        if(i % 2 == 0){
            v[i] = to_string(stoi(v[i]) & 1);
        }
    }
    
    vi grupos(total);
    map<int,int> szs;
    map<int,int> cnt_g;
    // cout<<v;
    int prev = 0;
    for(int i = 1;i<total;i+=2){
        if(v[i] == string("*")){
            if(prev){
                grupos[i] = grupos[i - 2];
                szs[grupos[i]]++;
            }else{
                grupos[i] = i;
                szs[i]++;
                prev = 1;
            }
        }else{
            prev = 0;
        }
    }
    vi grupos_numeros(total);
    for(int i = 1;i<total;){
        if(v[i] == string("*")){
            int cnt = 1;
            while(cnt < szs[grupos[i]]){
                cnt_g[grupos[i]] += (v[i - 1] == "1");
                grupos_numeros[i - 1] = grupos[i];
                i += 2;
                cnt++;
            }
            cnt_g[grupos[i]] += (v[i - 1] == "1");
            grupos_numeros[i - 1] = grupos[i];
            cnt_g[grupos[i]] += (v[i + 1] == "1");
            grupos_numeros[i + 1] = grupos[i];
        }
        i+=2;
    }
    for(auto&[key, value]:szs){
    //   cout<<key<<esp<<value<<el;   
        value++;
    }
    int ans = 0;
    vi grupo_visitado(total);
    for(int i = 0;i<total;i+=2){
        if(grupos_numeros[i]){
            if(grupo_visitado[grupos_numeros[i]]) continue;
            ans ^= (szs[grupos_numeros[i]] == cnt_g[grupos_numeros[i]]);
            grupo_visitado[grupos_numeros[i]] = 1;
        }else{
            ans ^= stoi(v[i]);
        }
    }
    cout<<(ans ? "odd" : "even")<<el;
    for(int i = 0;i<cambios;i++){
        int idx, num;
        cin>>idx>>num;
        idx--;
        int real_idx = idx * 2;
        num = num&1;
        if(grupos_numeros[real_idx]){
            // resto el anterior valor y me agrego y recalculo el xor
            ans ^= (szs[grupos_numeros[real_idx]] == cnt_g[grupos_numeros[real_idx]]);
            cnt_g[grupos_numeros[real_idx]] -= stoi(v[real_idx]);
            v[real_idx] = to_string(num);
            cnt_g[grupos_numeros[real_idx]] += stoi(v[real_idx]);
            ans ^= (szs[grupos_numeros[real_idx]] == cnt_g[grupos_numeros[real_idx]]);
        }else{
            //quitar el anteriory ponerme a mi;
            ans ^= stoi(v[real_idx]);
            v[real_idx] = to_string(num);
            ans ^= stoi(v[real_idx]);
        }
        cout<<(ans ? "odd" : "even")<<el;
    }
}

/*

*/