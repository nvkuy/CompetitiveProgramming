#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x1, y1, x2, y2, dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
    set<string> s;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < 8; i++) {
        string tmp = to_string(x1 + dx[i]) + '|' + to_string(y1 + dy[i]);
        s.insert(tmp);
    }
    for (int i = 0; i < 8; i++) {
        string tmp = to_string(x2 + dx[i]) + '|' + to_string(y2 + dy[i]);
        if (s.find(tmp) != s.end()) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}
