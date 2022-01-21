#include <bits/stdc++.h>

using namespace std;

struct check{
    char c;
    vector<int> cs;
    check(char ci, vector<int> costs) {
        c = ci;
        cs = costs;
    }
    setcheck(char ci, int cost) {

    }
    long long cal() {
        if (cs.size() <= 1)
            return 0;
        sort(cs.begin(); cs.end());
        long long ans = 0;
        for (int i = 0; i < (cs.size() - 1); i++)
            ans += cs[i];
        return ans;
    }
};

string s[22];
int a[22][1000002];
vector<int> cc;

int main()
{

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        cc.clear();
        for (int j = 0; j < n; j++) {

            for (int k = 0; k < cc.size(); k++) {}
        }
    }

    return 0;
}
