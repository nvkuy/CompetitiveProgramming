#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MaxA = 5e6;
int isNotPrime[MaxA + 1];

int main()
{

    for (int i = 2; i * i <= MaxA; i++)
        if (!isNotPrime[i])
            for (int j = i * i; j <= MaxA; j += i)
                isNotPrime[j] = 1;

    vector<vector<int>> pm(4);
    for (int i = 1; i <= MaxA; i++)
        if (!isNotPrime[i]) pm[i % 4].push_back(i);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, int> p1, p2;
        p1 = p2 = {1e9, 1e9};
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            if (ai % 4 == 0) {
                if (ai / 4 + 1 < p2.first)
                    p2 = {ai / 4 + 1, i};
                continue;
            }
            int tmp = upper_bound(pm[ai % 4].begin(), pm[ai % 4].end(), ai) - pm[ai % 4].begin();
            int turn = 1 + (ai - pm[ai % 4][tmp - 1]) / 4;
            if (turn < p1.first)
                p1 = {turn, i};
        }
        if (p1.first == p2.first)
            cout << (p1.second < p2.second ? "Farmer John" : "Farmer Nhoj") << endl;
        else
            cout << (p1.first < p2.first ? "Farmer John" : "Farmer Nhoj") << endl;
    }

    return 0;
}
