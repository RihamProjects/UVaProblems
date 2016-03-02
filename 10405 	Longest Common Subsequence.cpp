#include <bits/stdc++.h>
using namespace std;

typedef	long long	ll;
typedef	long double	ld;
#define	Set(v,d)											memset(v, d, sizeof(v))
#define	oo														100000000   //infinity
#define	F														first
#define	S														second
#define	pb														push_back
#define	sz(x) 												(int)(x.size())
#define	all(x)													(x.begin()),(x.end())
#define	rall(x)												(x.rbegin()),(x.rend())

const int MAX = 1003;
int dp[MAX][MAX]; string s1, s2;

int Solve(int i, int j){
	if(i < 0 || j < 0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans1 = 0, ans2 = 0, ans0 = 0;
	if(s1[i] == s2[j])
		return dp[i][j] = Solve(i - 1, j - 1) + 1;
	ans0 = Solve(i - 1, j - 1);
	ans1 = Solve(i - 1, j);
	ans2 = Solve(i, j - 1);
	return dp[i][j] = max(ans1, max(ans2, ans0));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	cin.ignore();
	while(getline(cin, s1)){
		getline(cin, s2);
		if(s1 == "" || s2 == ""){ puts("0"); continue; }
		Set(dp, -1);
		int ans = Solve(sz(s1) - 1, sz(s2) - 1);
		printf("%d\n", ans);
	}
	return 0;
}
