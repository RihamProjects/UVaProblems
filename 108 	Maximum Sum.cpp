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
const int MAX = 102;
int N, Max = -oo;
/** ----------------------------Functions----------------------------- **/

/**********************************************************************************/
int main() {
//	freopen("In.txt", "r", stdin);
//	freopen("Out.txt", "w", stdout);
	while(scanf("%d", &N) == 1){
		int arr[MAX][MAX];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++){
				int r;
				scanf("%d", &r);
				arr[i + 1][j + 1] = r;
			}
		for(int i = 0; i <= N; i++){
			for(int j = 1; j <= N; j++){
				arr[i][j] += arr[i][j - 1];
			}
		}
		for(int i = 0; i <= N; i++){
				for(int j = 1; j <= N; j++){
					arr[j][i] += arr[j - 1][i];
				}
			}

		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				for(int k=1; k<=i; k++)
					for(int q=1; q<=j; q++){
						int Cur = arr[i][j];
						Cur -= arr[i - k][j];
						Cur -= arr[i][j - q];
						Cur +=arr[i - k][j - q];
						Max = max(Cur, Max);
					}
		printf("%d\n", Max);
		Max = -oo;
	}

	return 0;
}
