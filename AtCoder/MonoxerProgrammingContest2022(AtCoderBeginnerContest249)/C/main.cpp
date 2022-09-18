#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;
    cin.ignore();
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        getline(cin, arr[i]);
    for (int choose = 0; choose < (1 << n); choose++) {
        bitset<16> bs(choose);
        if (bs.count() < k)
            continue;
        vector<int> cnt(33, 0);
        for (int i = 0; i < arr.size(); i++) {
            if (!bs[i])
                continue;
            for (int j = 0; j < arr[i].length(); j++)
                cnt[arr[i][j] - 'a']++;
        }
        int tans = 0;
        for (int i = 0; i < 33; i++)
            tans += (cnt[i] == k);
        ans = max(tans, ans);
    }
    cout << ans;

    return 0;
}
