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
	vector<ll> reg;
	vector<ll> cmd;
	while (getline(cin, line)) {
		istringstream iss(line);
		if (line == "") continue;
		string s;
		ll val;
		if (line[0] == 'R') {
			iss >> s >> s >> val;
			reg.push_back(val);
		}
		else {
			iss >> s;
			char c;
			while (iss >> val) {
				cmd.push_back(val);
				iss >> c;
			}
		}
	}
	auto get = [&](int r) -> ll {
		if (r <= 3) return r;
		else return reg[r - 4];
	};
	auto run = [&](ll ia) -> vector<ll> {
		reg[0] = ia;
		vector<ll> ans;
		int pc = 0;
		while (pc >= 0 && pc < (int)cmd.size()) {
			int op = cmd[pc];
			int r = cmd[pc+1];
			if (op == 0) reg[0] = reg[0] / (1LL << get(r));
			else if (op == 1) reg[1] = reg[1] ^ r;
			else if (op == 2) reg[1] = get(r) % 8;
			else if (op == 3) {
				if (reg[0] != 0) pc = r - 2;
			}
			else if (op == 4) reg[1] = reg[1] ^ reg[2];
			else if (op == 5) ans.push_back(get(r) % 8);
			else if (op == 6) reg[1] = reg[0] / (1LL << get(r));
			else if (op == 7) reg[2] = reg[0] / (1LL << get(r));
			pc += 2;
		}
		return ans;
	};
	auto ans = run(reg[0]);
	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << (i == (int)ans.size() - 1 ? '\n' : ',');
	}
}