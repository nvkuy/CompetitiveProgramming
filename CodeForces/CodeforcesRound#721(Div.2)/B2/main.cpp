#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string s;
int make(int n) {
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            ans++;
            s[n - i - 1] = s[i] = '1';
        }
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        int tmp = make(n), turn = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                turn++;
        if (tmp > 1) {
            cout << "ALICE" << endl;
            continue;
        }
        if (tmp == 0) {
            if (turn == 1)
                cout << "BOB" << endl;
            else
                cout << ((turn % 2) ? "ALICE" : "BOB") << endl;
            continue;
        }
        if (turn == 1) {
            cout << "DRAW" << endl;
            continue;
        }
        cout << "ALICE" << endl;
    }

    return 0;
}
