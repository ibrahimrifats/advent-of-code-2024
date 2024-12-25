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
	getline(cin, line);
	istringstream iss(line);
	string word;
	set<string> dict;
	while (iss >> word) {
		if (word.back() == ',') word.pop_back();
		dict.insert(word);
	}
	while (getline(cin, line)) {
		if (line == "") continue;
		int n = line.size();
		vector<ll> dp(n+1, 0); dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j >= 0; --j) {
				dp[i] *= dp[j] * dict.count(line.substr(j, i-j));
			}
		}
		ans += dp[n];
	}
	cout << ans << '\n';
}