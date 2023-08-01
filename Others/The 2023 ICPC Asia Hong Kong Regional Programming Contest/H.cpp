#include<bits/stdc++.h>
#define ll int
#define nn "\n"
#define pb push_back
using namespace std;
#define X first 
#define Y second
#define PI 3.141592654
const ll N = 2e5 + 1 ;
#define int int

ll n , m ;
ll a[N] ;
void Input(){ 
    //cin >> n >> m ;
    //for(int i=1;i<=n;i++) cin >> a[i] ;
} 
void solve(){
    ll l ,r , b , k ;
    cin >> l >> r >> b >> k ;

    ll ans = l/b ;
    if(l%b) ans++ ;
    cout<<ans*b*k<<nn;
}       
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(fopen( "icecream.txt", "r"))
    { freopen("icecream.txt", "r", stdin);  freopen( "chocolate.txt", "w", stdout); }
    int T=1;
    //cin>>T;
    while(T--) {  Input() ;  solve() ;  }
}
