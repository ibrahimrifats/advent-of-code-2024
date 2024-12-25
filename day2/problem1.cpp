#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_safe(vector<int> &v) {
    vector<int> f = v, r = v;
    sort(f.begin(), f.end());
    sort(r.begin(), r.end(), greater<int>());

    if (v != f && v != r) return false;

    for (int i = 1; i < v.size(); ++i) {
        if (abs(v[i] - v[i - 1]) <= 3 && abs(v[i] - v[i - 1]) > 0) continue;
        return false;
    }
    return true;
}

int main() {
    ifstream file("input1.txt");
    string line;
    ll ans = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> v;
        int x;

        while (iss >> x) v.push_back(x);

        if (is_safe(v)) {
            ans++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
