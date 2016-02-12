//============================================================================
// Name         : Riham.cpp
// Author       : Remo
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef	long long			ll;
typedef	long double		ld;
#define	For(i,a,b)			for(int i=a;i<=b;i++)
#define	Set(v,d)			memset(v, d, sizeof(v))
#define	oo					501  ///infinity
/** ---------------------------Declarations--------------------------- **/
const int MAX=101;
int T, m, x, SUM=0;
int dp[MAX*oo][MAX], coin[oo];
/** ----------------------------Functions----------------------------- **/
int Dividing_Coin(int sum, int indx){
    if(indx == m){
        return abs(SUM-2*sum);
    }
    if(dp[sum][indx] != oo)
        return dp[sum][indx];
    return dp[sum][indx]=min(Dividing_Coin(sum, indx+1),
                      Dividing_Coin(sum+coin[indx], indx+1));
}

ll Ipow(int base, int exp)
	{ll result = 1;
	while(exp)
	{if(exp & 1)result*=base;
		exp>>=1;base*=base;}
return result;}
//********************************************************//
int main() {
	//freopen("Output.txt", "w", stdout);
	   scanf("%d", &T);
	   while(T--){
	        scanf("%d", &m);
	        for(int i=0; i<m; i++){
	            int r;
	            scanf("%d", &r);
	            coin[i]=r;
	            SUM+=coin[i];
	        }
	        for(int i=0; i<SUM+5; i++)
	            for(int j=0; j<m+2; j++)
	                dp[i][j]=oo;
	        cout<<Dividing_Coin(0, 0)<<endl;
	        SUM=0;
	    }
	return 0;
}

