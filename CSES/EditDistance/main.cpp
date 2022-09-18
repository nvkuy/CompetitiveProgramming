#include <bits/stdc++.h>

using namespace std;

int f[5005][5005];

int main()
{

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    //vector<vector<int>> f(s1.length(), vector<int>(s2.length(), 0));
    for (int i = 0; i <= s1.length(); i++)
        f[i][0] = i;
    for (int i = 0; i <= s2.length(); i++)
        f[0][i] = i;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
            if (s1[i - 1] == s2[j - 1])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
        }
    }
    cout << f[s1.length()][s2.length()];

    return 0;
}
