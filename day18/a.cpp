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
	vector<pair<int, int>> pos;
	while (getline(cin, line)) {
		istringstream iss(line);
		int x, y; char c; iss >> y >> c >> x;
		pos.push_back({x, y});
	}
	const int MN = 70 + 1;
	int N = MN, M = MN;
	auto in = [&](int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; };
	const int blocked = 1024;
	vector<vector<int>> g(N, vector<int>(M));
	for (int i = 0; i < blocked; ++i) {
		auto [x, y] = pos[i];
		debug(x, y);
		g[x][y] = 1;
	}
	vector<vector<int>> dist(N, vector<int>(M, 1e9));
	dist[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (!in(nx, ny)) continue;
			if (g[nx][ny]) continue;
			if (dist[x][y] + 1 < dist[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	cout << dist[N-1][M-1] << '\n';
}