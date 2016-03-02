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
int T, dp[Max][Max], counter = 0; string s;

int StringToPalindrome(int i, int j){
	if(j <= i) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i] == s[j]) return dp[i][j] = StringToPalindrome(i + 1, j - 1);
	return dp[i][j] = min( StringToPalindrome(i + 1, j - 1) + 1, min( StringToPalindrome(i, j - 1) + 1, StringToPalindrome(i + 1, j) + 1) );
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	cin.ignore();
	while(T--){
		Set(dp, -1);

		getline(cin, s);
		if(s == ""){ puts("0"); continue; }
		int ans = StringToPalindrome(0, sz(s) - 1);
		printf("Case %d: %d\n", ++counter, ans);
	}

	return 0;
}
