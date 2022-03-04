#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

long long ans, f[101];
set<string> s;

void cal(long long n, long long co, vector<long long> nums) {
    if (n == 0LL) {
        ans = min(ans, co);
        return;
    }
    if (co > ans)
        return;
    string st = to_string(n) + '|' + to_string(co) + '|' + to_string(nums.size());
    if (s.find(st) != s.end())
        return;
    s.insert(st);
    if (n - f[nums.size()] > 0)
        return;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] > n) {
            nums.pop_back();
            continue;
        } else {
            long long tmp = nums[i];
            n -= tmp;
            co++;
            nums.pop_back();
            cal(n, co, nums);
            n += tmp;
            co--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    long long n;
    vector<long long> nums;
    ans = 1LL;
    nums.push_back(ans);
    while ((ans * 2LL) <= 1e12) {
        ans *= 2LL;
        nums.push_back(ans);
    }
    ans = 1LL, n = 2LL;
    while ((ans * n) <= 1e12) {
        ans *= n;
        n++;
        nums.push_back(ans);
    }
    sort(nums.begin(), nums.end());
    f[0] = 0LL;
    for (int i = 1; i <= nums.size(); i++)
        f[i] = f[i - 1] + nums[i - 1];
    cin >> t;
    while (t--) {
        cin >> n;
        s.clear();
        ans = 1e18;
        cal(n, 0, nums);
        if (ans == 1e18)
            ans = -1;
        cout << ans << endl;
    }

    return 0;
}
