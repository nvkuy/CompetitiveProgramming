#include <bits/stdc++.h>

using namespace std;

struct Block {
    int nu;
    int co;
    Block(int ni, int ci) {
        nu = ni;
        co = ci;
    }
};

bool cmp(Block b1, Block b2) {
    return (b1.nu < b2.nu);
}

vector<Block> blocks;
int orc[100001];

int main()
{
    int n, k, ni, ci;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ni >> ci;
        blocks.push_back(Block(ni, ci));
        orc[i] = ci;
    }
    sort(blocks.begin(), blocks.end(), cmp);
    //for (int i = 0; i < n; i++)
    //    cout << blocks[i].nu << "|" << blocks[i].co << " ";
    //cout << endl;
    bool fl = true;
    for (int i = 0; i < n; i++)
        if (orc[i] != blocks[i].co)
            fl = false;
    cout << (fl ? "Y" : "N");

    return 0;
}
