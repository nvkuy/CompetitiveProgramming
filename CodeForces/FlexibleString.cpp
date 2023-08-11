#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> allow_mask[11];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // vector<vector<int>> allow_mask(11);
    for (int i = 0; i <= 10; i++) {
        for (int mask = 0; mask < (1 << 10); mask++)
            if (__builtin_popcount(mask) <= i) allow_mask[i].push_back(mask);
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        set<char> tmp;
        for (auto c : a) tmp.insert(c);
        long long ans = 0;
        vector<char> char_in_a(tmp.begin(), tmp.end());
        int tt = char_in_a.size();
        for (int mask : allow_mask[k]) {
            if (mask >= (1 << tt)) break;
            // vector<int> allow_change(26, 0), next_diff(n, n);
            // for (int j = 0; j < char_in_a.size(); j++)
            //     if ((mask >> j) & 1) allow_change[char_in_a[j] - 'a'] = 1;
            // for (int j = 0; j < n; j++) {
            //     if (a[j] != b[j] && !allow_change[a[j] - 'a'])
            //         next_diff[j] = j;
            // }
            // for (int j = n - 2; j >= 0; j--)
            //     next_diff[j] = min(next_diff[j], next_diff[j + 1]);
            // long long tans = 0;
            // for (int j = 0; j < n; j++)
            //     tans += next_diff[j] - j;
            // ans = max(ans, tans);
            vector<int> allow_change(26, 0);
            for (int j = 0; j < tt; j++)
                if ((mask >> j) & 1) allow_change[char_in_a[j] - 'a'] = 1;
            long long tans = 0, con = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i] && !allow_change[a[i] - 'a'])
                    con = 0;
                else
                    con++;
                tans += con;
            }
            ans = max(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}

// WHY THIS CODE RUN THAT FAST?????
// #include <bits/stdc++.h>
// #define ll long long
// #define endl '\n'
// #define pll pair<long long,long long>
// #define pii pair<int,int>
// #define FOR(i,a,b) for(int i =a; i<=b; i++)
// #define ROF(i,a,b) for(int i =a; i>=b; i--)

// const long long MOD = 1e9+7;

// using namespace std;
// int n,k;
// string a;
// string b;
// bool bg[100003];
// bool check[100003];
// vector<int> cnt[1000];
// vector<int> bitmx[12];
// vector<char> cur;
// void rst(){
//     for (int i = 'a'; i<='z'; i++) {
//         cnt[i].clear();
//     }
//     for (int i =0; i<=n; i++) bg[i]=check[i]=0;
//     cur.clear();
// }

// void solve(){
//     cin>>n>>k;
//     cin>>a;
//     cin>>b;
//     rst();
//     for (int i =0; i<n; i++){
//         if (a[i]!=b[i]){
//             cnt[a[i]].push_back(i);

//         }
//         else bg[i]=1;
//     }
//     for (int i ='a'; i<='z'; i++){
//         if (cnt[i].size()) cur.push_back(i);
//     }
//     int t = cur.size();
//     ll lres=0;
//     if (k>t) k=t;
//     for (auto x: bitmx[k]){
//         if (x>= (1<<t)){
//             break;
//         }
//         // cout<<x<<endl;
//         for (int i =0; i<n; i++) {
//             check[i]=bg[i];
//         }
//         for (int i =0; i<t; i++){
//             if ((1<<i)&x){
//                 for (auto pp : cnt[cur[i]]){// thanh phan cua chu
//                     check[pp]=1;
//                 }
//             }
//         }
//         int cr=0;
//         ll res=0;
//         for (int i =0; i<n; i++){
//             if (check[i]==1){
//                     cr++;
//                     res+=cr;
//             }
//             else {
//                 cr =0;
//             }
//         }
//         lres = max(res,lres);
//     }
//     cout<<lres<<endl;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     if(fopen("input.txt", "r")) {
//         freopen("input.txt","r",stdin);
//         freopen("output.txt","w",stdout);
//     }
//     for (int i =0; i<=1024; i++){
//         bitmx[__builtin_popcount(i)].push_back(i);
//     }
//     int t=1;
//     cin>>t;
//     while(t--)
//         solve();
//     return 0;
// }
