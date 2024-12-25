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
	string line;
	ll ans = 0;
	vector<string> g;
	string instruction = "";
	while (getline(cin, line)) {
		if (line == "") continue;
		if (line[0] != '#') instruction += line;
		else {
			string row = "";
			for (char c : line) {
				if (c == '#') row += "##";
				if (c == '.') row += "..";
				if (c == '@') row += "@.";
				if (c == 'O') row += "[]";
			}
			g.push_back(row);
		}
	}
	int N = g.size(), M = g[0].size();
	int sx, sy;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j] == '@') sx = i, sy = j; 
		}
	}
	auto act = [&](int dx, int dy) {
		vector<vector<int>> vis(N, vector<int>(M));
		vector<pair<int, int>> comp;
		bool movable = 1;
		auto dfs = [&](auto self, int x, int y) -> void {
			comp.push_back({x, y});
			vis[x][y] = 1;
			int nx = x + dx, ny = y + dy;
			if (g[nx][ny] == '#') movable = 0;
			if (g[nx][ny] != '@' && g[nx][ny] != '[' && g[nx][ny] != ']') return;
			if (g[nx][ny] == '[') {
				if (!vis[nx][ny]) self(self, nx, ny);
				if (!vis[nx][ny+1]) self(self, nx, ny+1);
			}
			if (g[nx][ny] == ']') {
				if (!vis[nx][ny]) self(self, nx, ny);
				if (!vis[nx][ny-1]) self(self, nx, ny-1);
			}
		};
		dfs(dfs, sx, sy);
		if (!movable) return;
		sort(comp.begin(), comp.end(), [&](pair<int, int> a, pair<int, int> b) {
			return dx * a.first + dy * a.second > dx * b.first + dy * b.second;
		});
		for (auto [x, y] : comp) {
			g[x + dx][y + dy] = g[x][y];
			g[x][y] = '.';
		}
		sx = sx + dx, sy = sy + dy;
	};
	for (char c : instruction) {
		if (c == '<') act(0, -1);
		if (c == '>') act(0, 1);
		if (c == '^') act(-1, 0);
		if (c == 'v') act(1, 0);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j] != '[') continue;
			int vert = i;
			int hori = j;
			ans += 100 * vert + hori;
		}
	}
	cout << ans << '\n';
}