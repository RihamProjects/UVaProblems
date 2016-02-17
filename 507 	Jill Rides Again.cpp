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
#define	oo						1000000007   //infinity
/** ---------------------------Declarations--------------------------- **/
ll b, s, R, sum = 0, ans = 0, start = -1, End = -1, tem = 0;
/** ----------------------------Functions----------------------------- **/

/**********************************************************************************/
int main() {
//	freopen("In.txt", "r", stdin);
//	freopen("Out.txt", "w", stdout);
	scanf("%lld", &b);
	for(ll r=0; r<b; r++){
		scanf("%lld", &s);
		for(int d=1; d<s; d++){
			scanf("%lld", &R);
			sum += R;
			if(ans < sum){
				ans = sum;
				End = d + 1;
				start = tem;
			}
			else if( ans ==  sum && d + 1 - tem > End - start ){
				ans = sum;
				End = d + 1;
				start = tem;
			}
			if(sum < 0){
				sum = 0;
				tem = d;
			}
		}
		if(End > start) printf("The nicest part of route %lld is between stops %lld and %lld\n", r + 1, start + 1, End);
		else printf("Route %lld has no nice parts\n", r + 1);
		sum = 0, ans = 0, start = -1, End = -1, tem = 0;
	}

	return 0;
}
