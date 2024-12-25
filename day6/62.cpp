#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG

#else
#define debug(...) 0
#endif

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
	auto escapes = [&]() -> bool {
		int x, y;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (g[i][j] == '^') x = i, y = j;
			}
		}
		int dx = -1, dy = 0;
		vector<vector<set<pair<int, int>>>> vis(N, vector<set<pair<int, int>>>(M));
		while (true) {
			if (vis[x][y].count({dx, dy})) return 0;
			vis[x][y].insert({dx, dy});
			int nx = x + dx, ny = y + dy;
			if (!in(nx, ny)) return 1;
			if (g[nx][ny] == '#') {
				swap(dx, dy); dy *= -1;
			}
			else {
				x = nx, y = ny;
			}
		}
	};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j] != '.') continue;
			g[i][j] = '#';
			if (!escapes()) {
				ans++;
			}
			g[i][j] = '.';
		}
	}
	cout << ans << '\n';
}