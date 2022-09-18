#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool tryMake(string &s1, string &s2, string &ans) {
    int c11 = 0, c01 = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '1')
            c11++;
        else
            c01++;
    }
    int c12 = 0, c02 = 0;
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '1')
            c12++;
        else
            c02++;
    }
    ans.clear();
    if (min(c11, c12) * 2 >= s1.length()) {
        int j = 0;
        for (int i = 0; i <= s1.length(); i++) {
            if (j >= s2.length()) {
                if (i < s1.length())
                    ans.push_back(s1[i]);
                continue;
            }
            if (i >= s1.length()) {
                while (j < s2.length()) {
                    ans.push_back(s2[j]);
                    j++;
                }
                continue;
            }
            if (s1[i] == '1' && s2[j] == '1') {
                ans.push_back('1');
                j++;
                continue;
            }
            if (s1[i] == '1') {
                while (j < s2.length() && s2[j] != '1') {
                    ans.push_back(s2[j]);
                    j++;
                }
                ans.push_back('1');
                j++;
                continue;
            }
            if (s2[j] == '1') {
                ans.push_back(s1[i]);
                continue;
            }
            ans.push_back(s1[i]);
            if (s1[i] != s2[j])
                ans.push_back(s2[j]);
            j++;
        }
        return true;
    }
    if (min(c01, c02) * 2 >= s1.length()) {
        int j = 0;
        for (int i = 0; i <= s1.length(); i++) {
            if (j >= s2.length()) {
                if (i < s1.length())
                    ans.push_back(s1[i]);
                continue;
            }
            if (i >= s1.length()) {
                while (j < s2.length()) {
                    ans.push_back(s2[j]);
                    j++;
                }
                continue;
            }
            if (s1[i] == '0' && s2[j] == '0') {
                ans.push_back('0');
                j++;
                continue;
            }
            if (s1[i] == '0') {
                while (j < s2.length() && s2[j] != '0') {
                    ans.push_back(s2[j]);
                    j++;
                }
                ans.push_back('0');
                j++;
                continue;
            }
            if (s2[j] == '0') {
                ans.push_back(s1[i]);
                continue;
            }
            ans.push_back(s1[i]);
            if (s1[i] != s2[j])
                ans.push_back(s2[j]);
            j++;
        }
        return true;
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s1, s2, s3;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        getline(cin, s3);
        string ans;
        if (!tryMake(s1, s2, ans))
            if (!tryMake(s1, s3, ans))
                tryMake(s2, s3, ans);
        cout << ans << endl;
    }

    return 0;
}
