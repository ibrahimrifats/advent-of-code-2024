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
	while (getline(cin, line)) {
		istringstream issA(line);
		getline(cin, line);
		istringstream issB(line);
		getline(cin, line);
		istringstream issP(line);
		getline(cin, line);
		string s; char c;
		ll ax, ay;
		issA >> s >> s >> c >> c >> ax >> c >> c >> c >> ay;
		ll bx, by;
		issB >> s >> s >> c >> c >> bx >> c >> c >> c >> by;
		ll px, py;
		issP >> s >> c >> c >> px >> c >> c >> c >> py;

		ll cur = 1e9;
		for (int i = 0; i <= 100; ++i) {
			for (int j = 0; j <= 100; ++j) {
				if (ax * i + bx * j == px && ay * i + by * j == py) {
					cur = min(cur, 3LL * i + j);
				}
			}
		}
		if (cur != 1e9) ans += cur;
	}
	cout << ans << '\n';
}