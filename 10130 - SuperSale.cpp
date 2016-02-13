//============================================================================
// Name         : Riham.cpp
// Author       : Remo
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef	long long			ll;
typedef	long double		ld;
#define	Set(v,d)				memset(v, d, sizeof(v))
#define	oo						10000007  //infinity
/** ---------------------------Declarations--------------------------- **/
const int maxW=33, maxN=1003;
int T, N, G, weight[maxN], price[maxN];
int dp[maxW][maxN];
/** ----------------------------Functions----------------------------- **/
int SuperSale(int w, int indx){
	if(indx == N){
		return 0;
	}
	if(dp[w][indx] != -1)
		return dp[w][indx];
	int ans1=0,ans2=0;
	if(w-weight[indx]>=0 && indx<N)
		ans1=SuperSale(w-weight[indx], indx+1)+price[indx];
	if(indx<N)
		ans2=SuperSale(w, indx+1);
	return dp[w][indx]=max(ans1, ans2);

}

ll Ipow(int base, int exp)
	{ll result = 1;
	while(exp)
	{if(exp & 1)result*=base;
		exp>>=1;base*=base;}
return result;}
//********************************************************//
int main() {
//	freopen("Output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int p, w;
			scanf("%d %d", &p, &w);
			price[i]=p, weight[i]=w;
		}
		Set(dp,-1);
		int sol=0;
		scanf("%d", &G);
		for(int i=0; i<G; i++){
			int w;
			scanf("%d", &w);
			sol+=SuperSale(w, 0);
		}
		printf("%d\n", sol);
	}

	return 0;
}
