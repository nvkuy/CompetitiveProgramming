#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<int> a;

int numTwo(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; i++)
        ans += (abs(a[i]) == 2);
    return ans;
}

pair<int, pair<int, int>> cal(int l, int r) {
    int numNeg = 0, firstNeg = 1e9, lastNeg = -1;
    for (int i = l; i <= r; i++) {
        if (a[i] < 0) {
            numNeg++;
            lastNeg = i;
            firstNeg = min(firstNeg, i);
        }
    }
    if (numNeg % 2) {
        if (numTwo(l, firstNeg) > numTwo(lastNeg, r))
            return make_pair(numTwo(l, lastNeg - 1), make_pair(l, lastNeg - 1));
        return make_pair(numTwo(firstNeg + 1, r), make_pair(firstNeg + 1, r));
    }
    return make_pair(numTwo(l, r), make_pair(l, r));
}

pair<int, int> getAns(pair<int, int> ans) {
    return make_pair(ans.first, n - ans.second - 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        vector<int> posZero;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                posZero.push_back(i);
        }
        if (posZero.size() == 0) {
            pair<int, pair<int, int>> tmp = cal(0, n - 1);
            pair<int, int> ans = getAns(tmp.second);
            cout << ans.first << ' ' << ans.second << endl;
        } else {
            int maxProduct = 0; //2^x
            pair<int, int> ans = make_pair(0, 0);
            pair<int, pair<int, int>> tmp = cal(0, posZero[0] - 1);
            if (tmp.first > maxProduct) {
                maxProduct = tmp.first;
                ans = tmp.second;
            }
            tmp = cal(posZero.back() + 1, n - 1);
            if (tmp.first > maxProduct) {
                maxProduct = tmp.first;
                ans = tmp.second;
            }
            for (int i = 1; i < posZero.size(); i++) {
                tmp = cal(posZero[i - 1] + 1, posZero[i] - 1);
                if (tmp.first > maxProduct) {
                    maxProduct = tmp.first;
                    ans = tmp.second;
                }
            }
            ans = getAns(ans);
            cout << ans.first << ' ' << ans.second << endl;
        }
    }

    return 0;
}
