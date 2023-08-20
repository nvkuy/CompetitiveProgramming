#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> a, tmp;
int n, ans = 0;

void bf(int pos) {
    if (pos == n) {
        vector<int> v1, v2, v3;
        for (int i = 0; i < n; i++)
            if (tmp[i] == 0)
                v1.push_back(a[i]);
            else if (tmp[i] == 1)
                v2.push_back(a[i]);
            else
                v3.push_back(a[i]);
        if (min(v1.size(), min(v2.size(), v3.size())) == 0)
            return;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());
        for (int i = 0; i < v1.size(); i++)
            for (int j = 0; j < v2.size(); j++)
                for (int k = 0; k < v3.size(); k++)
                    ans = max(ans, abs(v1[i] - v2[j]) + abs(v2[j] - v3[k]));
        return;
    }
    for (int i = 0; i < 3; i++) {
        tmp[pos] = i;
        bf(pos + 1);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    a.resize(n);
    tmp = a;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bf(0);
    cout << ans << endl;

    return 0;
}