#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s1, s2;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s1);
        getline(cin, s2);
        bool hasAinS2 = false;
        for (int i = 0; i < s2.length(); i++)
            if (s2[i] == 'a')
                hasAinS2 = true;
        if (hasAinS2) {
            if (s2.length() == 1)
                cout << "1" << endl;
            else
                cout << "-1" << endl;
            continue;
        }
        cout << (1LL << s1.length()) << endl;
    }

    return 0;
}
