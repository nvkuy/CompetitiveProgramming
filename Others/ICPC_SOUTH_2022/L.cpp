#include<bits/stdc++.h>
#define ll long long 
#define nn "\n"
#define pb push_back
using namespace std;
#define X first 
#define Y second
#define PI 3.141592654
const ll N = 1e4 + 2  ;
#define int long long 

ll n , m , k ;
string s1 , s2 , s3 ;
vector<ll> path[N] ;
ll dp[N] ;
void Input(){ 
    //cin >> n >> s1 >> s2 >> s3 ;
} 
ll cal(ll ind) {
    return (ll)( s1[ind] - '0' ) + (ll)( s2[ind] - '0' ) ;
}
void solve(){
    while(cin >> n){
        if(n==0) break ;
        cin >> s1 >> s2 >> s3 ;
        for(int i=1;i<=n+1;i++) {
            path[i].clear();
        }
        s1 = "0" + s1 ;
        s2 = "0" + s2 ;
        s3 = "0" + s3 ;

        for(int i=n;i>=1;i--) {
            ll ans = cal(i) ;
            ans/=10 ;
            for(int j=i-1;j>=1;j--){
                ll tmp = cal(j) ;
                ll tmp2 = ( tmp  + ans )%10 ;
                if( (ll)(s3[j]-'0') == tmp2) path[i].pb(j) ;
            }
        }

        for(int i=1;i<=n;i++) dp[i] = 1e15 ;
        for(int i=1;i<=n;i++) {
            ll tmp = cal(i) ;
            if( tmp <10 && tmp==(s3[i]-'0')  ) dp[i] = i-1 ;
        }
        //for(int i=1;i<=n;i++) cout << dp[i]<<" ";cout<<nn;
        for(int i=1;i<=n;i++){
            for(auto x:path[i]) {
                dp[i] = min( dp[i] , dp[x] + i-x-1 ) ;
                ll ans = cal(i)/10 ;
                ll tmp = cal(x) ;
                if( (tmp+ans) < 10 && (tmp+ans)==(ll)(s3[x]-'0') ) dp[i] = min( dp[i] , (x-1) + i-x-1 ) ;
                //if(i==2) cout<<ans<<" "<<tmp<<nn;
            }
            //cout<<i<<nn;
        }

        ll res = n ;
        for(int i=1;i<=n;i++) {
            ll tmp = cal(i) ;
            if( tmp%10 != (s3[i]-'0') ) continue ;
            res = min( res , dp[i] + n-i ) ;
        }
        cout<<res<<nn;
        //cout<<cal(1) <<nn ;
        //  for(int i=1;i<=n;i++) cout << dp[i]<<" ";cout<<nn;
        // for(int i=1;i<=n;i++) {
        //     cout<<i<<nn;
        //     for(auto x:path[i]) cout<<x<<" ";cout<<nn;
        // }
    }
}       
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // if(fopen( "icecream.txt", "r"))
    // { freopen("icecream.txt", "r", stdin);  freopen( "chocolate.txt", "w", stdout); }
    int T=1;
    //cin>>T;
    while(T--) {  Input() ;  solve() ;  }
}