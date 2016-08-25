#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define oo (int)1e9
const int N = 1001, M = 30;
int dp[N][M], d[M], q[M], w, m;
int solve(int t, int i) {
	if (i == m)
		return 0;
	if (dp[t][i] != -1)
		return dp[t][i];
	int ans1 = -oo, ans2 = -oo;
	if (t - 3 * w * d[i] >= 0)
		ans1 = solve(t - 3 * w * d[i], i + 1) + q[i];
	ans2 = solve(t, i + 1);
	return dp[t][i] = max(ans1, ans2);
}
vector<pair<int, int>> answer;
void FindPath(int t, int i) {
	if (i == m)
		return;
	int ans1 = -oo, ans2 = -oo;
	if (t - 3 * w * d[i] >= 0) {
		ans1 = solve(t - 3 * w * d[i], i + 1) + q[i];
	}
	ans2 = solve(t, i + 1);
	if (ans1 >= ans2) {
		answer.push_back( { d[i], q[i] });
		FindPath(t - 3 * w * d[i], i + 1);
	} else
		FindPath(t, i + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
	int t;bool once=1;
	while (scanf("%d%d", &t, &w) == 2) {
		if(!once)
			printf("\n");
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d", d + i, q + i);
		memset(dp, -1, sizeof dp);
		int ans = solve(t, 0);
		cout << ans << endl;
		FindPath(t, 0);
		cout << answer.size() << endl;
		for (int i = 0; i < (int) answer.size(); i++)
			cout << answer[i].first << " " << answer[i].second << endl;
		answer.clear();
		once = 0;
	}
	return 0;
}
