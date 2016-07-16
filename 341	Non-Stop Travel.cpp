#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007
#define ll long long
#define ld long double
const int N = 302;
vector<pair<int, int>>adj[N];
int n, m, t, c, cnt = 0;
vector<int>ans;
int Dijkestra(int s, int e){
    priority_queue<pair<int, int>>pq;
    vector<int>dist(n+2, oo), par(n+2, -1);
    dist[s] = 0;
    pq.push({0, s});
    par[s] = -1;
    while(!pq.empty()){
        int node = pq.top().second, d = pq.top().first;
        pq.pop();
        if(d > dist[node]) continue;
        for(int i=0;i<adj[node].size();i++){
            int ch = adj[node][i].first, cost = adj[node][i].second;
            if(dist[node] + cost < dist[ch]){
                dist[ch] = dist[node] + cost;
                pq.push({dist[ch], ch});
                par[ch] = node;
            }
        }
    }
    int Dist = dist[e];
    while(e != -1){
        ans.push_back(e);
        e = par[e];
    }
    return Dist;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(scanf("%d", &n), n){
        for(int i=1;i<=n;i++){
            cin >> m;
            while(m--){
                scanf("%d%d", &t, &c);
                adj[i].push_back({t, c});
            }
        }
        int s, e;
        scanf("%d%d", &s, &e);
        int dist = Dijkestra(s, e);
        printf("Case %d: Path =", ++cnt);
        while(!ans.empty()){
            printf(" %d", ans.back());
            ans.pop_back();
        }
        printf("; %d second delay\n", dist);
        for(int i=0;i<=n;i++)adj[i].clear();
    }
	return 0;
}
