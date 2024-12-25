#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

using pii = pair<int, int>;
vector<vector<string>> pads = {
	{" ^A", "<v>"},
	{" ^A", "<v>"},
	{"789", "456", "123", " 0A"},
};
map<char, pii> dir = {
	{'^', {-1, 0}},	
	{'>', {0, 1}},	
	{'<', {0, -1}},	
	{'v', {1, 0}},	
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	auto solve = [&](string s) -> int {
		struct State {
			int idx; vector<pii> pos;
			bool operator<(const State &other) const {
				return tie(idx, pos) < tie(other.idx, other.pos);
			}
		};
		State src = {0, {{0, 2}, {0, 2}, {3, 2}}};
		auto valid = [&](int i, int x, int y) -> bool {
			return x >= 0 && y >= 0 && x < (int)pads[i].size() && y < (int)pads[i][0].size() && pads[i][x][y] != ' ';
		};
		queue<State> q;
		map<State, int> dist;
		q.push(src);
		dist[src] = 0;
		int cur = 1e9;
		while (!q.empty()) {
			auto state = q.front(); q.pop();
			auto [idx, pos] = state;
			if (idx == (int)s.size()) {
				cur = min(cur, dist[state]);
				continue;
			}
			auto relax = [&](State nstate) {
				if (!dist.count(nstate)) {
					dist[nstate] = dist[state] + 1;
					q.push(nstate);
				}
			};
			for (char d : "^>v<") {
				auto npos = pos;
				npos[0].first += dir[d].first;
				npos[0].second += dir[d].second;
				if (!valid(0, npos[0].first, npos[0].second)) continue;
				relax({idx, npos});
			}
			// press 'A'
			int p = 0;
			for (p = 0; p < (int)pads.size() - 1; ++p) {
				auto [x, y] = pos[p];
				if (pads[p][x][y] != 'A') break;
			}
			if (p + 1 == (int)pads.size()) {
				auto [x, y] = pos[p];
				if (pads[p][x][y] == s[idx]) relax({idx+1, pos});
			}
			else {
				auto [x, y] = pos[p];
				auto d = pads[p][x][y];
				auto npos = pos;
				npos[p+1].first += dir[d].first;
				npos[p+1].second += dir[d].second;
				if (!valid(p+1, npos[p+1].first, npos[p+1].second)) continue;
				relax({idx, npos});
			}
		}
		return cur;
	};
	while (getline(cin, line)) {
		int dist = solve(line);
		ans += dist * stoi(line.substr(0, 3));
	}
	cout << ans << '\n';
}