#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<bool> dd;
vector<int> ans;

void make(int ai) {
    ans.push_back(ai);
    dd[ai] = true;
    int tmp, p2 = 1;
    for (int i = 0; i < n; i++) {
        tmp = ai;
        tmp ^= p2;
        if (!dd[tmp]) {
            make(tmp);
            return;
        }
        p2 *= 2;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dd.assign((1 << n), false);
    make(0);
    for (int i = 0; i < ans.size(); i++) {
        bitset<20> bs(ans[i]);
        for (int j = n - 1; j >= 0; j--)
            cout << bs[j];
        cout << endl;
    }

    return 0;
}
