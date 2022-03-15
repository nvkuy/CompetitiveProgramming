#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> n >> m >> p;
    vector<int> co(m, 0), rm;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < m; j++)
            if (s[j] == '1')
                co[j]++;
    }
    for (int i = 0; i < m; i++) {
        if (co[i] >= (n / 2) + (n % 2))
            rm.push_back(i);
    }
    for (int i = 0; i < pow(2LL, rm.size()); i++) {
        bitset<20> sl(i);
        for (int j = 0; j < rm.size(); j++)
    }

    return 0;
}
