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
		const ll B = 10000000000000;
		px += B;
		py += B;
		debug(ax, ay, bx, by, px, py);

		ll det = ax * by - bx * ay;
		ll i11 = by;
		ll i12 = -bx;
		ll i21 = -ay;
		ll i22 = ax;
		ll i = i11 * px + i12 * py;
		ll j = i21 * px + i22 * py;
		if (i % det) continue;
		if (j % det) continue;
		i /= det, j /= det;
		if (i < 0 || j < 0) continue;
		debug(i, j, det);
		ans += 3 * i + j;
	}
	cout << ans << '\n';
}