#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, i, j;
    cin >> n >> k;
    i = 3, j = n - 1;
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(n);
    ans.push_back(2);
    while (i < j) {
        ans.push_back(j);
        j--;
        if (i >= j)
            break;
        ans.push_back(i);
        i++;
    }
    for (int t = i; t <= j; t++)
        ans.push_back(t);
    vector<bool> dd(2 * n + 2, false);
    for (int i = 1; i < ans.size(); i++) {
        if (k <= 1) {
            if (ans[i] > ans[i - 1])
                sort(ans.begin() + i, ans.end());
            else
                sort(ans.begin() + i, ans.end(), greater<int>());
            break;
        }
        if (!dd[abs(ans[i] - ans[i - 1])])
            k--;
        dd[abs(ans[i] - ans[i - 1])] = true;
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
