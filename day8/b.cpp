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
	while (getline(cin, line)) {
		g.push_back(line);
	}
	int N = g.size(), M = g[0].size();
	using pii = pair<int, int>;
	map<char, vector<pii>> mp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j] != '.') mp[g[i][j]].push_back({i, j});
		}
	}
	auto in = [&](int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; };
	vector<vector<int>> node(N, vector<int>(M));
	for (auto [c, vec] : mp) {
		for (auto [i1, j1] : vec) {
			for (auto [i2, j2] : vec) {
				if (i1 == i2 && j1 == j2) continue;
				int di = i2 - i1, dj = j2 - j1;
				int g = gcd(di, dj);
				di /= g, dj /= g;
				for (int k = 0; k < 100; ++k) {
					int i = i1 + k * di;
					int j = j1 + k * dj;
					if (in(i, j)) node[i][j] = 1;
				}
				for (int k = 0; k < 100; ++k) {
					int i = i1 - k * di;
					int j = j1 - k * dj;
					if (in(i, j)) node[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans += node[i][j];
		}
	}
	cout << ans << '\n';
}