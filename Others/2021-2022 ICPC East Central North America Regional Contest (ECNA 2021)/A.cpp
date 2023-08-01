#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MaxN = 1e5 + 3;
int fe[MaxN], fc[MaxN];
vector<vector<int>> divi;

int em_complexity(int n) {
    if (n >= MaxN) return 1e9;
    if (fe[n] != -1) return fe[n];
    if (n <= 2) return n;
    int ans = 1 + em_complexity(n - 1);
    for (int num : divi[n])
        ans = min(ans, num + em_complexity(n / num));
    return fe[n] = ans;
}

// int em_complexity(int n) {
//     if (fe[n] != -1) return fe[n];
//     if (n <= 2) return n;
//     int ans = 1e9;
//     if (n % 2) ans = min(ans, 1 + em_complexity(n - 1));
//     else ans = min(ans, 2 + em_complexity(n / 2));
//     if (n % 3) ans = min(ans, 1 + em_complexity(n - 1));
//     else ans = min(ans, 3 + em_complexity(n / 3));
//     return fe[n] = ans;
// }

// int cal(int n) {
//     string s = to_string(n);
//     string s1, s2;
//     for (int i = 0; i < s.length(); i++) {
//         s1.push_back(s[i]);
//         if (i + 1 < s.length() && s[i + 1] != '0') {
//             for (int j = i + 1; j < s.length(); j++)
//                 s2.push_back(s[j]);
//             break;
//         }
//     }
//     int ans = em_complexity(stoi(s1));
//     if (s2.length() > 0) ans += cal(stoi(s2));
//     return fc[n] = ans;
// }

int cal(int n) {
    if (fc[n] != -1) return fc[n];
    string s = to_string(n);
    int ans = em_complexity(n), len = s.length();
    for (int i = 1; i < n; i++) {
        ans = min(ans, cal(i) + cal(n - i));
        if (i >= n - i) break;
    }
    for (int i = 0; i + 1 < len; i++) {
        if (s[i + 1] == '0') continue;
        string s1, s2;
        for (int j = 0; j < len; j++) {
            if (j <= i)
                s1.push_back(s[j]);
            else
                s2.push_back(s[j]);
        }
        ans = min(ans, cal(stoi(s1)) + cal(stoi(s2)));
    }

    return fc[n] = ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    divi.resize(MaxN);
    for (int i = 0; i < MaxN; i++)
        fe[i] = fc[i] = -1;
    for (int i = 2; i < MaxN; i++) {
        for (int j = 1; j * i < MaxN; j++)
            divi[i * j].push_back(i);
    }
    // cout << em_complexity(9) << ' ' << em_complexity(10) << endl;
    // cout << cal(11) << ' ' << cal(1) << endl;
    // cout << em_complexity(12) << ' ' << em_complexity(7) << ' ' << em_complexity(5) << endl;'
    int n;
    cin >> n;
    cout << cal(n) << endl;

    return 0;
}
