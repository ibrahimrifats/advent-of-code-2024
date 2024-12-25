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
	vector<ll> vec;
	while (getline(cin, line)) {
		istringstream iss(line);
		ll x;
		while (iss >> x) vec.push_back(x);
	}
	for (int it = 0; it < 25; ++it) {
		vector<ll> nxt;
		for (ll x : vec) {
			if (x == 0) nxt.push_back(1);
			else if (to_string(x).size() % 2 == 0) {
				string s = to_string(x);
				int n = s.size();
				nxt.push_back(stoll(s.substr(0, n/2)));
				nxt.push_back(stoll(s.substr(n/2)));
			}
			else {
				nxt.push_back(x * 2024);
			}
		}
		vec = nxt;
	}
	cout << vec.size() << '\n';
}
