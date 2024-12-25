#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	bool on = 1;
	while (getline(cin, line)) {
		int n = line.size();
		for (int i = 0; i < n; ++i) {
			if (line.substr(i, 4) == "do()") on = 1;
			else if (line.substr(i, 7) == "don't()") on = 0;
			if (line.substr(i, 4) == "mul(") {
				istringstream iss(line.substr(i+4, 12));
				char c;
				int a, b;
				iss >> a >> c >> b;
				char d;
				iss >> d;
				if (d != ')' || c != ',' || !on) continue;
				ans += a * b;
			}
		}		
	}
	cout << ans << '\n';
}