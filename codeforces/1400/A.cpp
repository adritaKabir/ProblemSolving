#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < 2 * n; i += 2) cout << s[i];
		cout << '\n';
	}
    return 0;
}