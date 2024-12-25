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

    while (getline(infile, line)) {  // Read from file instead of cin
        g.push_back(line);
    }

    int N = g.size(), M = g[0].size();
    string want = "XMAS";
    auto in = [&](int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; };

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < M - 1; ++j) {
            bool ok = [&]() -> bool {
                if (g[i][j] != 'A') return false;
                if (g[i-1][j-1] == 'M' && g[i-1][j+1] == 'M' && g[i+1][j-1] == 'S' && g[i+1][j+1] == 'S') return true;
                if (g[i-1][j-1] == 'M' && g[i-1][j+1] == 'S' && g[i+1][j-1] == 'M' && g[i+1][j+1] == 'S') return true;
                if (g[i-1][j-1] == 'S' && g[i-1][j+1] == 'S' && g[i+1][j-1] == 'M' && g[i+1][j+1] == 'M') return true;
                if (g[i-1][j-1] == 'S' && g[i-1][j+1] == 'M' && g[i+1][j-1] == 'S' && g[i+1][j+1] == 'M') return true;
                return false;
            }();
            ans += ok;
        }
    }

    cout << ans << '\n';
}
