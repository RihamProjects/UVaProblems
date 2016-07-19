#include <bits/stdc++.h>
#define oo 1000000007
#define ll long long
using namespace std;
const int N = 23;
int cnt=0, cost[N][N];
int n, m;
int FloydWarshall(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(scanf("%d%d", &n, &m) == 2 && !(!n && !m)){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) {
                cost[i][j] = oo;
                if(i == j) cost[i][i]=0;
        }
        char s[21][11];
        for(int i=0;i<n;scanf("%s", s+i++));
        for(int i=0;i<m;i++){
            int f, t, c;
            scanf("%d%d%d", &f, &t, &c);
            cost[f][t] = min(cost[f][t], c);
            cost[t][f] = cost[f][t];
        }
        FloydWarshall();
        int ans = 0, ANS = 1, Min = oo;
        for(int i=1;i<=n;i++){
            ans = 0;
            for(int j=1;j<=n;j++)
                ans += cost[j][i];
            if(Min > ans) ANS = i, Min = ans;
        }
        printf("Case #%d : %s\n", ++cnt, s[ANS-1]);
    }
	return 0;
}
