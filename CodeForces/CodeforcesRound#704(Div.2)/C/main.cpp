#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, m;
string s1, s2;

void getPos(vector<int> &pos) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j >= m)
            break;
        if (s1[i] == s2[j]) {
            pos.push_back(i);
            j++;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> fpos, lpos;
    cin >> n >> m;
    cin.ignore();
    getline(cin, s1);
    getline(cin, s2);

    getPos(fpos);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    getPos(lpos);
    reverse(lpos.begin(), lpos.end());
    for (int i = 0; i < m; i++)
        lpos[i] = n - lpos[i] - 1;
    int ans = 0;
    for (int i = 1; i < m; i++)
        ans = max(ans, lpos[i] - fpos[i - 1]);
    cout << ans;

    return 0;
}
