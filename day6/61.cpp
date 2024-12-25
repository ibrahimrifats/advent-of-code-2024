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
    ifstream inputFile("input.txt"); // Open the input file
    if (!inputFile) {
        cerr << "Failed to open input.txt" << endl;
        return 1;
    }
    
    string line;
    ll ans = 0;
    vector<string> g;
    
    while (getline(inputFile, line)) { // Read from input.txt
        g.push_back(line);
    }
    inputFile.close(); // Close the file
    
    int N = g.size(), M = g[0].size();
    auto in = [&](int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; };
    int x, y;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (g[i][j] == '^') x = i, y = j;
        }
    }
    
    int dx = -1, dy = 0;
    vector<vector<int>> vis(N, vector<int>(M));
    
    while (true) {
        vis[x][y] = 1;
        int nx = x + dx, ny = y + dy;
        if (!in(nx, ny)) break;
        if (g[nx][ny] == '#') {
            swap(dx, dy); dy *= -1;
        } else {
            x = nx, y = ny;
        }
    }
    
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < M; ++j) {
            ans += vis[i][j];
        }
    
    cout << ans << '\n';
    return 0;
}
