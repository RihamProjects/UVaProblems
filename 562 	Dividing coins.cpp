#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 50001, M = 101;
int dp[N][M], n, m, sum, coins[M];
int solve(int ans, int i) {
	if (i == m)
		return abs(sum - 2 * ans);
	if (dp[ans][i] != -1)
		return dp[ans][i];
	return dp[ans][i] = min(solve(ans + coins[i], i + 1), solve(ans, i + 1));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
	scanf("%d", &n);
	while (n--) {
		memset(dp, -1, sizeof dp);
		sum = 0;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d", coins + i), sum += coins[i];
		cout << solve(0, 0) << endl;
	}
	return 0;
}
