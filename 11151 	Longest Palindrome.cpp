#include <bits/stdc++.h>
using namespace std;

typedef	long long	ll;
typedef	long double	ld;
#define	Set(v,d)	memset(v, d, sizeof(v))
#define	oo		100000003   //infinity
#define	F		first
#define	S		second
#define	pb		push_back
#define	sz(x) 	(int)(x.size())
#define	all(x)		(x.begin()),(x.end())
#define	rall(x)		(x.rbegin()),(x.rend())

const int Max = 1003;
int T, dp[Max][Max]; string s;

int LongestPalindrome(int i, int j){
	if(j < i) return 0;
	if(j == i) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i] == s[j])
		dp[i][j] = LongestPalindrome(i + 1, j - 1) + 2;
	return dp[i][j] = max( max( LongestPalindrome(i + 1, j), LongestPalindrome(i, j - 1) ), dp[i][j] );
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	 cin.ignore();
	while(T--){
		getline(cin, s);
		if (s == ""){
			puts("0");
			continue;
		}
		Set(dp, -1);
		int ans = LongestPalindrome(0, sz(s) - 1);
		printf("%d\n", ans);
	}

	return 0;
}
