#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int mod = 16777216;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	vector<vector<pair<ll, ll>>> buyers;
	while (getline(cin, line)) {
		istringstream iss(line);
		ll x; iss >> x;
		vector<pair<ll, ll>> diffs;
		for (int i = 0; i < 2000; ++i) {
			ll lst = x;
			x = (x * 64) ^ x; 
			x %= mod;
			x = (x / 32) ^ x;
			x %= mod;
			x = (x * 2048) ^ x;
			x %= mod;
			diffs.push_back({x%10 - lst%10, x%10});
		}
		buyers.push_back(diffs);
	}
	map<vector<ll>, ll> cand;
	for (auto diffs : buyers) {
		set<vector<ll>> seen;
		for (int i = 0; i < (int)diffs.size()-4; ++i) {
			vector<ll> cur = {diffs[i].first, diffs[i+1].first, diffs[i+2].first, diffs[i+3].first};
			if (seen.count(cur)) continue;
			seen.insert(cur);
			cand[cur] += diffs[i+3].second;
		}
	}
	for (auto &[a, b] : cand) ans = max(ans, b);
	cout << ans << '\n';
}