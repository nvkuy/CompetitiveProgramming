#include <bits/stdc++.h>

using namespace std;

vector<int> missingValue(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans;
    int j = 0;
    for (int i = 0; i < b.size(); i++) {
        if ((i > 0 && b[i] != b[i - 1]) || (i == 0)) {
            j = upper_bound(a.begin() + j, a.end(), b[i]) - a.begin();
            if ((a[j] < b[i]) && (j == (a.size() - 1)))
                ans.push_back(b[i]);
            if (a[j - 1] != b[i])
                ans.push_back(b[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> test = missingValue({203, 204, 205, 206, 207, 208, 203, 204, 205, 206},{203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204});
    for (int i = 0; i < test.size(); i++)
        cout << test[i] << " ";
    cout << endl;
    return 0;
}
