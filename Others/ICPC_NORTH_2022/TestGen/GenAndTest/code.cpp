#include<bits/stdc++.h>
#define ll long long 
#define nn "\n"
#define pb push_back
using namespace std;
#define X first 
#define Y second
#define PI 3.141592654
const ll N = 5e5 +2  ;

ll n , k ;
ll sum[N] , pre[N] , dp[N] ;
string s ;
ll mod= 1e9 + 7 ;
void Input(){ 
    cin >> s ;
    n = s.size() ; s="0"+s ;
}
void solve(){ 
    for(int i=1;i<=n;i++) {
        pre[i] = pre[i-1] + (s[i]-'a'+1) ;
    }
    for(int i=1;i<=n;i++){
        dp[i] = ( dp[i-1] + sum[i-1] + (s[i]-'a'+1)*i*(i+1)/2 ) % mod ;
        sum[i] = ( sum[i-1] + (s[i]-'a'+1) * i ) % mod ;
    }
    ll res = 0 ;
    for(int i=1;i<=n;i++){
        res = (res+dp[i]) % mod ;
    }
    cout<<res<<nn;
    // for(int i=1;i<=n;i++) cout<<dp[i]<<" ";cout<<nn;
    // for(int i=1;i<=n;i++) cout<<sum[i]<<" ";cout<<nn;
}       
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(fopen( "icecream.txt", "r"))
    { freopen("icecream.txt", "r", stdin);  freopen( "chocolate.txt", "w", stdout); }
    int T=1;
    cin>>T;
    while(T--) {  Input() ;  solve() ;  }
}
