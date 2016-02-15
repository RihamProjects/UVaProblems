//============================================================================
// Name           : Riham.cpp
// Author         : Remo
// Description   : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
using namespace std;
typedef	long long			ll;
typedef	long double		ld;
#define	Set(v,d)			memset(v, d, sizeof(v))
#define	oo						10000007  //infinity
/** ---------------------------Declarations--------------------------- **/
double n;
const int Max=30199;
int money[]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
ll dp[Max+5][11];
/** ----------------------------Functions----------------------------- **/
ll Dollars(int m, int indx){
	if(indx == 11 || m <= 0)
		return (m == 0);
	if(dp[m][indx] != -1)
		return dp[m][indx];
	return dp[m][indx] = Dollars(m - money[indx], indx) + Dollars(m, indx + 1);
}

/***********************************************************/
int main() {
//	freopen("In.txt", "r", stdin);
//	freopen("Out.txt", "w", stdout);
	Set(dp, -1);
	while( scanf("%lf", &n) == 1 && n ){
		printf("%6.2lf%17lld\n", n, Dollars( round(n * 100), 0));
	}
	return 0;
}

