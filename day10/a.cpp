#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	vector<string> g;
	while (getline(cin, line)) {
		g.push_back(line);
	}
	int N = g.size(), M = g[0].size();
	auto in = [&](int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; };
	set<pair<int, int>> vis;
	auto go = [&](auto self, int i, int j, int d) -> void {
		if (d == 9) vis.insert({i, j});
		else {
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (!in(nx, ny)) continue;
				if (g[nx][ny] - '0' != d + 1) continue;
				self(self, nx, ny, d + 1);
			}
		}
	};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j] == '0') {
				vis.clear();
				go(go, i, j, 0);
				ans += vis.size();
			}
		}
	}
	cout << ans << '\n';
}