#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream infile("input.txt");  // Open input.txt
    string line;
    ll ans = 0;
    set<pair<int, int>> ord;

    while (getline(infile, line)) {  // Read from file instead of cin
        istringstream iss(line);
        if (line.empty()) continue;
        if (line.find('|') != string::npos) {
            int x; char c; int y;
            iss >> x >> c >> y;
            ord.insert({x, y});
        } else {
            vector<int> v;
            int x;
            iss >> x;
            v.push_back(x);
            char c;
            while (iss >> c >> x) {
                v.push_back(x);
            }
            int n = v.size();
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (ord.count({v[j], v[i]})) ok = false;
                }
            }
            if (ok) ans += v[n / 2];
        }
    }
    cout << ans << '\n';
}
