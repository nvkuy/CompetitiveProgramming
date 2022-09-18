#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> precal;

int cg(int l, int r, char c) {
    for (int i = 0; i < (int)(c); i++) {
        if (precal[r][i] - precal[l][i] > 0)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    string s;
    cin >> n;
    precal.assign(n + 1, vector<int>(151, 0));
    cin.ignore();
    getline(cin, s);
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 151; k++)
            precal[i + 1][k] = precal[i][k];
        precal[i + 1][(int)(s[i])]++;
        if (s[i] <= s[j])
            j = i;
    }
    int i = 0;
    while (i < j) {
        if (s[i] <= s[j])
            i++;
        else {
            swap(s[i], s[j]);
            //cout << "sw " << i << ' ' << j << endl;
            break;
        }
    }
    i++; j--;
    while (i < j) {
        int rp = cg(i + 1, j + 1, s[i]);
        if (rp == -1) {
            i++;
            continue;
        }
        char c = (char)(rp);
        while (j > i) {
            if (s[j] != c)
                j--;
            else {
                swap(s[i], s[j]);
                //cout << "sw " << i << ' ' << j << endl;
                i++; j--;
                break;
            }
        }
    }
    cout << s;

    return 0;
}
