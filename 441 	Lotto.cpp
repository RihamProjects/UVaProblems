//============================================================================
// Name           : Riham.cpp
// Author         : Remo
// Description   : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef	long long	ll;
typedef	long double	ld;
#define	Set(v,d)	memset(v, d, sizeof(v))
#define	oo		1000000007   //infinity
#define	F		first
#define	S		second
#define	pb		push_back
#define	sz(x) 	(int)(x.size())
#define	all(x)		(x.begin()),(x.end())
#define	rall(x)		(x.rbegin()),(x.rend())
#define	pi			3.1415926536

const int MAX = 15;
int n, arr[MAX];

void Lotto(string s, int sum){
	if(sz(s) == n){
		if(sum == 6){
			vector<int>ans;
			for(int i=0;i<sz(s);i++)
				if(s[i] == '1') ans.pb(arr[i]);
			for(int i=0;i<sz(ans) - 1;i++)
				printf("%d ", ans[i]);
			printf("%d", ans[sz(ans)-1]);
			puts("");
		}
		return;
	}
	Lotto(s+'1', sum+1);
	Lotto(s+'0', sum);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	while(n){
		for(int i=0;i<n;i++) scanf("%d", &arr[i]);
		Lotto("", 0);
		scanf("%d", &n);
		if(n)
			puts("");
	}
	return 0;
}
