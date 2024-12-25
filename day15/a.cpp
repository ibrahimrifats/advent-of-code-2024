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
		else g.push_back(line);
	}
	int N = g.size(), M = g[0].size();
	int sx, sy;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j] == '@') sx = i, sy = j; 
		}
	}
	auto act = [&](int dx, int dy) {
		int k = 0;
		bool can = 0;
		for (k = 0; ; ++k) {
			int nx = sx + k * dx, ny = sy + k * dy;
			if (g[nx][ny] == '#') break;
			else if (g[nx][ny] == '.') {
				can = 1;
				break;
			}
		}
		if (!can) return;
		for (int i = k; i >= 1; --i) {
			int x = sx + i * dx, y = sy + i * dy;
			g[x][y] = g[x - dx][y - dy];
		}
		g[sx][sy] = '.';
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
			if (g[i][j] != 'O') continue;
			ans += 100 * i + j;
		}
	}
	cout << ans << '\n';
}