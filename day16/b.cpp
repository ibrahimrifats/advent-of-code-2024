#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	vector<string> g;
	while (getline(cin, line)) {
		g.push_back(line);
	}
	int N = g.size(), M = g[0].size();
	int ssx, ssy, tx, ty;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
		if (g[i][j] == 'S') ssx = i, ssy = j;
		if (g[i][j] == 'E') tx = i, ty = j;
	}
	auto go = [&](int sx, int sy, vector<int> dirs) {
		vector<vector<vector<ll>>> dist(N, vector<vector<ll>>(M, vector<ll>(4, 1e18)));
		for (int dir : dirs) dist[sx][sy][dir] = 0;
		struct Item {
			int x, y, dir; ll d;
			bool operator<(const Item &other) const {
				return d > other.d;
			}
		};
		priority_queue<Item> pq;
		for (int dir : dirs) pq.push({sx, sy, dir, 0});
		while (!pq.empty()) {
			auto [x, y, dir, d] = pq.top(); pq.pop();
			if (d != dist[x][y][dir]) continue;
			vector<Item> nxt;
			nxt.push_back({x + dx[dir], y + dy[dir], dir, d + 1});
			nxt.push_back({x, y, (dir - 1 + 4) % 4, d + 1000});
			nxt.push_back({x, y, (dir + 1 + 4) % 4, d + 1000});
			for (auto [nx, ny, ndir, nd] : nxt) {
				if (g[nx][ny] == '#') continue;
				if (nd >= dist[nx][ny][ndir]) continue;
				dist[nx][ny][ndir] = nd;
				pq.push({nx, ny, ndir, nd});
			}
		}
		return dist;
	};
	auto dist1 = go(ssx, ssy, {0});
	auto dist2 = go(tx, ty, {0, 1, 2, 3});
	ll mndist = *min_element(dist1[tx][ty].begin(), dist1[tx][ty].end());
	ll ans = 0;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
		bool ok = 0;
		for (int dir = 0; dir < 4; ++dir) {
			if (dist1[i][j][dir] + dist2[i][j][(dir + 2) % 4] == mndist) ok = 1;
		}
		ans += ok;
	}
	cout << ans << '\n';
}