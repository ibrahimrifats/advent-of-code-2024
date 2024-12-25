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

	vector<vector<int>> vis(N, vector<int>(M));
	using pii = pair<int, int>;
	vector<vector<pii>> comps;
	auto flood = [&](auto self, int i, int j) -> void {
		vis[i][j] = 1;
		comps.back().push_back({i, j});
		for (int dir = 0; dir < 4; ++dir) {
			int nx = i + dx[dir], ny = j + dy[dir];
			if (!in(nx, ny)) continue;
			if (vis[nx][ny]) continue;
			if (g[nx][ny] != g[i][j]) continue;
			self(self, nx, ny);
		}
	};
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
		if (!vis[i][j]) {
			comps.push_back({});
			flood(flood, i, j);
		}
	}
	for (auto comp : comps) {
		struct Item {
			int x, y, d;
			bool operator<(const Item &other) const {
				return tie(x, y, d) < tie(other.x, other.y, other.d);
			}
		};
		set<Item> seen;
		for (auto [i, j] : comp) {
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (in(nx, ny) && g[nx][ny] == g[i][j]) continue;
				seen.insert({nx, ny, dir});
			}
		}
		int peri = 0;
		while (!seen.empty()) {
			peri++;
			auto [i, j, d] = *seen.begin();
			while (true) {
				seen.erase({i, j, d});
				bool cont = 0;
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (!seen.count({nx, ny, d})) continue;
					cont = 1;
					i = nx, j = ny;
					break;
				}
				if (cont) continue;
				break;
			}
		}
		ans += peri * comp.size();
	}
	cout << ans << '\n';
}