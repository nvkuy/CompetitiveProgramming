#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int sub_arr_size = min(k, n);
        long long ans = 0, cur_sum = 0;
        for (int i = 0; i < sub_arr_size; i++)
            cur_sum += a[i];
        int j = 0;
        ans = cur_sum;
        for (int i = sub_arr_size; i < n; i++) {
            cur_sum += (a[i] - a[j]);
            j++;
            ans = max(cur_sum, ans);
        }
        long long addition = max(k - n, k - 1);
        for (int i = 0; i < min(n, k); i++) {
            ans += addition;
            addition--;
        }
        cout << ans << endl;
    }

    return 0;
}
