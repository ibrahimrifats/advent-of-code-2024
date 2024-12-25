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
	vector<ll> vec;
	while (getline(cin, line)) {
		istringstream iss(line);
		ll x;
		while (iss >> x) vec.push_back(x);
	}
	vector<map<ll, ll>> dp(76);
	auto go = [&](auto self, ll x, ll left) -> ll {
		if (left == 0) return 1;
		if (dp[left].count(x)) return dp[left][x];
		ll &cur = dp[left][x];
		if (x == 0) cur = self(self, 1, left-1);
		else if (to_string(x).size() % 2 == 0) {
			string s = to_string(x);
			int n = s.size();
			cur = self(self, stoll(s.substr(0, n/2)), left-1);
			cur += self(self, stoll(s.substr(n/2)), left-1);
		}
		else {
			cur = self(self, x*2024, left-1);
		}
		return cur;
	};
	ll ans = 0;
	for (ll x : vec) {
		ans += go(go, x, 75);
	}
	cout << ans << '\n';
}
