#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int w;
    cin >> w;
    vector<int> ans;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int num = i * 10 + j;
            if (num == 0)
                continue;
            ans.push_back(num), ans.push_back(num * 100), ans.push_back(num * 10000);
        }
    }
    ans.push_back(1e6);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
