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
		istringstream iss(line);
		ll want;
		iss >> want;
		char col; iss >> col;
		vector<ll> vec;
		ll x;
		while (iss >> x) {
			vec.push_back(x);
		}
		if (vec.empty()) break;

		bool ok = 0;
		auto go = [&](auto self, int i, ll cur) -> void {
			if (i == (int)vec.size()) {
				if (cur == want) ok = 1;
				return;
			}
			self(self, i+1, cur * vec[i]);
			self(self, i+1, cur + vec[i]);
		};
		go(go, 1, vec[0]);
		if (ok) ans += want;
	}
	cout << ans << '\n';
}