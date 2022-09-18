#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;
string s;

bool check(int seg_size) {
    int useOp = 0;
    for (int i = 0; i < seg_size; i++) {
        vector<int> cnt(33, 0);
        for (int j = i; j < n; j += seg_size)
            cnt[s[j] - 'a']++;
        int max_char = 0, other = 0;
        for (int j = 0; j < 33; j++) {
            other += cnt[j];
            max_char = max(max_char, cnt[j]);
        }
        useOp += (other - max_char);
        if (useOp > k)
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin.ignore();
    getline(cin, s);
    int ans = 1e9;
    for (int i = 1; i * i <= n; i++) {
        if (n % i > 0)
            continue;
        if (check(i)) {
            ans = i;
            break;
        }
        if (i != n / i && check(n / i))
            ans = min(ans, n / i);
    }
    cout << ans << endl;

    return 0;
}
