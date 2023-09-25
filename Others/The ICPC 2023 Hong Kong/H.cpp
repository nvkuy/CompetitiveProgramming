#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
char a[20][20] ;
bool check[20][20] , b[20][20] ;
bool ch41(ll i,ll j){
    if(i+3>10) return 0 ;
    if(a[i][j]=='#'&& a[i+1][j]=='#' && a[i+2][j]=='#' && a[i+3][j]=='#') return 1 ;
    return 0; 
}
bool ch42(ll i,ll j){
    if(j+3>10) return 0 ;
    if(a[i][j]=='#'&& a[i][j+1]=='#' && a[i][j+2]=='#' && a[i][j+3]=='#') return 1 ;
    return 0; 
}

bool ch31(ll i,ll j){
    if(i+2>10) return 0 ;
    if(a[i][j]=='#'&& a[i+1][j]=='#' && a[i+2][j]=='#') return 1 ;
    return 0; 
}
bool ch32(ll i,ll j){
    if(j+2>10) return 0 ;
    if(a[i][j]=='#'&& a[i][j+1]=='#' && a[i][j+2]=='#') return 1 ;
    return 0; 
}

bool ch21(ll i,ll j){
    if(i+1>10) return 0 ;
    if(a[i][j]=='#'&& a[i+1][j]=='#') return 1 ;
    return 0; 
}
bool ch22(ll i,ll j){
    if(j+1>10) return 0 ;
    if(a[i][j]=='#'&& a[i][j+1]=='#') return 1 ;
    return 0; 
}


int main()
{
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin >> a[i][j] ;
        }
    }
    map<pair<ll,ll>,ll> d ;
    map<ll,ll> cnt , cnt2;
    ll tmp = 1 ;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(check[i][j]) continue;

            if(ch41(i,j)) {
                check[i][j] = check[i+1][j] = check[i+2][j] = check[i+3][j] = 1 ;
                d[{i,j}] = d[{i+1,j}] = d[{i+2,j}] = d[{i+3,j}] = ++tmp;
                cnt[tmp] =4 ;
            }
            else if(ch42(i,j)){
                check[i][j] = check[i][j+1] = check[i][j+2] = check[i][j+3] = 1 ;
                d[{i,j}] = d[{i,j+1}] = d[{i,j+2}] = d[{i,j+3}] = ++tmp;  
                cnt[tmp] =4 ;   
            }

            else if(ch31(i,j)) {
                check[i][j] = check[i+1][j] = check[i+2][j] = 1 ;
                d[{i,j}] = d[{i+1,j}] = d[{i+2,j}] = ++tmp;  
                cnt[tmp] =3 ;
            }
            else if(ch32(i,j)){
                check[i][j] = check[i][j+1] = check[i][j+2] = 1 ;
                d[{i,j}] = d[{i,j+1}] = d[{i,j+2}] = ++tmp;  
                cnt[tmp] =3 ;  
            }
            
            else if(ch21(i,j)) {
                check[i][j] = check[i+1][j] = 1 ;
                d[{i,j}] = d[{i+1,j}] = ++tmp;  
                cnt[tmp] =2 ;     
            }
            else if(ch22(i,j)) {
                check[i][j] = check[i][j+1] = 1 ;
                d[{i,j}] = d[{i,j+1}]  = ++tmp;  
                cnt[tmp] =2 ;   
            }
            else {
                check[i][j] = 1 ;
                d[{i,j}] = ++tmp ;
                cnt[tmp] =1 ;
            }
        }
    }
    ll t1 = 10 , t2= 0 , t3 = 0 ;
    ll q ;
    cin >> q ;
    for(int i=1;i<=q;i++){
        string t ;
        ll x , y ;
         cin >> t ;
         if(t=="SHOW"){
            cout << t1 <<" "<<t2<<" "<<t3<<endl;
         }
         else {
            cin >> x >> y ;
            if(b[x][y]) {

            }
            else {
                b[x][y] = 1 ;
                ll index = d[{x,y}] ;
                cnt2[index]++ ;
                //cout<<x<<" "<<y<<endl;
                if(cnt2[index] == cnt[index]) {
                    if(cnt[index] == 1){
                        t1--;
                        t3++;
                    }
                    else {
                        t2--;
                        t3++;
                    }
                }
                else {
                    t2++;
                    t1--;
                }
            }
         }

    }



    return 0;
}
