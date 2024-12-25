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
		for (int i = 0; i < 2000; ++i) {
			x = (x * 64) ^ x; 
			x %= mod;
			x = (x / 32) ^ x;
			x %= mod;
			x = (x * 2048) ^ x;
			x %= mod;
		}
		ans += x;
	}
	cout << ans << '\n';
}