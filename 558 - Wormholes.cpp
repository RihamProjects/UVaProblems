#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007
#define ll long long
#define ld long double
const int N = 1003;
vector<pair<int, int>>adj[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int C;
    scanf("%d", &C);
    while(C--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i=0;i<m;i++){
            int f, t, c;
            scanf("%d%d%d", &f, &t, &c);
            adj[f].push_back({t, c});
        }
        vector<int>dist(n+1, oo); dist[0] = 0;
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<adj[j].size();k++){
                    pair<int, int> v = adj[j][k];
                    dist[v.first] = min(dist[v.first], dist[j] + v.second);
                }
        bool HasNegativeCycle = 0;
        for(int j=0;j<n;j++)
            for(int k=0;k<adj[j].size();k++){
                pair<int, int> v = adj[j][k];
                if(dist[v.first] > dist[j] + v.second)
                    HasNegativeCycle = 1;
            }
        printf("%s\n", HasNegativeCycle? "possible" : "not possible");
        for(int i=0;i<n;i++) adj[i].clear();
    }
    return 0;
}
