#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define oo (int)1e9
const int N = 7490, M = 30;
int coins[] = { 1, 5, 10, 25, 50 };
int dp[N+2][6];
int solve(int money, int i) {
	if (i == 5)
		return !money;
	if (dp[money][i] != -1)
		return dp[money][i];
	int ans = 0;
	if (money - coins[i] >= 0)
		ans = solve(money - coins[i], i);
	return dp[money][i] = ans + solve(money, i + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
	memset(dp, -1, sizeof(dp));
	solve(N, 0);
	int money;
	while(scanf("%d", &money) == 1) {
		printf("%d\n", dp[money][0]);
	}
	return 0;
}
