#include <bits/stdc++.h>
using namespace std;

typedef    unsigned long long           ull;
typedef    long long                          ll;
typedef    long double                      ld;
#define    Set(v,d)                           memset(v, d, sizeof(v))
#define    oo                                   100007   //infinity
#define    F                                    first
#define    S                                    second
#define    pb                                  push_back
#define    sz(x)                              (int)(x.size())
#define    all(x)                              (x.begin()), (x.end())
#define    rall(x)                             (x.rbegin()), (x.rend())
typedef    vector<int>                      vi;
typedef    pair<int, int>                    ii;

const int N = 1005;
int dp[N][N], x[N][3], n;

int solve(int t, int indx){
    if(t < 0 || indx == n){
        if(t>=0) return 0;
        return -oo;
    }
    if(dp[t][indx] != -1) return dp[t][indx];
    int ans1 = 0, ans2 = 0;
    ans1 = solve(t-x[indx][0], indx+1)+x[indx][1];
    ans2 = solve(t, indx+1);
    return dp[t][indx] = max(ans1, ans2);
}
int r[N], g[N];
vi sol;
void TraceOperation(int t, int indx){
    if(t < 0 || indx == n){
        return;
    }

    int ans1 = 0, ans2 = 0;
    ans1 = solve(t-x[indx][0], indx+1)+x[indx][1];
    ans2 = solve(t, indx+1);

    int optimal = solve(t, indx);
    if(optimal == ans1){
        sol.pb(indx);
        TraceOperation(t-x[indx][0], indx+1);
    }
    else{
        TraceOperation(t, indx+1);
    }
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t, w, bl = 0;
    while(cin>>t>>w){
        if (bl)
            putchar('\n');
        bl = 1;
        Set(dp, -1);
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d%d", r+i, g+i);
            x[i][0] = 3*w*r[i];
            x[i][1] = g[i];
        }
        printf("%d\n", solve(t, 0));
        TraceOperation(t, 0);
        int sz = sz(sol);
        printf("%d\n", sz);
        for(int i=0;i<sz;i++){
            printf("%d %d\n", r[sol[i]], g[sol[i]]);
        }
        sol.clear();
    }
    return 0;
}
