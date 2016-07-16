#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007
#define ll long long
#define ld long double
const int N = 102;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int V, m, Cost[N];
    vector<int>adj[N];
 while(scanf("%d", &V) == 1){
    if(V == -1) break;
    for(int i=1;i<=V;i++){
        scanf("%d%d", Cost+i, &m);
        while(m--){
            int t;scanf("%d", &t);
            adj[i].push_back(t);
        }
    }
    vector<int>dist(V+5, -oo);
    dist[1] = 100;
    for(int j=1;j<100000;j++)
        for(int u=1;u<=V;u++)
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                if(dist[u] + Cost[v] > 0)
                    dist[v] = max(dist[v], dist[u] + Cost[v]);
            }
    if(dist[V] == -oo) printf("hopeless\n");
    else printf("winnable\n");
    for(int i=0;i<=V;i++)adj[i].clear();
}
	return 0;
}
