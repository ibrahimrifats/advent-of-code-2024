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
	auto print = [&](int it) {
		cout << it << '\n';
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cout << (g[i][j].size() != 0 ? '#' : ' ');
			}
			cout << '\n';
		}
	};
	int its = 10000;
	for (int it = 0; it < its; ++it) {
		int clustering = 0;
		for (int i = 1; i < N-1; ++i) for (int j = 1; j < M-1; ++j) {
			if (g[i][j].size()) {
				clustering += g[i-1][j].size();
				clustering += g[i][j-1].size();
				clustering += g[i+1][j].size();
				clustering += g[i][j+1].size();
			}
		}
		if (clustering >= 1000) {
			debug(clustering);
			print(it);
		}
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
}

