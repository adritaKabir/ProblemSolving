#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c, d; cin >> a >> b >> c >> d;
	if (max(a, c) <= min(b, d)) cout << "Yes\n";
	else cout << "No\n";
    return 0;
}