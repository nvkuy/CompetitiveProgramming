#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ai;
    cin >> n;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        if (b.size() == 0) {
            b.push_back(ai);
            continue;
        }
        int j = lower_bound(b.begin(), b.end(), ai) - b.begin();
        if (j == b.size())
            b.push_back(ai);
        else
            b[j] = ai;
    }
    cout << b.size();

    return 0;
}
