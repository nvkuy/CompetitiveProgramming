#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a, b;
long long n, mod = 1e9 + 7;

vector<vector<int>> matmul(vector<vector<int>> mt1, vector<vector<int>> mt2) {

    vector<vector<int>> ans;
    vector<int> tmp1; int tmp2;

    for (int i = 0; i < mt1.size(); i++) {
        for (int j = 0; j < mt2.size(); j++) {
            tmp2 = 0;
            for (int k = 0; k < mt1[i].size(); k++)
                tmp2 = (tmp2 + ((mt1[i][k] * mt2[k][j]) % mod)) % mod;
            tmp1.push_back(tmp2);
        }
        ans.push_back(tmp1);
        tmp1.clear();
    }

    return ans;
}

long long cal(long long n) {

    if (n == 1)
        return 1;
    if (n == 2)
        return 6;

    n -= 2;
    long long ans = 4 * (n % mod) % mod;
    vector<vector<int>> t1, t4;

    t1 = {{1, 0}, {0, 1}}, t4 = a;
    while (n > 0) {
        if (n % 2 == 1)
            t1 = matmul(t1, t4);
        t4 = matmul(t4, t4);
        n /= 2;
    }
    //cout << t1[0][0] << " " << t1[0][1] << endl;
    //cout << t1[1][0] << " " << t1[1][1] << endl;
    t1 = matmul(b, t1);
    //cout << t1[0][0] << " " << t1[0][1] << endl;
    ans = (t1[0][1] + ans) % mod;
    return ans;
}

int main()
{
    a = {{0, -1}, {1, 2}};
    b = {{1, 6}};
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;
        cout << cal(n) << "\n";
    }

    return 0;
}
