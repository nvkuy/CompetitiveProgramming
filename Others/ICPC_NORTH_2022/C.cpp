#include<bits/stdc++.h>
#define ll long long 
#define nn "\n"
#define pb push_back
using namespace std;
#define X first 
#define Y second
#define PI 3.141592654
const ll N = 2e5 +2  ;

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

ll n , k ;
ll u[N] , v[N] ;
map< pair<ll,ll> , bool > d ;
ll check(ll x,ll y) {
    ll res = 0 ;
    if( d[{x-1,y}] == 1) res++;
    if( d[{x,y-1}] == 1) res++;
    if( d[{x+1,y}] == 1) res++;
    if( d[{x,y+1}] == 1) res++;
    return res ;
}
void Input(){ 
}
void solve(){ 
    while(cin>>n){
        d.clear() ;
        vector<pair<ll, ll>> cor(n);
        for(int i=0;i<n;i++) {
            cin >> cor[i].first >> cor[i].second;
            d[cor[i]] = 1 ;
        }
        sort(cor.begin(), cor.end(), cmp);
        ll res = n ;
        for(int i = 0; i < n; i++){
            if ( d[cor[i]]==0 ) continue ;
            if(check(cor[i].first, cor[i].second)==4) {
                d[cor[i]] = 0 ;
                res--;
            }
        }
        for(int i=0;i<n;i++){
            if ( d[cor[i]]==0 ) continue ;
            if(check(cor[i].first, cor[i].second)==3) {
                d[cor[i]] = 0 ;
                res--;
            }
        }
        for(int i=0;i<n;i++){
            if ( d[cor[i]]==0 ) continue ;
            if(check(cor[i].first, cor[i].second)==2) {
                d[cor[i]] = 0 ;
                res--;
            }
        }
        for(int i=0;i<n;i++){
            if ( d[cor[i]]==0 ) continue ;
            if(check(cor[i].first, cor[i].second)==1) {
                d[cor[i]] = 0 ;
                res--;
            }
        }
        cout << res << nn ;
    }
    
}       
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(fopen( "input.txt", "r"))
    { freopen("input.txt", "r", stdin);  freopen( "output.txt", "w", stdout); }
    int T=1;
    //cin>>T;
    while(T--) {  Input() ;  solve() ;  }
}
