#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

char curChar, curPos;

bool cmpStr(string s1, string s2) {
    int p1, p2;
    for (int i = 0; i < 10; i++) {
        if (s1[i] == curChar)
            p1 = i;
        if (s2[i] == curChar)
            p2 = i;
    }
    if (p1 - curPos < 0)
        p1 += 10;
    if (p2 - curPos < 0)
        p2 += 10;
    return p1 > p2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    vector<string> as(n), cpas;
    for (int i = 0; i < n; i++)
        getline(cin, as[i]);
    int ans = 1e9;
    for (char c = '0'; c <= '9'; c++) {
        cpas = as;
        int time = 0, pos = 0;
        while (!cpas.empty()) {
            curChar = c, curPos = pos;
            sort(cpas.begin(), cpas.end(), cmpStr);
            string curStr = cpas.back(); cpas.pop_back();
            while (curStr[pos] != c) {
                time++;
                pos = (pos + 1) % 10;
            }
            pos = (pos + 1) % 10;
            time++;
        }
        ans = min(ans, time - 1);
    }
    cout << ans;

    return 0;
}
