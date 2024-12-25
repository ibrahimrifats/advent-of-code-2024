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
	map<string, set<string>> adj;
	set<string> st;
	while (getline(cin, line)) {
		string a = line.substr(0, 2);		
		string b = line.substr(3, 2);		
		adj[a].insert(b);
		adj[b].insert(a);
		st.insert(a);
		st.insert(b);
	}
	auto has = [&](string x) -> bool {
		return x[0] == 't';
	};
	set<string> groups;
	for (string a : st) {
		for (string b : st) {
			if (!adj[a].count(b) || !adj[b].count(a)) continue;
			for (string c : adj[a]) {
				if (adj[b].count(c) && (has(a) || has(b) || has(c))) {
					groups.insert(a + ',' + b + ',' + c);
				}
			}
		}
	}
	ans = groups.size();
	debug(ans);
	cout << ans/6 << '\n';
}