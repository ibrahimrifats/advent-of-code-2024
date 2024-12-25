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
	int sx, sy, tx, ty;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
		if (g[i][j] == 'S') sx = i, sy = j;
		if (g[i][j] == 'E') tx = i, ty = j;
	}
	auto go = [&](int srcx, int srcy) -> vector<vector<int>> {
		vector<vector<int>> dist(N, vector<int>(M, 1e8));
		struct Item { int x, y; };
		queue<Item> q;
		dist[srcx][srcy] = 0;
		q.push({srcx, srcy});
		while (!q.empty()) {
			auto [x, y] = q.front(); q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (!in(nx, ny)) continue;
				int nd = dist[x][y] + 1;
				if (nd < dist[nx][ny]) {
					dist[nx][ny] = nd;
					if (g[nx][ny] != '#') q.push({nx, ny});
				}
			}
		}
		return dist;
	};
	auto sd = go(sx, sy);
	auto td = go(tx, ty);
	auto base = sd[tx][ty];
	map<int, int> cnt;
	for (int i = 1; i < N-1; ++i) {
		for (int j = 1; j < M-1; ++j) {
			for (int dir = 0; dir < 4; ++dir) {
				int i2 = i + dx[dir], j2 = j + dy[dir];
				if (!in(i2, j2)) continue;
				if (g[i2][j2] == '#') continue;
				auto cur = sd[i][j] + td[i2][j2] + 1;
				if (cur > base) continue;
				cnt[base - cur]++;
				if (cur <= base - 100) ans++;
			}
		}
	}
	cout << ans << '\n';
}