#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n <= 3) cout << -1 << '\n';
		else {
			for (int i = n - (1 - n % 2); i >= 1; i -= 2) cout << i << ' ';
			cout << 4 << ' ' << 2 << ' ';
			for (int i = 6; i <= n; i += 2) cout << i << ' ';
			cout << '\n';
		}
	}
    return 0;
}