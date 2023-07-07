#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m, cur_time = 1;
    cin >> n >> m;
    map<string, string> server_dns, client_dns;
    map<int, string> client_cache_time;
    map<string, int> name_time;

    bool hacked = false;
    while (n--) {
        cur_time++;
        int type;
        cin >> type;
        if (type == 1) {
            string name, ip;
            cin >> name >> ip;
            server_dns[name] = ip;
        } else {
            string name;
            cin >> name;
            if (server_dns.find(name) == server_dns.end()) continue;
            if (hacked) continue;
            if (client_dns.find(name) != client_dns.end()) {
                string pre = client_dns[name];
                if (pre != server_dns[name]) {
                    hacked = true;
                    continue;
                }
                int pre_time = name_time[name];
                client_cache_time.erase(client_cache_time.find(pre_time));
            } else {
                if (client_dns.size() >= m) {
                    pair<int, string> far = *client_cache_time.begin();
                    client_cache_time.erase(client_cache_time.begin());
                    client_dns.erase(client_dns.find(far.second));
                }
            }
            client_dns[name] = server_dns[name];
            client_cache_time.insert({cur_time, name});
            name_time[name] = cur_time;
        }
    }

    cout << (hacked ? "Warning: Possible DNS Poisoning detected!" : "Everything looks ok!") << endl;

    return 0;
}
