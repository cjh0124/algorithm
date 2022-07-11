#include <bits/stdc++.h>
using namespace std;
int n, m, op, a, b;
int arr[100001], tree[400004];

void upd(int node, int s, int e, int idx, int val) {
	if (idx<s || idx>e) return;
	if (s == e) {
		tree[node] = val;
		return;
	}
	int m = (s + e) / 2;
	upd(2 * node, s, m, idx, val);
	upd(2 * node + 1, m + 1, e, idx, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int s, int e, int qs, int qe) {
	if (qs > e || qe < s) return 1e9;
	if (qs <= s && e <= qe) return tree[node];
	int m = (s + e) / 2;
	return min(query(2 * node, s, m, qs, qe), query(2 * node + 1, m + 1, e, qs, qe));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		upd(1, 1, n, i, arr[i]);
	}
	cin >> m;
	while (m--) {
		cin >> op >> a >> b;
		if (op & 1) {
			upd(1, 1, n, a, b);
		}
		else {
			cout << query(1, 1, n, a, b) << '\n';
		}
	}
}