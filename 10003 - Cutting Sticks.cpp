#include <bits/stdc++.h>
using namespace std;

typedef    unsigned long long                 ull;
typedef    long long                          ll;
typedef    long double                        ld;
#define    Set(v,d)                           memset(v, d, sizeof(v))
#define    oo                                 10000007   //infinity
#define    F                                  first
#define    S                                  second
#define    pb                                 push_back
#define    sz(x)                              (int)(x.size())
#define    all(x)                             (x.begin()), (x.end())
#define    rall(x)                            (x.rbegin()), (x.rend())
typedef    vector<int>                        vi;
typedef    pair<int, int>                     ii;

const int N = 1005;
int dp[N][N], x[N];

int Cost(int i, int j){
    if(i+1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = oo;
    for(int k=i+1;k<=j-1;k++)
        ans = min(ans, Cost(i, k) + Cost(k, j) + abs(x[j] - x[i]) );
    return dp[i][j] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int l;
    while(scanf("%d", &l) == 1, l){
        int n;

        Set(dp, -1);

        scanf("%d", &n);
        x[0] = 0, x[n+1] = l;
        for(int i=1;i<n+1;i++)
            scanf("%d", x+i);
        int sol = Cost(0, n+1);
        printf("The minimum cutting is %d.\n", sol);
    }
    return 0;
}
