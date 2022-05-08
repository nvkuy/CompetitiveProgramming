#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int genNext(int ai) {
    int ans = ai;
    string tmp = to_string(ai);
    reverse(tmp.begin(), tmp.end());
    ans += stoi(tmp);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int maxNBF = 1e6;
    vector<int> ps(maxNBF + 1, 0);
    for (int i = 1; i <= maxNBF; i++) {
        int f = i;
        while (f <= maxNBF) {
            ps[f]++;
            f = genNext(f);
        }
    }
    for (int i = 1; i <= maxNBF; i++)
        ps[i] += ps[i - 1];
    int t, l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << ps[min(r, maxNBF)] - ps[min(l - 1, maxNBF)] << endl;
    }

    return 0;
}
