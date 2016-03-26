#include <bits/stdc++.h>
using namespace std;

typedef    unsigned long long           ull;
typedef    long long                          ll;
typedef    long double                      ld;
#define    Set(v,d)                           memset(v, d, sizeof(v))
#define    oo                                     10000000000000007   //infinity
#define    F                                      first
#define    S                                      second
#define    pb                                    push_back
#define    sz(x)                                (int)(x.size())
#define    all(x)                               (x.begin()), (x.end())
#define    rall(x)                             (x.rbegin()), (x.rend())
typedef     vector<int>                     vi;

const int MAX = 500005;
vi adjList[MAX]; bool visited[MAX]; int ans, num;
void dfs(int n){
    visited[n] = 1;
    num++;
    for(int i=0;i<sz(adjList[n]);i++){
        if(!visited[adjList[n][i]]){
            dfs(adjList[n][i]);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int TC, n, m;
    scanf("%d", &TC);
    while(TC--){
        for(int i=0;i<MAX;i++)
            adjList[i].clear();
        ans = 0;
        Set(visited, 0);
        scanf("%d%d", &n, &m);
        for(int i=0;i<m;i++){
            int f, t;
            scanf("%d%d", &f, &t);
            adjList[f].pb(t);
            adjList[t].pb(f);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                num = 0;
                dfs(i);
                ans = max(num, ans);
            }
        }
        cout<<(ans==1? 0 : ans)<<endl;
    }
    return 0;
}

