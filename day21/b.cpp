#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

using pii = pair<int, int>;
map<char, pii> dir = {
	{'^', {-1, 0}},	
	{'>', {0, 1}},	
	{'<', {0, -1}},	
	{'v', {1, 0}},	
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	const int M = 25;
	vector<vector<string>> pads;
	for (int i = 0; i < M; ++i) {
		pads.push_back({" ^A", "<v>"});
	}
	pads.push_back({"789", "456", "123", " 0A"});
	auto valid = [&](int i, int x, int y) -> bool {
		return x >= 0 && y >= 0 && x < (int)pads[i].size() && y < (int)pads[i][0].size() && pads[i][x][y] != ' ';
	};
	auto get_paths = [&](int p, int x1, int y1, int x2, int y2) -> vector<string> {
		vector<string> ret;
		auto go = [&](auto self, int x, int y, string cur) {
			if (!valid(p, x, y)) return;
			if (tie(x, y) == tie(x2, y2)) ret.push_back(cur);
			if (cur.size() == 5) return;
			for (auto [d, del] : dir) {
				self(self, x + del.first, y + del.second, cur + d);
			}
		};
		go(go, x1, y1, "");
		return ret;
	};
	auto locate = [&](int p, char c) -> pair<int, int> {
		for (int i = 0; i < (int)pads[p].size(); ++i) {
			for (int j = 0; j < (int)pads[p][0].size(); ++j) {
				if (pads[p][i][j] == c) return {i, j};
			}
		}
		assert(false);
	};
	map<tuple<int, int, int, int, int>, ll> cache;
	auto min_dist = [&](auto self, int p, int x1, int y1, int x2, int y2) -> ll {
		tuple<int, int, int, int, int> state = {p, x1, y1, x2, y2};
		if (cache.count(state)) return cache[state];
		ll &cur = cache[state];
		cur = 1e18;
		auto paths = get_paths(p, x1, y1, x2, y2);
		for (auto path : paths) {
			if (p == 0) cur = min(cur, (ll)path.size() + 1);
			else {
				ll route = 0;
				path = 'A' + path + 'A';
				for (int i = 1; i < (int)path.size(); ++i) {
					auto [lx1, ly1] = locate(p-1, path[i-1]);
					auto [lx2, ly2] = locate(p-1, path[i]);
					route += self(self, p-1, lx1, ly1, lx2, ly2);
				}
				cur = min(cur, route);	
			}
		}
		return cur;
	};
	auto solve = [&](string s) -> ll {
		string path = 'A' + s;
		ll cur = 0;
		for (int i = 1; i < (int)path.size(); ++i) {
			auto [lx1, ly1] = locate(M, path[i-1]);
			auto [lx2, ly2] = locate(M, path[i]);
			cur += min_dist(min_dist, M, lx1, ly1, lx2, ly2);
		}
		return cur;
	};
	string line;
	ll ans = 0;
	while (getline(cin, line)) {
		ll dist = solve(line);
		ll num = stoi(line.substr(0, 3));
		debug(dist, num);
		ans += dist * stoi(line.substr(0, 3));
	}
	cout << ans << '\n';
}