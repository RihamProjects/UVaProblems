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
int N, T, m;
string s;
/** ----------------------------Functions----------------------------- **/
/**********************************************************************************/
int main() {
//	freopen("In.txt", "r", stdin);
//	freopen("Out.txt", "w", stdout);
	scanf("%d\n", &T);
	while(T--){
		vector<string>arr;
		int Max = -oo, cnt = 0;
		cin>>s;
		arr.push_back(s);
		N = m = s.size();
		while(--m){
			cin>>s;
			arr.push_back(s);
		}
		bool exit = 1;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int k=i; k<N; k++)
					for(int q=j; q<N; q++){
						for(int a=i; a<=k; a++){
							for(int b=j; b<=q; b++){
								if(arr[a][b] == '0'){
									exit = 0;
									cnt = 0;
									break;
								}
								cnt++;
							}
							if(!exit){
								exit = 1;
								break;
							}
						}
						Max = max(Max, cnt);
						cnt = 0;
					}
		printf("%d\n", Max);
		if(T)puts("");
	}
	return 0;
}
