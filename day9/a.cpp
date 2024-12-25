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
	getline(cin, line);
	ll ans = 0;
	vector<int> data;
	for (int i = 0; i < (int)line.size(); ++i) {
		int c = -1;
		if (i % 2 == 0) c = i / 2;
		for (int j = 0; j < line[i] - '0'; ++j) {
			data.push_back(c);
		}
	}
	auto fix = [&]() {
		while (data.back() == -1) data.pop_back();
	};
	fix();
	for (int i = 0; i < (int)data.size(); ++i) {
		if (data[i] == -1) {
			data[i] = data.back();
			data.pop_back();
			fix();
		}
	}
	for (int i = 0; i < (int)data.size(); ++i) {
		ans += data[i] * i;
	}

	cout << ans << '\n';
}