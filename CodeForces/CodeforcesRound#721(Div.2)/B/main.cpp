#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        int turn = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                turn++;
        if (turn == 1)
            cout << "BOB" << endl;
        else
            cout << ((turn % 2) ? "ALICE" : "BOB") << endl;
    }

    return 0;
}
