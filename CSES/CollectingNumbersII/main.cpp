#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, ans = 1, t1, t2;
    cin >> n >> m;
    vector<int> arr(n);
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        a.push_back(make_pair(arr[i], i));
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i].second < a[i - 1].second)
            ans++;
    }
    while (m--) {
        cin >> t1 >> t2;
        swap(arr[t1 - 1], arr[t2 - 1]);
        t1 = arr[t1 - 1], t2 = arr[t2 - 1];
        if (t1 > t2)
            swap(t1, t2);
        if (t2 - t1 <= 2) {
            for (int i = max(2, t1 - 1); i <= min(n, t2 + 1); i++)
                if (a[i - 1].second < a[i - 2].second)
                    ans--;
            swap(a[t1 - 1].second, a[t2 - 1].second);
            for (int i = max(2, t1 - 1); i <= min(n, t2 + 1); i++)
                if (a[i - 1].second < a[i - 2].second)
                    ans++;
        } else {
            for (int i = max(2, t1 - 1); i <= min(n, t1 + 1); i++)
                if (a[i - 1].second < a[i - 2].second)
                    ans--;
            for (int i = max(2, t2 - 1); i <= min(n, t2 + 1); i++)
                if (a[i - 1].second < a[i - 2].second)
                    ans--;
            swap(a[t1 - 1].second, a[t2 - 1].second);
            for (int i = max(2, t1 - 1); i <= min(n, t1 + 1); i++)
                if (a[i - 1].second < a[i - 2].second)
                    ans++;
            for (int i = max(2, t2 - 1); i <= min(n, t2 + 1); i++)
                if (a[i - 1].second < a[i - 2].second)
                    ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
