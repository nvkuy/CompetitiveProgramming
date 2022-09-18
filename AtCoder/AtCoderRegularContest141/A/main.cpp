#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long getNum(string num, int rt) {
    long long ans = 0, p10 = 1, rm = stoll(num);
    for (int i = 0; i < num.length(); i++)
        p10 *= 10LL;
    while (rt--)
        ans = (ans * p10) + rm;
    return ans;
}

long long tryLength(int ln, long long n) {
    string tmp = to_string(n);
    string ans;
    for (int i = 0; i < ln; i++)
        ans.push_back(tmp[i]);
    long long tnum = getNum(ans, tmp.length() / ln);
    if (tnum <= n)
        return tnum;
    bool iok = true;
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] > '0') {
            if (i == 0 && ans[i] == '1')
                iok = false;
            ans[i]--;
            break;
        } else
            ans[i] = '9';
    }
    if (!iok) {
        ans.clear();
        ans.push_back('0');
        for (int i = 1; i < tmp.length(); i++)
            ans.push_back('9');
        tnum = getNum(ans, 1);
    } else
        tnum = getNum(ans, tmp.length() / ln);
    return tnum;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        string tmp = to_string(n);
        long long ans = 11;
        for (int i = 2; i <= tmp.length(); i++) {
            if (tmp.length() % i == 0)
                ans = max(ans, tryLength(tmp.length() / i, n));
        }
        cout << ans << endl;
    }

    return 0;
}
