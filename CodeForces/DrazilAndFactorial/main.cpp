#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    string s;
    vector<int> ans;
    cin >> n;
    cin.ignore();
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0' || s[i] == '1')
            continue;
        else {
            int j = s[i] - '0';
            if (j == 2 || j == 3 || j == 5 || j == 7)
                ans.push_back(j);
            else {
                if (j == 4) {
                    ans.push_back(2);
                    ans.push_back(2);
                    ans.push_back(3);
                } else if (j == 6) {
                    ans.push_back(3);
                    ans.push_back(5);
                } else if (j == 8) {
                    ans.push_back(2);
                    ans.push_back(2);
                    ans.push_back(2);
                    ans.push_back(7);
                } else {
                    ans.push_back(3);
                    ans.push_back(3);
                    ans.push_back(2);
                    ans.push_back(7);
                }
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    return 0;
}
