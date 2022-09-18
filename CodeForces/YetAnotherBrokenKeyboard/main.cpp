#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long ans = 0LL;
    int n, k;
    string s;
    char c;
    set<char> dd;
    cin >> n >> k;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < k; i++) {
        cin >> c;
        dd.insert(c);
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (dd.find(s[i]) == dd.end()) {
            j = i + 1;
            continue;
        }
        ans += (i - j + 1);
    }
    cout << ans << endl;

    return 0;
}
