#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, p;
    string s;
    cin >> n >> m >> p;
    vector<int> co(m, 0), rm;
    vector<string> a;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        a.push_back(s);
        for (int j = 0; j < m; j++)
            if (s[j] == '1')
                co[j]++;
    }
    for (int i = 0; i < m; i++) {
        if (co[i] >= (n / 2) + (n % 2))
            rm.push_back(i);
    }
    int ans = 0;
    bitset<20> cans;
    for (int i = 0; i < pow(2LL, rm.size()); i++) {
        bitset<20> sl(i);
        map<int, int> dd;
        map<int, int>::iterator it;
        for (int j = 0; j < rm.size(); j++) {
            if (!sl[j])
                continue;
            for (int k = 0; k < n; k++) {
                if (a[k][rm[j]] == '0')
                    dd[rm[j]]++;
            }
        }
        bool iok = true;
        for (it = dd.begin(); it != dd.end(); it++) {
            if ((*it).second > n / 2) {
                iok = false;
                break;
            }
        }
        if (!iok)
            continue;
        int tans = sl.count();
        if (tans > ans) {
            ans = tans;
            cans = sl;
        }
    }
    for (int i = 0; i < m; i++)
        cout << cans[i];

    return 0;
}
