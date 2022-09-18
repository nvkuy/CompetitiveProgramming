#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        int i = s.find("11");
        int j = -1;
        for (int k = 0; k < s.length() - 1; k++)
            if (s[k] == '0' && s[k + 1] == '0')
                j = k;
        if (i >= 0 && j >= 0 && j > i)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
