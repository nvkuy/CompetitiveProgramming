#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        vector<int> test;
        for (int j = 0; j < n; j++) {
            if ((j & (1 << i)) != 0)
                test.push_back(j + 1);
        }
        cout << test.size() << ' ';
        for (int ai : test)
            cout << ai << ' ';
        cout << endl;
    }
    int num = 0;
    string rp;
    for (int i = 0; i < 10; i++) {
        cin >> rp;
        if (rp == "NEGATIVE")
            continue;
        num |= (1 << i);
    }
    int ans = num;
    for (int i = 0; i + 1 < n; i++) {
        if ((i | (i + 1)) == num) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}