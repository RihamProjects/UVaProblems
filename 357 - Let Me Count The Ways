//============================================================================
// Name           : Riham.cpp
// Author         : Remo
// Description   : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
using namespace std;
typedef	long long			ll;
typedef	long double		ld;
#define	Set(v,d)				memset(v, d, sizeof(v))
#define	oo						10000007  //infinity
/** ---------------------------Declarations--------------------------- **/
int n;
const int Max=30002;
int cent[]={1, 5, 10, 25, 50};
ll dp[Max+1][5];
/** ----------------------------Functions----------------------------- **/
ll LetMeCountTheWays(int m, int indx){
	if(m <= 0 || indx == 5)
		return m==0;
	if(dp[m][indx] != -1)
		return dp[m][indx];
	return dp[m][indx] = LetMeCountTheWays(m - cent[indx], indx)
					+ LetMeCountTheWays(m ,indx + 1);
}

/***********************************************************/
int main() {
	//freopen("Out.txt", "w", stdout);
	Set(dp, -1);
	dp[0][0]=1;
	LetMeCountTheWays(Max, 0);
	while( scanf("%d", &n) == 1 ){
		(dp[n][0] == 1) ? printf("There is only 1 way to produce %d cents change.\n", n) : printf("There are %lld ways to produce %d cents change.\n", dp[n][0], n);

	}

	return 0;
}

