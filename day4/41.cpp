#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ifstream infile("input.txt");  // Open input.txt
    string line;
    ll ans = 0;
    vector<string> g;

    while (getline(infile, line)) {  // Read from file instead of standard input
        g.push_back(line);
    }
    
    int N = g.size(), M = g[0].size();
    string want = "XMAS";
    auto in = [&](int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; };
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    bool ok = [&]() -> bool {
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dx * k, y = j + dy * k;
                            if (!in(x, y)) return false;
                            if (g[x][y] != want[k]) return false;
                        }
                        return true;
                    }();
                    ans += ok;
                }
            }
        }
    }
    cout << ans << '\n';
}
