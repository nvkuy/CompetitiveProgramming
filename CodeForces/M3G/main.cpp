#include <bits/stdc++.h>

using namespace std;

bool nt[1000001];
vector<int> snt;
vector<vector<int>> ans(1000001);

vector<int> pt(int n) {
    if (n <= 4)
        return {-1, -1};
    int d = 1e6 + 3;
    vector<int> rs = {-1, -1};
    for (int i = 0; i < snt.size(); i++) {
        if (snt[i] >= n)
            break;
        if (2 * snt[i] - n > d)
            break;
        if (nt[n - snt[i]]) {
            if (d > (2 * snt[i] - n)) {
                d = 2 * snt[i] - n;
                rs[0] = snt[i]; rs[1] = n - snt[i];
            }
        }
    }
    return rs;
}

int main()
{

    memset(nt, true, sizeof(nt));
    nt[1] = false; nt[0] = false;

    for(int i = 2; i * i <= 1000001; ++i) {
        if(nt[i] == true) {
            for(int j = i * i; j <= 1000001; j += i)
                nt[j] = false;
        }
    }
    for (int i = 3; i <= 1000001; i++)
        if (nt[i] == true)
            snt.push_back(i);
    nt[2] = false;

    for (int i = 4; i <= 1000001; i+=2)
        ans[i] = pt(i);


    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (ans[n][0] != -1)
            printf("%d = %d + %d\n", n, ans[n][0], ans[n][1]);
        else
            printf("No\n");
    }

    return 0;
}
