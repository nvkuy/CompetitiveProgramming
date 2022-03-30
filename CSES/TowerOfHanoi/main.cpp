#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<pair<int, int>> ans;

void make(int n, int A, int B) {
    if (n <= 1) {
        ans.push_back(make_pair(A, B));
        return;
    }
    int C = 6 - A - B;
    make(n - 1, A, C);
    make(1, A, B);
    make(n - 1, C, B);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    make(n, 1, 3);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;

    return 0;
}
