#include <bits/stdc++.h>
using namespace std;

int const maxN = 1000;
bool have_cow[4 * maxN][4 * maxN];
int cow = 0;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

void makeOK(int, int);
void addCow(int, int);

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        addCow(x, y);
        cout << cow - i << endl;
    }

    return 0;
}

void makeOK(int x, int y) {
    if (!have_cow[x + maxN][y + maxN]) return;
    vector<pair<int, int>> free_space;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!have_cow[nx + maxN][ny + maxN])
            free_space.push_back({nx, ny});
    }
    if (free_space.size() == 1)
        addCow(free_space.back().first, free_space.back().second);
}

void addCow(int x, int y) {
    if (have_cow[x + maxN][y + maxN]) return;
    cow++;
    have_cow[x + maxN][y + maxN] = true;
    makeOK(x, y);
    for (int i = 0; i < 4; i++)
        makeOK(x + dx[i], y + dy[i]);
}