#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int x, y;
vector<int> a;

long long cal(int l, int r) {
    long long ans = 0;
    int j = l, x_cnt = 0, y_cnt = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] == x)
            x_cnt++;
        if (a[i] == y)
            y_cnt++;
        while (x_cnt > 0 && y_cnt > 0) {
            ans += (r - i + 1);
            if (a[j] == x)
                x_cnt--;
            if (a[j] == y)
                y_cnt--;
            j++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
    freopen("input.txt", "w", stdout);
    cout << 2e5 <<  " 1 1" << endl;
    for (int i = 0; i < 2e5; i++)
        cout << "1 ";
    return 0;
    */
    //freopen("input.txt", "r", stdin);

    int n, l, r = -2;
    cin >> n >> x >> y;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i < n && a[i] <= x && a[i] >= y)
            continue;
        l = r + 2;
        r = i - 1;
        ans += cal(l, r);
    }
    cout << ans;

    return 0;
}
