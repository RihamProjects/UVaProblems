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
const int maxN=1122, maxK=15;
int N, k;
bitset<maxN+5>prime;
vector<int>primes;
ll dp[maxN+5][maxN+5][maxK+5];
/** ----------------------------Functions----------------------------- **/
void Sieve(){
	prime.set();
	prime[0]=prime[1]=0;
	for(int i=2; i<maxN+5; i++)
		if(prime[i]){
			for(int j=i*i; j<maxN+5; j+=i)
				prime[j]=0;
			primes.push_back(i);
		}
}

ll SumofDifferentPrimes(int n, int indx, int cnt){
	if(cnt <= 0 || n <= 0){
		return ((n == 0) && (cnt == 0));
	}
	if(dp[n][indx][cnt] != -1)
		return dp[n][indx][cnt];
	ll ans1=0, ans2=0;
	if(indx<(int)primes.size()){
		ans1=SumofDifferentPrimes(n-primes[indx], indx+1, cnt-1);
		ans2=SumofDifferentPrimes(n, indx+1, cnt);
	}
	return dp[n][indx][cnt]=ans1+ans2;
}

int main() {
	//freopen("i.txt","r",stdin);
	Sieve();
	Set(dp, -1);
	dp[0][0][0]=0;
	for(int idx=primes.size()-1;idx>=0;--idx)
	for(int n=0;n<maxN;++n)
	for(int cnt=0;cnt<maxK;++cnt)
		SumofDifferentPrimes(n, idx, cnt);


	int n,k;
	while(scanf("%d %d",&n,&k),(n||k)){
		printf("%lld\n",dp[n][0][k]);
	}

	return 0;
}
