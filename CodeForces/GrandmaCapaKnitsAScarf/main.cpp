#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int n;
string s;
int cal(char c) {
    int i = 0, j = n - 1;
    vector<int> dd(n, -1);
    while (i < j) {
        if (s[i] == s[j] && s[i] == c) {
            i++;
            j--;
            continue;
        }
        if (s[i] == c) {
            i++;
            continue;
        }
        if (s[j] == c) {
            j--;
            continue;
        }
        if (s[i] != s[j])
            return 1e9 + 7;
        else {
            i++;
            j--;
        }
    }
    //cout << c << '|' << i << '|' << j << endl;
    while (i < n && j >= 0) {
        if (s[i] == s[j]) {
            dd[i] = j;
            dd[j] = i;
            i++;
            j--;
        } else {
            if (s[i] == c)
                i++;
            else
                j--;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (dd[i] < 0);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        int ans = 1e9 + 7;
        for (char c = 'a'; c <= 'z'; c++) {
            ans = min(ans, cal(c));
            //cout << c << '|' << ans << endl;
        }
        if (ans == 1e9 + 7)
            ans = -1;
        cout << ans << endl;
    }

    return 0;
}
