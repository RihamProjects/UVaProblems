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
int N, Max = -oo;
const int MAX = 10002;
int arr[MAX];
/** ----------------------------Functions----------------------------- **/
/**********************************************************************************/
int main() {
//	freopen("In.txt", "r", stdin);
//	freopen("Out.txt", "w", stdout);
	scanf("%d", &N);
	while(N){
		Set(arr, 0);
		for(int i = 0; i < N; i++){
			int r;
			scanf("%d", &r);
			arr[i + 1] = arr[i] + r;
		}
		for(int i=0; i<=N; i++)
			for(int j=i; j<=N; j++){
				int cur = arr[j] - arr[i];
				Max = max(Max, cur);
			}
		(Max)? printf("The maximum winning streak is %d.\n", Max) : puts("Losing streak.");
		Max = -oo;
		scanf("%d", &N);
	}
	return 0;
}
