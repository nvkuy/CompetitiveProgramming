#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;
vector<int> a;
vector<pair<int, int>> ans;

int eval(int ai, int l, int r) {
    if (ai >= l && ai <= r)
        return 1;
    return -1;
}
/*
bool canPartition(int l, int r) {
    if (l > r)
        return false;
    long long cs = 0;
    int j = 0, par = 0;
    for (int i = 0; i < n; i++) {
        if (k - par == 1) {
            j = i;
            break;
        }
        cs += eval(a[i], l, r);
        if (cs <= 0)
            continue;
        par++;
        j = i + 1;
        cs = 0;
    }
    for (; j < n; j++)
        cs += eval(a[j], l, r);
    par++;
    if (cs <= 0)
        return false;
    return par >= k;
}
*/
void getAns(int l, int r) {
    long long cs = 0;
    int j = 0, par = 0;
    for (int i = 0; i < n; i++) {
        if (k - par == 1) {
            j = i;
            break;
        }
        cs += eval(a[i], l, r);
        if (cs <= 0)
            continue;
        ans.push_back({j + 1, i + 1});
        par++;
        j = i + 1;
        cs = 0;
    }
    ans.push_back({j + 1, n});
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n), ans.clear();
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> sorted_arr = a;
        sort(sorted_arr.begin(), sorted_arr.end());
        int minxy = n, x, y;
        for (int i = 0; i < n; i++) {
            int j = ((n + k + 1) / 2) + i - 1;
            if (j >= n)
                break;
            if (sorted_arr[j] - sorted_arr[i] < minxy) {
                x = sorted_arr[i], y = sorted_arr[j];
                minxy = y - x;
            }
        }
        getAns(x, y);
        cout << x << ' ' << y << endl;
        for (int i = 0; i < k; i++)
            cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}
