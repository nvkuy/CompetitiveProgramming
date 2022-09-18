#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long ans = 0;
    int n, ai, curMod = 0;
    map<int, int> cnt;
    cnt[0]++;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        curMod = (((curMod + ai) % n) + n) % n;
        ans += cnt[curMod];
        cnt[curMod]++;
        //cout << ans << '|' << curMod << endl;
    }
    cout << ans;

    return 0;
}
