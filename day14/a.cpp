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
	ll ans = 1;
	int N = 103, M = 101;
	// int N = 7, M = 11;
	struct Robot {
		int px, py, vx, vy;
	};
	vector<vector<vector<Robot>>> g(N, vector<vector<Robot>>(M));
	while (getline(cin, line)) {
		istringstream iss(line);
		char c;
		int px, py;
		int vx, vy;
		iss >> c >> c >> py >> c >> px >> c >> c >> vy >> c >> vx;
		g[px][py].push_back({px, py, vx, vy});
	}
	int its = 100;
	for (int it = 0; it < its; ++it) {
		vector<vector<vector<Robot>>> nxt(N, vector<vector<Robot>>(M));
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
			for (auto [px, py, vx, vy] : g[i][j]) {
				int nx = i + vx, ny = j + vy;
				if (nx < 0) nx += N;
				if (ny < 0) ny += M;
				nx %= N, ny %= M;
				nxt[nx][ny].push_back({px, py, vx, vy});
			}
		}
		g = nxt;
	}
	vector<vector<int>> quad(2, vector<int>(2));
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
		if (i == N / 2 || j == M / 2) continue;
		quad[i > N / 2][j > M / 2] += g[i][j].size();
	}
	ans = quad[0][0] * quad[0][1] * quad[1][0] * quad[1][1];
	cout << ans << '\n';
}