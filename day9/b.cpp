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
	struct Item {
		int id, len;
	};
	vector<Item> data;
	vector<vector<int>> info(10);
	for (int i = 0; i < (int)line.size(); ++i) {
		int c = -1;
		if (i % 2 == 0) c = i / 2;
		data.push_back({c, line[i] - '0'});
		if (c != -1) info[line[i] - '0'].push_back(i);
	}
	vector<Item> ans;
	for (int i = 0; i < (int)data.size(); ++i) {
		if (data[i].id != -1) {
			ans.push_back(data[i]);
			continue;
		}
		while (true) {
			int mx = -1, arg;
			for (int j = 0; j <= data[i].len; ++j) {
				if (!info[j].empty() && info[j].back() >= i) {
					if (info[j].back() > mx) {
						mx = max(mx, info[j].back());
						arg = j;
					}
				}
			}
			if (mx == -1) break;
			info[arg].pop_back();
			ans.push_back(data[mx]);
			data[mx].id = -1;
			data[i].len -= arg;
		}
		ans.push_back(data[i]);
	}
	vector<int> vec;
	for (auto [id, len] : ans) {
		for (int j = 0; j < len; ++j) vec.push_back(id);
	}
	ll tot = 0;
	for (int i = 0; i < (int)vec.size(); ++i) {
		if (vec[i] != -1) tot += vec[i] * i;
	}
	cout << tot << '\n';
}